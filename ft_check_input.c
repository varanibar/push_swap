/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 15:36:55 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/05/07 12:46:41 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	ft_check_chars(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

static int	ft_check_limits(char *str)
{
	int		i;
	long	nbr;
	long	limit;

	i = 0;
	nbr = 0;
	limit = INT_MAX;
	if (str[i] == '-')
	{
		limit += 1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (nbr > limit)
		return (0);
	return (1);
}

static int	ft_split_validate_add(char **argv, int n, t_stack **stack)
{
	int		i;
	int		j;
	char	**input;

	i = 0;
	while (i < n)
	{
		j = 0;
		input = ft_split(argv[i++], ' ');
		if (!input)
			return (0);
		else if (input[0] == NULL)
			return (ft_free_array(input), 0);
		while (input[j] != NULL)
		{
			if (!ft_check_chars(input[j]))
				return (ft_free_array(input), 0);
			if (!ft_check_limits(input[j]))
				return (ft_free_array(input), 0);
			if (!ft_add_to_stack(stack, ft_atoi(input[j++])))
				return (ft_free_array(input), 0);
		}
		ft_free_array(input);
	}
	return (1);
}

static int	ft_check_dup(t_stack *stack)
{
	int		i;
	t_stack	*current;
	t_stack	*next;

	i = 0;
	current = stack;
	while (current != NULL && current->next != NULL)
	{
		if (i != 0)
			current = current->next;
		next = current->next;
		while (next != NULL)
		{
			if (current->val == next->val)
				return (0);
			next = next->next;
		}
		i++;
	}
	return (1);
}

int	ft_check_input(int argc, char **argv, t_stack **stack, t_flags *flags)
{
	int	i;
	int	n_flags;

	i = 1;
	n_flags = 0;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	else
	{
		n_flags = ft_flag_checker(argv + 1, argc - 1, flags);
		i += n_flags;
		if (i == argc)
			return (0);
		if (!ft_split_validate_add(argv + 1 + n_flags, argc - i, stack))
			return (0);
		if (!ft_check_dup(*stack))
			return (0);
	}
	ft_assign_rank(stack);
	return (1);
}

/*
** Main checker function, it's in charge of:
**
** 	- Checks if there are enough arguments passed
** 	- Checks the flags
** 	- Sending the remaining arguments to a processing function that splits,
** 	  validates and adds the arguments to the stack. If it
**
** 	- Checks the duplicates
**
*/

// int	main(int argc, char **argv)
// {
// 	t_stack	*stack_a;
// 	t_flags	*flags;

// 	stack_a = NULL;
// 	flags = NULL;
// 	if (!ft_check_input(argc, argv, &stack_a, &flags))
// 	{
// 		ft_free_stack(&stack_a);
// 		free(flags);
// 		return (ft_printf("Error\n"), 0);
// 	}
// 	ft_free_stack(&stack_a);
// 	free(flags);
// 	return (0);
// }
