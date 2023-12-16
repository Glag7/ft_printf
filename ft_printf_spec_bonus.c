/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:49:50 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/15 16:35:51 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_addspec(t_list **lst, t_list **curr, const char **s, va_list args)
{
	static short	minor = 0;
	t_spec			spec;
	t_str			*conv;

	minor = minor && lst && *lst;
	if (lst == NULL || *lst == NULL)
		return (-3);
	if (**s != '%')
	{
		conv = malloc(sizeof(t_str));
		if (conv != NULL)
			*conv = (t_str){0, 0};
		*curr = ft_add_conv(lst, *curr, conv);
		if (curr == NULL)
			return (-2);
		return (0);
	}
	if (ft_setspec(s, &spec, &minor, args))
		return (-1);
	conv = ft_get_conv_tstr(spec, args);
	*curr = ft_add_conv(lst, *curr, conv);
	if (curr == NULL)
		return (-2);
	return (conv->len);
}

short	ft_setspec(const char **s, t_spec *spec, short *minor, va_list args)
{
	short	error;

	(*s)++;
	error = 0;
	*spec = (t_spec){0, 0, 0, 0, -42, 0, 0};
	*s += ft_setflags(*s, spec);
	*s += ft_setwidth(*s, spec, &error, args);
	*s += ft_setpre(*s, spec, &error, args);
	if (!(error && !*minor))
		*s += ft_setconv(*s, spec, minor, &error);
	if (error && !*minor)
		return (1);
	return (0);
}
