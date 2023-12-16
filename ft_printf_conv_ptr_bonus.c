/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_ptr_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:15:43 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/15 16:35:40 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_str	*ft_ptr(t_spec spec, va_list args)
{
	char	*ptr;
	t_str	*conv;
	size_t	len;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
	{
		conv = ft_nil(spec);
		return (conv);
	}
	if (spec.precision >= 0 && spec.pad == '0')
		spec.pad = 0;
	else if (spec.pad == '0' && spec.width - !!spec.sign - 2 > spec.precision)
		spec.precision = spec.width - !!spec.sign - 2;
	spec.alt = 'x';
	spec.precision = ft_max(spec.precision, ft_numlen((size_t) ptr, 16));
	len = spec.precision + 2 + !!spec.sign;
	spec.width = ft_max(len, spec.width);
	conv = ft_newtstr_pad(spec.width, len, spec.pad);
	if (spec.pad == '-' && conv != NULL)
		ft_nbrbase(conv->s, spec, (size_t) ptr, B16_L);
	else if (conv != NULL)
		ft_nbrbase(conv->s + spec.width - len, spec, (size_t) ptr, B16_L);
	return (conv);
}

t_str	*ft_nil(t_spec spec)
{
	size_t	size;
	t_str	*conv;

	size = ft_max(5, spec.width);
	if (spec.pad != '0')
		conv = ft_newtstr_pad(size, 5, spec.pad);
	else
		conv = ft_newtstr_pad(size, 5, 0);
	if (conv == NULL)
		return (NULL);
	if (spec.pad == '-')
		ft_memcpy(conv->s, "(nil)", 5);
	else
		ft_memcpy(conv->s + size - 5, "(nil)", 5);
	conv->len = size;
	return (conv);
}
