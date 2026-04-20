/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekoelma <lekoelma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:36:55 by lekoelma          #+#    #+#             */
/*   Updated: 2026/04/20 17:36:16 by lekoelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_dup(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = i + 1;
		while (input[j])
		{
			if (ft_atoi(input[i]) == ft_atoi(input[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_input(char *input)
{
	int	i;

	i = 0;
	if (input[i] == '\0')
		return(0);
	while (input[i])
	{
		if (!(ft_isdigit(&input[i])))
			return (0);
		i++;
	}
	return (1);
}