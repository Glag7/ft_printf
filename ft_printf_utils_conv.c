/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_conv.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:16:37 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/15 18:42:43 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_cpy_nbr(char *tmp, short neg, char *dest, int *len)
{
	size_t	i;
	char	c;

	i = 0;
	if (neg)
	{
		i++;
		dest[0] = '-';
	}
	c = *(tmp - i);
	while (c)
	{
		dest[i] = c;
		i++;
		c = *(tmp - i);
	}
	*len += i;
}

void	ft_putnbrbase_str(ssize_t n, char *dest, char *base, int *i)
{
	size_t	numlen;
	size_t	len;
	size_t	num;
	char	tmp[66];
	short	neg;

	num = n;
	len = ft_strlen(base);
	if (n < 0)
	{
		neg = 1;
		num = -n;
	}
	else
		neg = 0;
	*tmp = '\0';
	numlen = 1;
	while (num || numlen == 1)
	{
		tmp[numlen] = base[num % len];
		num /= len;
		numlen++;
	}
	ft_cpy_nbr(tmp + numlen + neg - 1, neg, dest, i);
}

void	ft_putnbrbase_pos_str(size_t n, char *dest, char *base, int *i)
{
	size_t	numlen;
	size_t	len;
	char	tmp[66];

	len = ft_strlen(base);
	*tmp = '\0';
	numlen = 1;
	while (n || numlen == 1)
	{
		tmp[numlen] = base[n % len];
		n /= len;
		numlen++;
	}
	ft_cpy_nbr(tmp + numlen - 1, 0, dest, i);
}

t_str	*ft_newtstr_pad(size_t len, size_t word_len, char pad)
{
	char	*str;
	t_str	*conv;

	str = malloc(len * sizeof(char));
	conv = malloc(sizeof(t_str));
	if (str == NULL || conv == NULL)
	{
		free(conv);
		free(str);
		return (NULL);
	}
	if (pad == '-')
		ft_bspace(str + word_len, len - word_len);
	else if (pad == '0')
		ft_bzchar(str, len - word_len);
	else
		ft_bspace(str, len - word_len);
	conv->len = len;
	conv->s = str;
	return (conv);
}

long	ft_parsewidth(int width, char *pad)
{
	if (width > 0)
		return (width);
	*pad = '-';
	if (width == -2147483648)
		return (2147483648);
	return (-width);
}
