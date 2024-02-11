/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:53:32 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/22 17:05:47 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swaplen(void *a, void *b, size_t len)
{
	void	*tmp;

	tmp = malloc(len);
	if (tmp == NULL)
	{
		a = NULL;
		b = NULL;
		return ;
	}
	ft_memcpy(tmp, a, len);
	ft_memcpy(a, b, len);
	ft_memcpy(b, tmp, len);
	free(tmp);
}
