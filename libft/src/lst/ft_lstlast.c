/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:05:19 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/05 23:29:04 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*nxt;

	if (lst == NULL)
		return (NULL);
	nxt = lst->next;
	while (nxt != NULL)
	{
		lst = nxt;
		nxt = lst->next;
	}
	return (lst);
}
