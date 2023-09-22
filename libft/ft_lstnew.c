/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:40:38 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/06 14:30:15 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
int main(void)
{
	t_list *newNode = ft_lstnew("Flavio Caliman");
	if (newNode == NULL)
	{
		printf("Erro: falha ao alocar memoria");
		return (1);
	}
	printf("Conteudo do novo no: %s\n", (char*)(newNode->content));
	free(newNode);
	return (0);
}*/