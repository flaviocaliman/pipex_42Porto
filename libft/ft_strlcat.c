/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:45:25 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/05 15:31:47 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	slen;
	size_t	dlen;
	size_t	i;
	size_t	n;

	slen = ft_strlen(src);
	dlen = ft_strlen(dest);
	i = 0;
	n = dlen;
	if (size <= dlen)
		return (slen + size);
	while (src[i] && n < size - 1)
	{
		dest[n] = src[i];
		n++;
		i++;
	}
	dest[n] = '\0';
	return (dlen + slen);
}

/*int	main(void)
{
	char d1[] = "Flavio";
	const char s1[] = " Caliman";
	printf("%lu\n\n", ft_strlcat(d1, s1, 20));
}*/