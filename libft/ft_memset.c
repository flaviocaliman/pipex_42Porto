/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:14:42 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/05 15:52:01 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = s;
	while (i < n)
		str[i++] = (unsigned char) c;
	return (s);
}

/*int	main(void)
{
	char s6[] = "CaliMan";
	ft_memset(s6, 'x', 4);
	printf("%s\n\n", s6);
}*/