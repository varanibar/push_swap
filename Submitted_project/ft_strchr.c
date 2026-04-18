/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varanibar <varanibar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:43:34 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/18 20:57:22 by varanibar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>

// int main(void)
// {
// 	char s[] = "1234";
// 	char c = '\0';
// 	printf("\nAddress of string passed = %p\n\n", s);
//     printf("pointer returned    strchr = %p\n", strchr(s, c));
//     printf("pointer returned ft_strchr = %p\n", ft_strchr(s, c));

//     return (0);
// }
