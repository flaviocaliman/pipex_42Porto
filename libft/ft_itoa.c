/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-c <fgomes-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:30:54 by fgomes-c          #+#    #+#             */
/*   Updated: 2023/05/05 17:18:01 by fgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	casas_decimais(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*int_to_str(char *str, long l, int i)
{
	if (l == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (l < 0)
	{
		str[0] = '-';
		l = l * -1;
	}
	while (l > 0)
	{
		str[i] = l % 10 + '0';
		l = l / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	l;
	int		i;

	l = n;
	i = casas_decimais(l);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	return (int_to_str(str, l, i));
}
/*
int	main(void)
{
	int n = 1036;
	char *itoa = ft_itoa(n);
	printf("%s\n\n", itoa);
}*/