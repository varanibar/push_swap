/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:58:51 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/19 18:34:00 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;
	size_t	len;
	size_t	i;

	start = 0;
	end = ft_strlen(s1);
	i = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	len = end - start + 1;
	trim = malloc (len * sizeof(char));
	if (!trim)
		return (NULL);
	while (s1[start] && start < end)
		trim[i++] = s1[start++];
	trim[i] = '\0';
	return (trim);
}

// #include <stdio.h>

// int main(void)
// {
// 	char s1[] = "hehe1234hehehe";
// 	char set[] = "he";
// 	char *trim = ft_strtrim(s1, set);
// 	printf("%s\n", trim);
// 	// free(trim);
// 	return(0);
// }