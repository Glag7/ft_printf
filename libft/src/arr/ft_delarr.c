/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:56:45 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/22 15:59:57 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delarr(void **arr, void (del)(void *))
{
	size_t	i;
	void	*tmp;

	i = 0;
	tmp = arr[i];
	while (tmp)
	{
		del(tmp);
		free(tmp);
		i++;
		tmp = arr[i];
	}
	free(arr);
}
