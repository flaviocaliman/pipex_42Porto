/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:19:31 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/05 15:31:03 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}	
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

/*int	main(void)
{
	char dest[50];
	const char src[] = "Calimessi";
	printf("%lu\n\n", ft_strlcpy(dest, src, 9));
}*/