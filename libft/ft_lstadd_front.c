/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:21:41 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/06 14:53:11 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
int main(void)
{
	t_list *lst = NULL;
	ft_lstadd_front(&lst, ft_lstnew("elemento 1"));
	ft_lstadd_front(&lst, ft_lstnew("elemento 2"));
	while (lst)
	{
		printf("%s\n", (char*)lst->content);
		lst = lst->next;
	}
	return (0);
}*/