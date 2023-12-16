/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_nums.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:48:58 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/15 16:25:58 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str	*ft_nums(t_spec spec, va_list args)
{
	t_str	*conv;
	size_t	num;

	if (spec.l == 'l')
		num = va_arg(args, unsigned long);
	else if (spec.l == 'z')
		num = va_arg(args, size_t);
	else
		num = va_arg(args, unsigned);
	if (num == 0 && spec.precision < 0 && spec.pad != '0')
		spec.precision = 1;
	if (spec.conv == 'u')
		conv = ft_uint(spec, num);
	else if (spec.conv == 'x')
		conv = ft_hexl(spec, num);
	else if (spec.conv == 'X')
		conv = ft_hexu(spec, num);
	else if (spec.conv == 'o')
		conv = ft_oct(spec, num);
	else
		conv = ft_bin(spec, num);
	return (conv);
}

t_str	*ft_int(t_spec spec, va_list args)
{
	t_str	*conv;
	ssize_t	num;

	if (spec.l == 'l')
		num = va_arg(args, long);
	else if (spec.l == 'z')
		num = va_arg(args, ssize_t);
	else
		num = va_arg(args, int);
	if (num == 0 && spec.precision < 0 && spec.pad != '0')
		spec.precision = 1;
	conv = ft_int2(spec, num);
	return (conv);
}

t_str	*ft_int2(t_spec spec, ssize_t num)
{
	size_t	n;
	t_str	*conv;
	size_t	len;

	if (num < 0)
	{
		n = -num;
		spec.sign = '-';
	}
	else
		n = num;
	if (spec.precision >= 0 && spec.pad == '0')
		spec.pad = 0;
	else if (spec.pad == '0' && spec.width - !!spec.sign > spec.precision)
		spec.precision = spec.width - !!spec.sign;
	spec.alt = 0;
	spec.precision = ft_max(spec.precision, ft_numlen(n, 10));
	len = spec.precision + !!spec.sign;
	spec.width = ft_max(len, spec.width);
	conv = ft_newtstr_pad(spec.width, len, spec.pad);
	if (spec.pad == '-' && conv != NULL)
		ft_nbrbase(conv->s, spec, n, B10);
	else if (conv != NULL)
		ft_nbrbase(conv->s + spec.width - len, spec, n, B10);
	return (conv);
}

t_str	*ft_uint(t_spec spec, size_t n)
{
	t_str	*conv;
	size_t	len;

	if (spec.precision >= 0 && spec.pad == '0')
		spec.pad = 0;
	else if (spec.pad == '0' && spec.width - !!spec.sign > spec.precision)
		spec.precision = spec.width - !!spec.sign;
	spec.alt = 0;
	spec.precision = ft_max(spec.precision, ft_numlen(n, 10));
	len = spec.precision + !!spec.sign;
	spec.width = ft_max(len, spec.width);
	conv = ft_newtstr_pad(spec.width, len, spec.pad);
	if (spec.pad == '-' && conv != NULL)
		ft_nbrbase(conv->s, spec, n, B10);
	else if (conv != NULL)
		ft_nbrbase(conv->s + spec.width - len, spec, n, B10);
	return (conv);
}

t_str	*ft_bin(t_spec spec, size_t n)
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
		spec.alt = 'b';
	spec.precision = ft_max(spec.precision, ft_numlen(n, 2));
	len = spec.precision + !!spec.sign + 2 * !!spec.alt;
	spec.width = ft_max(len, spec.width);
	conv = ft_newtstr_pad(spec.width, len, spec.pad);
	if (spec.pad == '-' && conv != NULL)
		ft_nbrbase(conv->s, spec, n, B2);
	else if (conv != NULL)
		ft_nbrbase(conv->s + spec.width - len, spec, n, B2);
	return (conv);
}
