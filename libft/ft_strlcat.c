/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:15:41 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/16 18:41:01 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l_dst;
	size_t	l_src;

	i = 0;
	l_dst = ft_strlen (dst);
	l_src = ft_strlen (src);
	if (size == 0 || size <= l_dst)
		return (size + l_src);
	while (src[i] && i < (size - l_dst - 1))
	{
		dst[l_dst + i] = src[i];
		i++;
	}
	dst[l_dst + i] = '\0';
	return (l_dst + l_src);
}

// #include <bsd/string.h>
// #include <stdio.h>

// int main(void)
// {
// 	char src[] = "hello";
// 	char dst[] = "abcdefg";
// 	size_t size = 10;

// 	char src2[] = "hello";
// 	char dst2[] = "abcdefg";
// 	size_t size2 = 10;

// 	int result;
// 	int result2;

// 	printf("src =\n%s\n\n", src);
// 	printf("dest =\n%s\n\n", dst);
// 	printf("size =\n%zu\n\n", size);

// 	result = strlcat(dst, src, size);
// 	result2 = ft_strlcat(dst2, src2, size2);
// 	printf("result    strlcat = %d\n", result);
// 	printf("result ft_strlcat = %d\n\n", result2);
// 	printf("dst after    strlcat = %s\n", dst);
// 	printf("dst after ft_strlcat = %s\n\n", dst2);
// 	return (0);
// }
