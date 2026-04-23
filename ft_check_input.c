/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 15:36:55 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/04/23 15:13:00 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

// void	print_stack(t_stack *stack)
// {
// 	t_stack	*current;

// 	current = stack;
// 	while (current != NULL)
// 	{
// 		ft_printf("%d\n", current->val);
// 		current = current->next;
// 	}
// }

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
	int	i;
	t_stack *current;
	t_stack *next;

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

static int ft_flag_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] != '\0' || s2[i] != '\0' )
		return(0);
	return(1);
}

static char *ft_get_flag_type(int j)
{
	char *methods[5];

	methods[0] = "--bench";
	methods[1] = "--simple";
	methods[2] = "--medium";
	methods[3] = "--complex";
	methods[4] = "--adaptative";
	return (methods[j]);
}


static int ft_flag_checker(char **input, int n, t_flags *flags)
{
	int		i;
	int		j;

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

void	ft_ps_lstclear(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	tmp = NULL;
	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
// static void	free_input(char **array, int i)
// {
// 	while (i > 0)
// 		free(array[--i]);
// 	free(array);
// }
static int	ft_split_validate_add(char **argv, int n, t_stack **stack)
{
	int	i;
	int j;
	char **input;

	i = 0;
	j = 0;
	while (i < n)
	{
		input = ft_split(argv[i], ' ');
		if (!input || input[0] == NULL)
			return (ft_ps_lstclear(stack), 0);
		while (input[j] != NULL)
		{
			ft_printf("j = %\n",j);
			if (!ft_is_str_valid(input[j]))
				return (free(input), ft_ps_lstclear(stack), 0);
			if (ft_add_to_stack(stack, ft_atoi(input[j])) == -1)
				return (free(input), ft_ps_lstclear(stack), 0);
			j++;
		}
		i++;
		j = 0;
		free(input);
	}

	// print_stack(*stack);
	return(1);
}

static int ft_create_t_flag(t_flags **flags)
{
	*flags = malloc(sizeof(t_flags));
	if (!*flags)
		return (0);
	(*flags)->bench = 0;
	(*flags)->method = 0;
	return (1);
}



/*
** Main checker function, it's in charge of:
**
** 	- Checking if there are enough arguments passed
** 	- Checking if there are valid flags present (and if those are the only arguments passed)
** 	- Sending the remaining arguments to a processing function that splits the strings if necessary,
** 	  validates the validity of input and adds it to the stack
** 	- Once all the input arguments are in the stack, the duplicates needs to be verified
**
*/

int	ft_check_input(int argc, char **argv, t_stack **stack, t_flags **flags)
{
	int	i;
	int n_flags;

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
			return(free(flags), 0);
		if (!ft_split_validate_add(argv + 1 + n_flags, argc - i, stack))
			return (free(flags), 0);
		if (!ft_check_dup(*stack))
			return (free(flags), 0);
	}
	return (1);
}

// Testing main for this function

int	main(int argc, char **argv)
{
	t_stack *stack_a = NULL;
	t_flags	*flags = NULL;

	if (!ft_check_input(argc, argv, &stack_a, &flags))
	{
		return (ft_printf("Error\n"), 0);
	}
	ft_ps_lstclear(&stack_a);
	free(flags);
	return(0);
}
