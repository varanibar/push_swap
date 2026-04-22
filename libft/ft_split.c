/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varaniba <varaniba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 12:09:20 by varaniba          #+#    #+#             */
/*   Updated: 2026/03/25 15:37:06 by varaniba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	n;
	int	word;

	i = 0;
	n = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && word == 0)
			word = 1;
		else if (s[i] == c && word == 1)
		{
			n++;
			word = 0;
		}
		i++;
	}
	if (word == 1)
		n++;
	return (n);
}

static void	free_array(char **array, int i)
{
	while (i > 0)
		free(array[--i]);
	free(array);
}

static char	**allocate_memory(char **array, char const *s, char c, int n)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (*s && i < n)
	{
		if (*s == c)
			s++;
		else
		{
			size = 0;
			while (*s && *(s++) != c)
				size++;
			array[i] = malloc(sizeof(char) * (size + 1));
			if (!array[i])
			{
				free_array(array, i);
				return (NULL);
			}
			i++;
		}
	}
	return (array);
}

static char	**populate_strings(char **array, char const *s, char c, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s && i < n)
	{
		if (*s == c)
			s++;
		else
		{
			j = 0;
			while (*s && *s != c)
				array[i][j++] = *(s++);
			array[i++][j] = '\0';
		}
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		n;

	n = count_words(s, c);
	array = malloc(sizeof(char *) * (n + 1));
	if (!array)
		return (NULL);
	array = allocate_memory(array, s, c, n);
	if (array == NULL)
		return (NULL);
	array = populate_strings(array, s, c, n);
	return (array);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char c = ' ';
// 	char str[] = "      split       this for   me  !       ";
// 	char **array = ft_split(str,c);
// 	int n = count_words(str, c);
// 	int i = 0;
// 	while (i < n)
// 	{
// 		printf("array[%d] = %s\n", i, array[i]);
// 		i++;
// 	}
// }