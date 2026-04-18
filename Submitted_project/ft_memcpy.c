/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:33:29 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/22 13:59:54 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == (void *)0 && src == (void *)0)
		return (NULL);
	while (i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	return (dest);
}

// #include <string.h>
// #include <stdio.h>

// int main(void)
// {
// 	char dest1[50] = "1234";
// 	char src1[50] = "";
// 	int n1 = 10;

// 	char dest2[50] = "1234";
// 	char src2[50] = "";
// 	int n2 = 10;

// 	memcpy(dest1, src1+3, n1);
// 	printf("%s\n", dest1);

// 	ft_memcpy(dest2, src2+3, n2);
// 	printf("%s\n", dest2);

// 	return(0);
// }
