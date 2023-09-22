/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:01:48 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/06 18:24:44 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	totalsize;
	void	*dst;

	totalsize = nmemb * size;
	dst = malloc(totalsize);
	if (!dst)
		return (NULL);
	ft_memset(dst, 0, totalsize);
	return (dst);
}
/*
int	main(void)
{
	void *calloc;
	calloc = ft_calloc(10, 5);
	printf("%p\n\n", &calloc);
}*/