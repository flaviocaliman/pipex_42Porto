/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:31:19 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/13 14:53:23 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
/*
void	del_content(void *node)
{
	node = NULL;
}

int main(void)
{
	t_list	*begin, *cont01, *cont02, *cont03;

	begin = NULL;
	cont01 = ft_lstnew("Fla");
	cont02 = ft_lstnew("Gom");
	cont03 = ft_lstnew("Cal");
	ft_lstadd_back(&begin, cont01);
	ft_lstadd_back(&begin, cont02);
	ft_lstadd_back(&begin, cont03);
	while (begin)
	{
		printf("%s\n", (char *)begin->content);
		begin = begin->next;
	}
	ft_lstdelone(cont02, del_content);
	printf("%s -> %s\n", (char *)(cont02->content), (char *)(cont03->content));
	
	return (0);
}*/