/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:52:50 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/06 15:39:38 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*
int main(void)
{
	t_list	*list;
	t_list	*newNode;
	
	list = NULL;
	list = ft_lstnew("Flavio");
	newNode = ft_lstnew("Caliman");
	ft_lstadd_front(&list, newNode);
	newNode = ft_lstnew("!");
	ft_lstadd_front(&list, newNode);
	int	size = ft_lstsize(list);
	printf("Tamanho da lista: %d\n", size);
	return (0);
}*/