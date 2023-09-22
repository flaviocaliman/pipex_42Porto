/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:54:10 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/07 09:08:40 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
/*
void print_content(void *content)
{
	printf("%s\n", (char *) content);
}

int	main(void)
{
	t_list	*begin, *node01, *node02, *node03;
	
	begin = NULL;
	node01 = ft_lstnew("Flavio");
	node02 = ft_lstnew("Gomes");
	node03 = ft_lstnew("Caliman");
	ft_lstadd_back(&begin, node01);
	ft_lstadd_back(&begin, node02);
	ft_lstadd_back(&begin, node03);
	ft_lstiter(begin, &print_content);
	return (0);
}*/