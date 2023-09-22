/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:52:06 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/05 18:35:21 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	slen;
	size_t	i;
	char	*final_str;

	i = 0;
	slen = ft_strlen(s);
	final_str = (char *)malloc(sizeof(char) * (slen + 1));
	if (!final_str)
		return (NULL);
	while (i < slen)
	{
		final_str[i] = f(i, s[i]);
		i++;
	}
	final_str[slen] = '\0';
	return (final_str);
}
/*
char transform(unsigned int i, char c) {
    if (i % 2 == 0) {
        return ft_toupper(c);
    } else {
        return ft_tolower(c);
    }
}

int main() {
    char* s = "Exemplo de String";
    char* transformed = ft_strmapi(s, &transform);

    printf("String original: %s\n", s);
    printf("String transformada: %s\n", transformed);
    free(transformed);

    return 0;
}*/