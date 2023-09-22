/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:40:14 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/06 18:32:57 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	size_t		s1len;
	size_t		s2len;
	char		*strsoma;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	strsoma = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!s1 || !s2 || !strsoma)
		return (NULL);
	i = 0;
	j = 0;
	while (i < (s1len + s2len))
	{
		if (i < s1len)
		{
			strsoma[i] = s1[i];
			i++;
		}
		else
			strsoma[i++] = s2[j++];
	}
	strsoma[i] = '\0';
	return (strsoma);
}
/*
int	main(void)
{
	char const s15[] = "abcd";
	char const s16[] = "efghi";
	char *strjoin = ft_strjoin(s15, s16);
	printf("%s\n\n", strjoin);
}*/