/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chunk_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/30 15:30:30 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/05/07 10:44:53 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
// rotates stack_b until max is at top, then pushes back to a.
static void	push_back_to_a(t_stack **stack_a, t_stack **stack_b, t_counter *counter)
{
	int	max_index;

	while (*stack_b != NULL)
	{
		max_index = ft_max_index(*stack_b);
		if (max_index != 0)
		{
			if (max_index <= (ft_stack_size(*stack_b)) / 2)
				rb(stack_b, counter);
			else
				rrb(stack_b, counter);
		}
		else
			pa(stack_a, stack_b, counter);
	}
}

// calculates chunk_size, chunk_min and chunk_max and updates those in struct.
static t_bounds	ft_get_chunk_bounds(int chunk_num, int chunk_amount,
		int og_stack_size)
{
	t_bounds	chunk;

	chunk.size = og_stack_size / ft_sqrt(og_stack_size);
	chunk.min = chunk_num * chunk.size;
	if (chunk_num == chunk_amount - 1)
	{
		chunk.max = og_stack_size - 1;
		chunk.size = chunk.max - chunk.min + 1;
	}
	else
		chunk.max = chunk.min + chunk.size - 1;
	return (chunk);
}

// rotates stack a until top is in chunk. If top is in chunk pushes to b.
static void	rotate_and_push_to_b(t_stack **stack_a, t_stack **stack_b,
		t_counter *counter, t_bounds chunk)
{
	int	push_counter;
	int	chunk_index;

	push_counter = 0;
	while (push_counter < chunk.size)
	{
		chunk_index = ft_find_chunk_index(stack_a, chunk.min, chunk.max);
		if (chunk_index == -1)
			break ;
		if (!((*stack_a)->rank >= chunk.min && (*stack_a)->rank <= chunk.max))
		{
			if (chunk_index <= (ft_stack_size(*stack_a)) / 2)
				ra(stack_a, counter);
			else
				rra(stack_a, counter);
		}
		else
		{
			pb(stack_b, stack_a, counter);
			push_counter++;
		}
	}
}

void	ft_chunk_sort(t_stack **stack_a, t_counter *counter)
{
	int			chunk_amount;
	int			chunk_num;
	int			og_stack_size;
	t_bounds	chunk;
	t_stack		*stack_b;

	chunk_amount = ft_sqrt(ft_stack_size(*stack_a));
	chunk_num = 0;
	og_stack_size = ft_stack_size(*stack_a);
	stack_b = NULL;
	while (chunk_num < chunk_amount)
	{
		chunk = ft_get_chunk_bounds(chunk_num, chunk_amount, og_stack_size);
		rotate_and_push_to_b(stack_a, &stack_b, counter, chunk);
		chunk_num++;
	}
	push_back_to_a(stack_a, &stack_b, counter);
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;
// 	t_ops	counter = {0};
// 	int		input[argc];
// 	int		i;
// 	int		j;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	i = 0;
// 	j = 1;
// 	while (j < argc)
// 	{
// 		input[i] = ft_atoi(argv[j]);
// 		ft_add_to_stack(&stack_a, input[i]);
// 		i++;
// 		j++;
// 	}
// 	// ft_printf("%s\n", "stack_a:");
// 	print_stack(stack_a);
// 	ft_assign_rank(&stack_a);
// 	ft_chunk_sort(&stack_a, &stack_b, &counter);
// 	// ft_printf("stack a after sort:\n");
// 	// print_stack(stack_a);
// 	// ft_printf("stack b after sort:\n");
// 	// print_stack(stack_b);
// 	// return (0);
// }
