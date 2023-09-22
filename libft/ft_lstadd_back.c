/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:03:08 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/06 17:27:52 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}
/*
int main(void)
{
	t_list	*begin, *node01, *node02, *lastNode;
	
	begin = NULL;
	node01 = ft_lstnew("Flavio");
	node02 = ft_lstnew("Caliman");
	ft_lstadd_back(&begin, node01);
	ft_lstadd_back(&begin, node02);
	lastNode = ft_lstlast(begin);
	printf("Ultimo conteudo: %s\n", (char *)lastNode->content);
}*/