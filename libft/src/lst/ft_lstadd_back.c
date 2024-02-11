/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:10:51 by glaguyon          #+#    #+#             */
/*   Updated: 2023/11/21 19:23:30 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;
	t_list	*nxt;

	node = *lst;
	nxt = NULL;
	if (node)
		nxt = node->next;
	while (nxt != NULL)
	{
		node = nxt;
		nxt = node->next;
	}
	if (node != NULL)
		node->next = new;
	else
		*lst = new;
}
