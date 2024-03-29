/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:30:27 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/23 17:46:31 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_powi(ssize_t x, size_t n)
{
	size_t	i;
	ssize_t	x_og;

	if (n == 0)
		return (1);
	i = 1;
	x_og = x;
	while (i * 2 < n)
	{
		x *= x;
		i *= 2;
	}
	while (i < n)
	{
		x *= x_og;
		i++;
	}
	return (x);
}
