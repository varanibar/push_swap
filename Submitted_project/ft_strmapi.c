/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:36:03 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/21 18:27:30 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*str;

	i = 0;
	len = ft_strlen(s);
	str = malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>

// char toupper_test(unsigned int i,char c);

// int main(void)
// {
// 	char s[] = "abcd";
// 	printf("given str = %s\n", s);
// 	char *str = ft_strmapi(s, toupper_test);
// 	printf("returned str = %s\n", str);
// }

// char toupper_test(unsigned int i,char c)
// {
// 	i = 0;
// 	if (c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	return (c);
// }
