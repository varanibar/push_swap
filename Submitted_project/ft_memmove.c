/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:35:15 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/22 14:06:45 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = n - 1;
	j = 0;
	if (dest == (void *)0 && src == (void *)0)
		return (NULL);
	if (dest > src)
	{
		while (i + 1 > 0)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		while (j < n)
		{
			*(char *)(dest + j) = *(char *)(src + j);
			j++;
		}
	}
	return (dest);
}

// #include <string.h>
// #include <stdio.h>

// int main(void)
// {
// 	char dest1[] = "abcd";
// 	int n1 = 4;

// 	char dest2[] = "abcd";
// 	int n2 = 4;

// 	memmove(dest1 + 1, dest1, n1);
// 	printf("%s\n", dest1);

// 	ft_memmove(dest2+1, dest2, n2);
// 	printf("%s\n", dest2);

// 	return(0);
// }
