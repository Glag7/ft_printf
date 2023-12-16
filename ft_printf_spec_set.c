/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec_set.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 21:19:07 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/15 19:23:45 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_setflags(const char *s, t_spec *spec)
{
	size_t	i;
	int		tmp;
	char	*flags;

	i = 0;
	flags = "#0- +";
	tmp = ft_in(*s, flags);
	while (tmp != -1)
	{
		if (tmp == 0)
			spec->alt = 1;
		else if (tmp < 3)
		{
			if (spec->pad != '-')
				spec->pad = flags[tmp];
		}
		else if (spec->sign != '+' && tmp >= 3)
			spec->sign = flags[tmp];
		i++;
		tmp = ft_in(s[i], flags);
	}
	return (i);
}

size_t	ft_setwidth(const char *s, t_spec *spec, short *error, va_list args)
{
	size_t	n;
	int		i;
	char	c;

	c = *s;
	if (c == '*')
	{
		spec->width = ft_parsewidth(va_arg(args, int), &(spec->pad));
		return (1);
	}
	if (c < '0' || c > '9')
		return (0);
	n = 0;
	i = 0;
	while (c >= '0' && c <= '9')
	{
		n = n * 10 + c - 48;
		i++;
		c = s[i];
		if (n > 2147483647)
			*error = 1;
	}
	if (!*error)
		spec->width = n;
	return (i);
}

size_t	ft_setpre(const char *s, t_spec *spec, short *error, va_list args)
{
	size_t	n;
	int		i;

	if (*s != '.')
		return (0);
	if (s[1] == '*')
	{
		spec->precision = va_arg(args, int);
		return (2);
	}
	n = 0;
	i = 1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + s[i] - 48;
		i++;
		if (n > 2147483647)
			*error = 1;
	}
	if (i < 11 && n <= 2147483647)
		spec->precision = n;
	return (i);
}

size_t	ft_setconv(const char *s, t_spec *spec, short *minor, short *error)
{
	size_t	i;

	i = 0;
	if (*s == 'z')
	{
		spec->l = 'z';
		i = 1;
	}
	else if (*s == 'l')
	{
		i = 1;
		if (s[1] == 'l')
		{
			spec->l = 'z';
			i = 2;
		}
		else
			spec->l = 'l';
	}
	if (s[i] == '\0')
		*error = 1;
	else if (ft_in(s[i], "diouxXbcsp%") == -1)
		*minor = 1;
	spec->conv = s[i];
	return (i + !!s[i]);
}
