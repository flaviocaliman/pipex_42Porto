/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:44:59 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/05 18:07:22 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[j] && ft_strchr(set, s1[j]))
		j++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, j, i - j + 1));
}
/*
int main()
{
	char const *s1 = "    exemplo de string para teste     ";
	char const *set = " ";
	char *trimmed = ft_strtrim(s1, set);
	printf("String original: \"%s\"\n", s1);
	printf("String trimada: \"%s\"\n", trimmed);
	free(trimmed);
	return 0;
}*/