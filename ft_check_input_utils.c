/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_input_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/23 16:48:11 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/23 17:04:40 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	ft_flag_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] != '\0' || s2[i] != '\0' )
		return (0);
	return (1);
}

char	*ft_get_flag_type(int j)
{
	char	*methods[5];

	methods[0] = "--bench";
	methods[1] = "--simple";
	methods[2] = "--medium";
	methods[3] = "--complex";
	methods[4] = "--adaptative";
	return (methods[j]);
}

int	ft_flag_checker(char **input, int n, t_flags *flags)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((i < n && i < 2))
	{
		j = 0;
		while (j < 5)
		{
			if (ft_flag_strcmp(input[i], ft_get_flag_type(j)))
			{
				if (j == 0 && !flags->bench)
					flags->bench = 1;
				else if (j > 0 && !flags->method)
					flags->method = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return ((bool)flags->bench + (bool)flags->method);
}

int	ft_create_t_flag(t_flags **flags)
{
	*flags = malloc(sizeof(t_flags));
	if (!*flags)
		return (0);
	(*flags)->bench = 0;
	(*flags)->method = 0;
	return (1);
}
