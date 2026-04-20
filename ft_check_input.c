/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 15:36:55 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/04/20 19:24:35 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_isdigit(char *str)
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

int	ft_check_dup(char **input)
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

int	ft_check_input(char *input)
{
	int	i;

	i = 0;
	if (input[i] == '\0')
		return(0);
	while (input[i])
	{
		if (!ft_check_isdigit(input[i]) || !ft_check_dup(input[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b = NULL;
	int input[argc];
	int i;
	int j;
	i = 0;
	j = 1;
	stack_a = NULL;
	if (argc == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (argv[j])
	{
		if (!ft_check_input(argv[j]))
		{
			printf("%s\n", "Error");
			return(0);
		}
		j++;
	}
	return(0);
}
