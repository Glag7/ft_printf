/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_nums_hex.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:04:32 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/15 19:34:57 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str	*ft_hexl(t_spec spec, size_t n)
{
	t_str	*conv;
	size_t	len;

	if (n == 0)
		spec.alt = 0;
	if (spec.precision >= 0 && spec.pad == '0')
		spec.pad = 0;
	else if (spec.pad == '0'
		&& spec.width - !!spec.sign - 2 * !!spec.alt > spec.precision)
		spec.precision = spec.width - !!spec.sign - 2 * !!spec.alt;
	if (spec.alt)
		spec.alt = 'x';
	spec.precision = ft_max(spec.precision, ft_numlen(n, 16));
	len = spec.precision + !!spec.sign + 2 * !!spec.alt;
	spec.width = ft_max(len, spec.width);
	conv = ft_newtstr_pad(spec.width, len, spec.pad);
	if (spec.pad == '-' && conv != NULL)
		ft_nbrbase(conv->s, spec, n, B16_L);
	else if (conv != NULL)
		ft_nbrbase(conv->s + spec.width - len, spec, n, B16_L);
	return (conv);
}

t_str	*ft_hexu(t_spec spec, size_t n)
{
	t_str	*conv;
	size_t	len;

	if (n == 0)
		spec.alt = 0;
	if (spec.precision >= 0 && spec.pad == '0')
		spec.pad = 0;
	else if (spec.pad == '0'
		&& spec.width - !!spec.sign - 2 * !!spec.alt > spec.precision)
		spec.precision = spec.width - !!spec.sign - 2 * !!spec.alt;
	if (spec.alt)
		spec.alt = 'X';
	spec.precision = ft_max(spec.precision, ft_numlen(n, 16));
	len = spec.precision + !!spec.sign + 2 * !!spec.alt;
	spec.width = ft_max(len, spec.width);
	conv = ft_newtstr_pad(spec.width, len, spec.pad);
	if (spec.pad == '-' && conv != NULL)
		ft_nbrbase(conv->s, spec, n, B16_U);
	else if (conv != NULL)
		ft_nbrbase(conv->s + spec.width - len, spec, n, B16_U);
	return (conv);
}

t_str	*ft_oct(t_spec spec, size_t n)
{
	t_str	*conv;
	size_t	len;

	if (n == 0)
		spec.alt = 0;
	if (spec.precision >= 0 && spec.pad == '0')
		spec.pad = 0;
	else if (spec.pad == '0'
		&& spec.width - !!spec.sign - 2 * !!spec.alt > spec.precision)
		spec.precision = spec.width - !!spec.sign - 2 * !!spec.alt;
	if (spec.alt)
		spec.alt = '0';
	spec.precision = ft_max(spec.precision, ft_numlen(n, 8));
	len = spec.precision + !!spec.sign + 2 * !!spec.alt;
	spec.width = ft_max(len, spec.width);
	conv = ft_newtstr_pad(spec.width, len, spec.pad);
	if (spec.pad == '-' && conv != NULL)
		ft_nbrbase(conv->s, spec, n, B8);
	else if (conv != NULL)
		ft_nbrbase(conv->s + spec.width - len, spec, n, B8);
	return (conv);
}
