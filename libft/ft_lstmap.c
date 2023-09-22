/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:12:00 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/02 15:18:54 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//-Ponteiro para a nova lista
//-Ponteiro para a nova lista
//-Verifica se lst é NULL ou f é NULL, se for, retorna NULL
//-Percorre a lista enquanto houver elementos
//-Cria novo nó com a função f aplicada no conteúdo do nó atual da lista
//-Verifica se a criação do novo nó falhou
//-Se falhou, apaga a nova lista criada e retorna NULL
//-Adiciona o novo nó criado na lista new_lst
//-Avança para o próximo nó da lista original
//-Retorna a nova lista criada
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	new_node = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
