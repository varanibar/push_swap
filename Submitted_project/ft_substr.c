/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:37:32 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/24 20:22:40 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	len_s;
	char			*sub;

	i = 0;
	len_s = ft_strlen(s);
	if (start < len_s)
	{
		if (len >= len_s - start)
			len = len_s - start;
		sub = malloc(sizeof(char) * (len + 1));
		if (!sub)
			return (NULL);
		while (i < len && s[start])
			sub[i++] = (char)s[start++];
	}
	else
	{
		sub = malloc(sizeof(char));
		if (!sub)
			return (NULL);
	}
	sub[i] = '\0';
	return (sub);
}

// #include <string.h>
// #include <stdio.h>

// int main(void)
// {
// 	char s[] = "";
// 	int start = 1;
// 	int len = 1;

// 	char *sub = ft_substr(s, start, len);
// 	printf("%p	>%s\n%p	>%s", s, s, sub, sub);
// 	return(0);
// }