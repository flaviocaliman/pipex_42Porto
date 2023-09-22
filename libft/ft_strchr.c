/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:50:32 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/05 15:45:07 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*(unsigned char *) s == (unsigned char) c)
			return ((char *) s);
		s++;
	}
	if (*(unsigned char *) s == (unsigned char) c)
		return ((char *) s);
	return (NULL);
}

/*int	main(void)
{
	char s4[] = "Flavio";
	printf("%s\n", ft_strchr(s4, 'v'));
	printf("Posicao do caracter: %ld\n\n", ft_strchr(s4, 'v') - s4);
}*/