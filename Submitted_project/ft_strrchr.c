/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varanibar <varanibar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 07:41:15 by varanibar         #+#    #+#             */
/*   Updated: 2026/03/18 20:56:41 by varanibar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*s)
	{
		if (*s == (char)c)
			ptr = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (ptr);
}

// #include <string.h>
// #include <stdio.h>

// int main(void)
// {
// 	char s[] = "DFGDGFDFXAFSDFDXX";
// 	char c = '\0';
// 	printf("\nAddress of string = %p\n\n", s);

// 	printf("pointer returned        strrchr = %p\n", strrchr(s, c));
// 	printf("\npointer returned    ft_ strrchr = %p\n", ft_strrchr(s, c));

//     return (0);
// }
