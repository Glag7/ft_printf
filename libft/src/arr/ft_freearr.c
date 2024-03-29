/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:44:46 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/22 15:53:15 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freearr(void **arr)
{
	size_t	i;
	void	*tmp;

	i = 0;
	tmp = arr[i];
	while (tmp)
	{
		free(tmp);
		i++;
		tmp = arr[i];
	}
	free(arr);
}
