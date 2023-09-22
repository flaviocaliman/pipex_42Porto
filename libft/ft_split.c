/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:06:21 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/05 18:29:23 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cont_palavras(const char *str, char x)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != x)
		{
			count++;
			while (*str && (*str != x))
				str++;
		}
		else
			str++;
	}
	return (count);
}

static char	*separ_palavras(const char *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *) malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**words;

	i = 0;
	j = 0;
	words = (char **) malloc(sizeof(char *) * (cont_palavras(s, c) + 1));
	if (!words || !s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			words[j] = separ_palavras(&s[i], c);
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
		else
			i++;
	}
	words[j] = 0;
	return (words);
}
/*
int main() {
    char str[] = "hello world, how are you?";
    char **words = ft_split(str, ' ');
    if (!words) {
        printf("Erro: não foi possível alocar memória.\n");
        return 1;
    }
    for (int i = 0; words[i] != NULL; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }
    free(words);
    return 0;
}*/