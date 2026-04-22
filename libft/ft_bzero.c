/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varanibar <varanibar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:44:06 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/18 17:54:07 by varanibar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && n != 0)
	{
		*(char *)s = '\0';
		s++;
		i++;
	}
}

// #include <strings.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char s1[] = "hello world";
// 	int l1 = ft_strlen(s1);
// 	printf("string before = %s\n\n", s1);
// 	bzero(s1 + 2, 15);

// 	printf("string after bzero = %s\n", s1);
// 	int i = 0;
// 	while (i <= l1)
// 	{
// 		printf("s1[%d] = %c\n", i, s1[i]);
// 		i++;
// 	}

// 	char s2[] = "hello world";
// 	int l2 = ft_strlen(s2);
// 	ft_bzero(s2 + 2, 15);

// 	printf("\nstring after ft_bzero = %s\n", s2);
// 	int j = 0;
// 	while (j <= l2)
// 	{
// 		printf("s2[%d] = %c\n", j, s2[j]);
// 		j++;
// 	}
// 	return(0);
// }