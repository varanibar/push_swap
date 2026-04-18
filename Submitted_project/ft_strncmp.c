/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varanibar <varanibar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:46:02 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/18 19:22:49 by varanibar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0' ))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	//unsigned char is necessary otherwise it doesnt work with non ascii values
//     char a[] = "\x12\xff\x65\x12\xbd\xde\xad";
//     char b[] = "\x12\x02";
// 	int c = 6;

// 	printf("   strncmp = %d\n", strncmp(a, b, c));

//     char s1[] = "\x12\xff\x65\x12\xbd\xde\xad";
//     char s2[] = "\x12\x02";
// 	int n = 6;

// 	printf("ft_strncmp = %d\n", ft_strncmp(s1, s2, n));
// 	return(0);

// }
