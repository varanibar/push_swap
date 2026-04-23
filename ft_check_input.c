/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 15:36:55 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/04/23 17:08:10 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	ft_is_str_valid(char *str)
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

static int	ft_split_validate_add(char **argv, int n, t_stack **stack)
{
	int		i;
	int		j;
	char	**input;

	i = 0;
	j = 0;
	while (i < n)
	{
		input = ft_split(argv[i], ' ');
		if (!input || input[0] == NULL)
			return (ft_free_stack(stack), 0);
		while (input[j] != NULL)
		{
			if (!ft_is_str_valid(input[j]))
				return (free(input[j]), free(input), 0);
			if (ft_add_to_stack(stack, ft_atoi(input[j])) == -1)
				return (free(input[j]), free(input), 0);
			free(input[j]);
			j++;
		}
		i++;
		j = 0;
		free(input);
	}
	return (1);
}
/*
** Main checker function, it's in charge of:
**
** 	- Checks if there are enough arguments passed
** 	- Creates the node for the flags
** 	- Checks the flags
** 	- Sending the remaining arguments to a processing function splits,
** 	  validates and adds the arguments to the stack
** 	- Checks the duplicates
**
*/

int	ft_check_input(int argc, char **argv, t_stack **stack, t_flags **flags)
{
	int	i;
	int	n_flags;

	i = 1;
	n_flags = 0;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	else
	{
		if (!ft_create_t_flag(flags))
			return (0);
		n_flags = ft_flag_checker(argv + 1, argc - 1, *flags);
		i += n_flags;
		if (i == argc)
			return (0);
		if (!ft_split_validate_add(argv + 1 + n_flags, argc - i, stack))
			return (0);
		if (!ft_check_dup(*stack))
			return (0);
	}
	return (1);
}

/*
** Testing main for this function, when we call it in the
** push swap function we need to be careful
** to clear and free just like here
**
*/

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_flags	*flags;

	stack_a = NULL;
	flags = NULL;
	if (!ft_check_input(argc, argv, &stack_a, &flags))
	{
		ft_free_stack(&stack_a);
		free(flags);
		return (ft_printf("Error\n"), 0);
	}
	ft_free_stack(&stack_a);
	free(flags);
	return (0);
}
