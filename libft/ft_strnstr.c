/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:01:30 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/05 15:51:12 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && big[i + j] && little[j] == big[i + j]
			&& (i + j) < len)
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char big[] = "Hello, world!";
    const char little[] = " ";
	char *result = ft_strnstr(big, little, 10);
    if (result != NULL)
        printf("Substring encontrada: %s\n\n", result);
    else
    {
		printf("Substring nao encontrada\n\n");
	}
}*/