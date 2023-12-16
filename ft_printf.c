/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:20:11 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/15 19:09:43 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;
	t_list	*strs;

	if (!s)
		return (-1);
	strs = NULL;
	va_start(args, s);
	len = ft_printargs(s, args, strs);
	va_end(args);
	if (len < 0)
		return (-1);
	return (len);
}

int	ft_printargs(const char *s, va_list args, t_list *strs)
{
	t_list	*tmp;
	size_t	len_total;
	size_t	len_malloc;
	size_t	len;
	size_t	n;

	len = 0;
	len_malloc = 0;
	len_total = 0;
	tmp = NULL;
	while (*s || (len_total == 0 && !strs))
	{
		n = ft_nextspec(s);
		tmp = ft_add_tstr(&strs, tmp, s, n);
		s += n;
		len += n;
		n = ft_addspec(&strs, &tmp, &s, args);
		ft_checkspec(n, &strs, &len, &len_malloc);
		if (ft_printcheck(&strs, &len, &len_malloc, &len_total))
			return (-1);
	}
	ft_addspec(0, 0, 0, 0);
	if ((strs && ft_print(&strs, &len, &len_total)) || len_total > 2147483647)
		return (-1);
	return (len_total);
}

short	ft_printcheck(t_list **strs, size_t *len, size_t *len_m, size_t *len_t)
{
	if (*strs == NULL)
	{
		ft_addspec(0, 0, 0, 0);
		return (1);
	}
	if (*len_m > MAX_MEM)
	{
		*len_m = 0;
		if (ft_print(strs, len, len_t))
		{
			ft_addspec(0, 0, 0, 0);
			return (1);
		}
	}
	return (0);
}

void	ft_checkspec(size_t n, t_list **strs, size_t *len, size_t *len_m)
{
	if (n == (size_t) -3)
		return ;
	else if (n == (size_t) -2)
		ft_freehalf(NULL);
	else if (n == (size_t) -1)
	{
		ft_print(strs, len, len);
		ft_freehalf(NULL);
	}
	else
	{
		*len_m += n;
		*len += n;
	}
}

short	ft_print(t_list **strs, size_t *len, size_t *len_t)
{
	char	*toprint;
	size_t	tmp;

	tmp = *len;
	toprint = ft_lsttstr_to_str(strs, tmp, &ft_freehalf, NULL);
	if (toprint == NULL)
		return (1);
	if (write(1, toprint, tmp) == -1)
	{
		free(toprint);
		return (1);
	}
	free(toprint);
	*len_t += tmp;
	*len = 0;
	return (0);
}
