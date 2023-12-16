/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaguyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:58:20 by glaguyon          #+#    #+#             */
/*   Updated: 2023/12/15 16:36:09 by glaguyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_freehalf(void *tstr)
{
	static size_t	i = 0;

	if (tstr)
	{
		if (i)
			free(((t_str *) tstr)->s);
		free(tstr);
	}
	i = !i;
}

int	ft_nextspec(const char *s)
{
	size_t	i;
	char	curr;

	i = 0;
	curr = *s;
	while (curr)
	{
		if (curr == '%')
			return (i);
		i++;
		curr = s[i];
	}
	return (i);
}

t_list	*ft_add_tstr(t_list **lst, t_list *curr, const char *s, int len)
{
	t_list	*node;
	t_str	*tstr;

	tstr = malloc(sizeof(t_str));
	node = malloc(sizeof(t_list));
	if (node == NULL || tstr == NULL)
	{
		ft_lstclear(lst, &ft_freehalf);
		free(tstr);
		free(node);
		return (NULL);
	}
	tstr->s = (char *) s;
	tstr->len = len;
	node->content = tstr;
	node->next = NULL;
	ft_lstadd_back(&curr, node);
	if (*lst == NULL)
		*lst = node;
	return (node);
}

t_list	*ft_add_conv(t_list **lst, t_list *curr, t_str *conv)
{
	t_list	*node;

	if (conv == NULL)
	{
		ft_lstclear(lst, &ft_freehalf);
		return (NULL);
	}
	node = malloc(sizeof(t_list));
	if (node == NULL)
	{
		free(conv->s);
		free(conv);
		ft_lstclear(lst, &ft_freehalf);
		return (NULL);
	}
	node->content = conv;
	node->next = NULL;
	curr->next = node;
	return (node);
}
