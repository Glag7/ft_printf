/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delnarr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:00:06 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/22 16:01:47 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delnarr(void **arr, void (del)(void *), size_t n)
{
	size_t	i;
	void	*tmp;

	i = 0;
	tmp = arr[i];
	while (i < n)
	{
		del(tmp);
		free(tmp);
		i++;
		tmp = arr[i];
	}
	free(arr);
}
