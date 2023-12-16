/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_charstr_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:09:21 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/15 16:34:39 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_str	*ft_char(t_spec spec, va_list args)
{
	char	c;
	int		size;
	t_str	*conv;
	char	*str;

	c = va_arg(args, int);
	size = ft_max(1, spec.width);
	str = malloc(size * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_bspace(str, size);
	if (!(spec.pad == '-'))
		str[size - 1] = c;
	else
		str[0] = c;
	conv = malloc(sizeof(t_str));
	if (conv == NULL)
	{
		free(str);
		return (NULL);
	}
	conv->len = size;
	conv->s = str;
	return (conv);
}

t_str	*ft_str(t_spec spec, va_list args)
{
	char	*str_arg;
	size_t	size;
	t_str	*conv;
	size_t	len;

	str_arg = va_arg(args, char *);
	if (str_arg == NULL && (spec.precision > 5 || spec.precision < 0))
		str_arg = "(null)";
	else if (str_arg == NULL)
		str_arg = "";
	len = ft_strlen(str_arg);
	if (spec.precision >= 0 && spec.precision < (ssize_t) len)
		len = spec.precision;
	size = ft_max(len, spec.width);
	if (spec.pad != '0')
		conv = ft_newtstr_pad(size, len, spec.pad);
	else
		conv = ft_newtstr_pad(size, len, 0);
	if (conv == NULL)
		return (NULL);
	if (spec.pad == '-')
		ft_memcpy(conv->s, str_arg, len);
	else
		ft_memcpy(conv->s + size - len, str_arg, len);
	return (conv);
}
