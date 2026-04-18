/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:11:18 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/20 11:41:21 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_str_valid(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	if (nptr[i] == '.')
		return (0);
	if (nptr[i] != '\0' && ft_isdigit(nptr[i]))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	if (is_str_valid(nptr))
	{
		while (!ft_isdigit(nptr[i]))
		{
			if (nptr[i] == '-')
				sign = -sign;
			i++;
		}
		while (ft_isdigit(nptr[i]))
		{
			n = n * 10 + (nptr[i] - '0');
			i++;
		}
		return (sign * n);
	}
	return (0);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
// 	char str[] = "-123";
// 	printf("\n   atoi(%s): %d\n",str, atoi(str));
// 	printf("ft_atoi(%s): %d\n",str, ft_atoi(str));

// 	char str1[] = " -123";
// 	printf("\n   atoi(%s): %d\n",str1, atoi(str1));
// 	printf("ft_atoi(%s): %d\n",str1, ft_atoi(str1));

// 	char str2[] = "--123";
// 	printf("\n   atoi(%s): %d\n",str2, atoi(str2));
// 	printf("ft_atoi(%s): %d\n",str2, ft_atoi(str2));

// 	char str3[] = "-+123";
// 	printf("\n   atoi(%s): %d\n",str3, atoi(str3));
// 	printf("ft_atoi(%s): %d\n",str3, ft_atoi(str3));

// 	char str4[] = "-123sdf";
// 	printf("\n   atoi(%s): %d\n",str4, atoi(str4));
// 	printf("ft_atoi(%s): %d\n",str4, ft_atoi(str4));

// 	char str5[] = "+123";
// 	printf("\n   atoi(%s): %d\n",str5, atoi(str5));
// 	printf("ft_atoi(%s): %d\n",str5, ft_atoi(str5));

// 	char str6[] = "++123";
// 	printf("\n   atoi(%s): %d\n",str6, atoi(str6));
// 	printf("ft_atoi(%s): %d\n",str6, ft_atoi(str6));

// 	char str7[] = ".123";
// 	printf("\n   atoi(%s): %d\n",str7, atoi(str7));
// 	printf("ft_atoi(%s): %d\n",str7, ft_atoi(str7));

// 	char str8[] = "0.123";
// 	printf("\n   atoi(%s): %d\n",str8, atoi(str8));
// 	printf("ft_atoi(%s): %d\n",str8, ft_atoi(str8));

// 	char str9[] = "-.123";
// 	printf("\n   atoi(%s): %d\n",str9, atoi(str9));
// 	printf("ft_atoi(%s): %d\n",str9, ft_atoi(str9));

// 	char str10[] = "-0123.01.2";
// 	printf("\n   atoi(%s): %d\n",str10, atoi(str10));
// 	printf("ft_atoi(%s): %d\n",str10, ft_atoi(str10));

// 	char str11[] = "";
// 	printf("\n   atoi(%s): %d\n",str11, atoi(str11));
// 	printf("ft_atoi(%s): %d\n",str11, ft_atoi(str11));
// 	return(0);
// }
