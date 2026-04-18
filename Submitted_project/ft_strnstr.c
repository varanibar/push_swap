/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varanibar <varanibar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:13:10 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/18 20:56:52 by varanibar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	if (*big == '\0')
		return (NULL);
	while (i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] == little[j] && little[j] && (i + j) < len)
				j++;
			if (little[j] == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}

// #include <bsd/string.h>
//#include <stdio.h>
// int main(void)
// {
// 	char largestring[] = "Foo Ba Bar Bar";
//     char smallstring[] = "Bar";
// 	size_t len = 0;

//     char *ptr1;
// 	char *ptr2;

//     ptr1 = strnstr(largestring, smallstring, len);
// 	printf("%p  >  %s\n", ptr1, ptr1);

// 	ptr2 = ft_strnstr(largestring, smallstring, len);
// 	printf("%p  >  %s\n", ptr2, ptr2);

// 	return(0);
// }
