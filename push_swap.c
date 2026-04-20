/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/18 13:51:14 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/20 19:24:41 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	sign;

	sign = 1;
	i = 0;
	nb = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}

void	print_stack(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current != NULL)
	{
		printf("%d\n", current->val);
		current = current->next;
	}
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
	j = argc - 1;
	while (j > 0)
	{
		input[i] = ft_atoi(argv[j]);
		if (new_node(&stack_a, input[i]) == -1)
			return(write(1, "error", 5));
		i++;
		j--;
	}

	double disorder;
	disorder = compute_disorder(stack_a);
	printf("disorder = %f\n\n", disorder);

	printf("%s\n", "Stack before operation:");
	print_stack(stack_a);
	// rotate(&stack_a);

	// printf("%s\n", "Stack after operation:");

	// print_stack(stack_a);

	//moving first node to stack b
	stack_b = stack_a;
	stack_a = stack_a->next;
	stack_b->next = NULL;
	printf("%s\n", "Stack a:");
	print_stack(stack_a);
	printf("%s\n", "Stack b:");
	print_stack(stack_b);
	return (0);
}
