/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:23:20 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/24 20:21:41 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_populate_str(char *new, char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	total_len;

	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (total_len == 1)
	{
		new = malloc(sizeof(char));
		if (!new)
			return (NULL);
		*new = '\0';
		return (new);
	}
	new = malloc(sizeof(char) * total_len);
	if (!new)
		return (NULL);
	new = ft_populate_str(new, s1, s2);
	return (new);
}

// #include <stdio.h>

// int main(void)
// {
// 	char s1[] = "hello";
// 	char s2[] = "hola";

// 	char *new = ft_strjoin(s1, s2);
// 	printf("%s", new);
// 	free(new);
// 	return (0);
// }
