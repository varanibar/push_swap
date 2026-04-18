/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 17:47:18 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/21 16:34:00 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calculate_len(int n)
{
	int		size;

	size = 1;
	if (n < 0)
		size++;
	while (n / 10 != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

static char	*populate_string(int n, char *str, int len)
{
	int		i;
	long	mod;
	long	num;

	num = n;
	str[len] = '\0';
	i = len - 1;
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num >= 10)
	{
		mod = num % 10;
		num = num / 10;
		str[i--] = (char)(mod + 48);
	}
	str[i] = (char)(num + 48);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = calculate_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str = populate_string(n, str, len);
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	n;
// 	char *s;

// 	n = -9;
// 	printf("size = %d\n", calculate_len(n));
// 	s = ft_itoa(n);
// 	printf("string = %s\n", s);
// }
	// printf("i = %d > mod = %ld\n", i, mod);