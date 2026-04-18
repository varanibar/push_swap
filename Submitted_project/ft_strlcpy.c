/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:19:39 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/16 11:38:55 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen (src);
	if (size == 0)
		return (l);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (l);
}

// #include <bsd/string.h>
// #include <stdio.h>

// int main(void)
// {
// 	char src[] = "hello a";
// 	char dst[] = "sdf";
// 	size_t size = 3;

// 	char src2[] = "hello a";
// 	char dst2[] = "sdf";
// 	size_t size2 = 3;

// 	int result;
// 	int result2;
// 	printf("src =\n%s\n\n", src);
// 	printf("dest =\n%s\n\n", dst);

// 	result = strlcpy(dst, src, size);
// 	result2 = ft_strlcpy(dst2, src2, size2);
// 	printf("result    strlcpy = %d\n", result);
// 	printf("result ft_strlcpy = %d\n\n", result2);
// 	printf("dst after    strlcpy = %s\n", dst);
// 	printf("dst after ft_strlcpy = %s\n\n", dst2);
// 	return (0);
// }