/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:26:07 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/05 15:54:55 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;

	str = s;
	while (n > 0)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		str++;
		n--;
	}
	return (NULL);
}

/*int	main(void)
{
	const unsigned char s9[] = "Flavio Caliman";
	char *memchr = ft_memchr(s9, 'C', 10);
	if (memchr != NULL)
		printf("Pointer: %s\n", memchr);
	else
		printf("Caracter nao encontrado!\n\n");
}*/