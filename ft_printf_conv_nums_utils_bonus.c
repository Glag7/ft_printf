/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_nums_utils_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:52:24 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/15 16:35:28 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_numlen(size_t n, size_t baselen)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= baselen;
		i++;
	}
	return (i);
}

void	ft_nbrbase(char *s, t_spec spec, size_t num, char *base)
{
	size_t	len;
	size_t	baselen;
	size_t	nlen;

	len = spec.width;
	baselen = ft_strlen(base);
	nlen = ft_numlen(num, baselen);
	if (spec.sign)
		*s = spec.sign;
	s += !!spec.sign;
	if (num && spec.alt)
	{
		*s = '0';
		*(s + 1) = spec.alt;
		s += 2;
	}
	ft_bzchar(s, spec.precision - nlen);
	s += spec.precision - 1;
	while (num)
	{
		*s = base[num % baselen];
		s--;
		num /= baselen;
	}
}
