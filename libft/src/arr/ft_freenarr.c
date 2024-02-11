/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freenarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:53:27 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/22 15:54:23 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freenarr(void **arr, size_t n)
{
	size_t	i;
	void	*tmp;

	i = 0;
	tmp = arr[i];
	while (i < n)
	{
		free(tmp);
		i++;
		tmp = arr[i];
	}
	free(arr);
}
