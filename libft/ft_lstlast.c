/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:29:08 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/06 17:08:06 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int main(void)
{
	t_list	*begin;
	t_list	*node01;
	t_list	*node02;
	t_list	*node03;
	t_list	*lastNode;
	char 	*lastNodeContent;

	begin = NULL;
	node03 = ft_lstnew("Flavio");
	node02 = ft_lstnew("Gomes");
	node01 = ft_lstnew("Caliman");
	ft_lstadd_front(&begin, node01);
	ft_lstadd_front(&begin, node02);
	ft_lstadd_front(&begin, node03);
	
	lastNode = ft_lstlast(begin);
	
	lastNodeContent = lastNode->content;
	printf("%s\n", lastNodeContent);
	
	return (0);
}*/