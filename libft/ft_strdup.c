/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:51:16 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/20 12:03:55 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	int		l;
	char	*dup;

	l = 1 + ft_strlen(s);
	dup = malloc(sizeof(char) * l);
	if (!dup)
		return (0);
	dup = ft_strcpy(dup, s);
	return (dup);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char str[] = "hello world";

// 	printf("Original string:\n");
// 	printf("%p\n",(str));
// 	printf("%s\n",(str));

// 	printf("\nResult with strdup:\n");
// 	printf("%p\n",strdup(str));
// 	printf("%s\n",strdup(str));

// 	printf("\nResult with ft_strdup:\n");
// 	printf("%p\n",ft_strdup(str));
// 	printf("%s\n",ft_strdup(str));

// 	if (ft_strdup(str) == NULL)
// 		printf("allocation failed");

// 	return(0);
// }
