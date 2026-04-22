/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varanibar <varanibar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:42:05 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/18 20:55:35 by varanibar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// #include <string.h>
// #include <stdio.h>

// int main(void)
// {

// 	char str1[] = "hello world";
// 	char str2[] = "hello world";
// 	char str3[20] = "hello world";

// 	unsigned char c = 97;
// 	size_t n = 4*sizeof(char);

// 		memset(str1 + 10, c, n);
// 		printf("str1 After    memset: %s\n", str1);
// 		ft_memset(str1 + 10, c, n);
// 		printf("str1 After ft_memset: %s\n\n", str1);
// 			memset(str2 + 10, c, n);
// 			printf("str2 After    memset: %s\n", str2);
// 			ft_memset(str2 + 10, c, n);
// 			printf("str2 After ft_memset: %s\n\n", str2);
// 				memset(str3 + 10, c, n);
// 				printf("str3 After    memset: %s\n", str3);
// 				ft_memset(str3 + 10, c, n);
// 				printf("str3 After ft_memset: %s\n\n", str3);

// 	int array0[5] = {7, 7, 7, 7, 7};
// 	int array1[5] = {7, 7, 7, 7, 7};
// 	int array2[5] = {7, 7, 7, 7, 7};
// 	unsigned char c0 = 254;
// 	int n0 = 3*sizeof(int);

// 	printf("\n\nArray:\n");
// 	int i0 = 0;
// 	while (i0 < 5)
// 	{
// 		printf("%d ", array0[i0]);
// 		i0++;
// 	}

// 	memset(array1, c0, n0);
// 	printf("\nAfter memset:\n");
// 	int i1 = 0;
// 	while (i1 < 5)
// 	{
// 		printf("%d ", array1[i1]);
// 		i1++;
// 	}

// 	ft_memset(array2, c0, n0);
// 	printf("\n\nAfter ft_memset:\n");
// 	int i2 = 0;
// 	while (i2 < 5)
// 	{
// 		printf("%d ", array2[i2]);
// 		i2++;
// 	}

// 	return(0);
// }
