/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:50:29 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/15 16:34:28 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_str	*ft_get_conv_tstr(t_spec spec, va_list args)
{
	t_str	*conv;
	char	c;

	c = spec.conv;
	if (ft_in(c, "id") != -1)
		conv = ft_int(spec, args);
	else if (ft_in(c, "ouxXb") != -1)
		conv = ft_nums(spec, args);
	else if (c == 'p')
		conv = ft_ptr(spec, args);
	else if (c == 's')
		conv = ft_str(spec, args);
	else if (c == 'c')
		conv = ft_char(spec, args);
	else if (c == '%')
		conv = ft_percent();
	else
		conv = ft_bad(spec);
	return (conv);
}

t_str	*ft_percent(void)
{
	t_str	*conv;
	char	*str;

	conv = malloc(sizeof(t_str));
	if (conv == NULL)
		return (NULL);
	str = malloc(1 * sizeof(char));
	if (str == NULL)
	{
		free(conv);
		return (NULL);
	}
	*str = '%';
	conv->len = 1;
	conv->s = str;
	return (conv);
}

t_str	*ft_bad(t_spec spec)
{
	char	*str;
	t_str	*conv;

	str = malloc(27);
	if (str == NULL)
		return (NULL);
	conv = malloc(sizeof(t_str));
	if (conv == NULL)
	{
		free(str);
		return (NULL);
	}
	conv->s = str;
	*str = '%';
	str++;
	conv->len = 1;
	conv->len += ft_fill_flags(spec, str);
	conv->len += ft_fill_conv(spec, str + conv->len - 1);
	return (conv);
}

int	ft_fill_flags(t_spec spec, char *str)
{
	int	i;

	i = 0;
	if (spec.alt)
	{
		str[i] = '#';
		i++;
	}
	if (spec.sign)
	{
		str[i] = spec.sign;
		i++;
	}
	if (spec.pad)
	{
		str[i] = spec.pad;
		i++;
	}
	return (i);
}

int	ft_fill_conv(t_spec spec, char *str)
{
	int	i;

	i = 0;
	if (spec.width)
		ft_putnbrbase_str(spec.width, str, B10, &i);
	if (spec.precision >= 0)
	{
		str[i] = '.';
		i++;
		ft_putnbrbase_str(spec.precision, str + i, B10, &i);
	}
	if (spec.conv)
	{
		str[i] = spec.conv;
		i++;
	}
	return (i);
}
