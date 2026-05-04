/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chunk_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/30 15:30:30 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/05/01 16:49:58 by lekoelma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// am gonna use this later to decide how many chunks to create

static int	ft_sqrt(int nb)
{
	int	n;

	n = 1;
	while (n * n <= nb)
	{
		if (n * n == nb)
			return (n);
		n++;
	}
	return (n - 1);
}

// finds the node with the lowest value in the stack
// that did not get a rank yet. Rank is set to -1 by default (in add_to_stack)

static t_stack	*ft_find_min(t_stack *stack)
{
	t_stack	*current;
	t_stack	*min;

	while (stack != NULL && stack->rank != -1)
		stack = stack->next;
	current = stack;
	min = stack;
	while (current != NULL)
	{
		if (current->val < min->val && current->rank == -1)
			min = current;
		current = current->next;
	}
	return (min);
}

// Goes trough the entire stack and sets the minimal value to i (rank).

void	ft_assign_rank(t_stack **stack)
{
	int		size;
	t_stack	*min;
	int		i;

	size = ft_stack_size(*stack);
	i = 0;
	while (i < size)
	{
		min = find_min(*stack);
		min->rank = i;
		i++;
	}
}
// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	t_stack	*stack_a;
// 	int		input[argc];
// 	int		i;
// 	int		j;

// 	stack_a = NULL;
// 	i = 0;
// 	j = 1;
// 	while (j < argc)
// 	{
// 		input[i] = ft_atoi(argv[j]);
// 		ft_add_to_stack(&stack_a, input[i]);
// 		i++;
// 		j++;
// 	}
// 	ft_printf("%s\n", "stack_a:");
// 	print_stack(stack_a);
// 	rank(&stack_a);
// 	ft_printf("%d\n", stack_a->rank);
// 	return (0);
// }
