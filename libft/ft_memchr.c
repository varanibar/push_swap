/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varanibar <varanibar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 09:38:04 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/18 20:59:03 by varanibar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((unsigned char *)s);
		s++;
		i++;
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>

// int main(void)
// {
// 	// char *s = malloc(10*sizeof(char));
// 	char s[] = "hello world 1234";
// 	char c = 'x';
// 	size_t n = 20;

// 	printf("\nAddress of string passed = %p\n\n", s);
//     printf("pointer returned    memchr = %p\n", memchr(s, c, n));
//     printf("pointer returned ft_memchr = %p\n", ft_memchr(s, c, n));

//     return (0);
// }
