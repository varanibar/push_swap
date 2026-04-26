/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_selection_sort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/22 16:57:01 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/04/26 14:25:52 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

//Finds the index of the lowest number in stack_a,
//min_pos is set to the counter if our current value is smaller then our current minimal.

static int ft_min_index(t_stack *stack)
{
	t_stack *current;
	t_stack *min;
	int min_pos;
	int counter;
	current = stack;
	min = stack;
	counter = 0;
	min_pos = 0;

	while (current != NULL)
	{

		if (current->val < min->val)
		{
			min = current;
			min_pos = counter;
		}
		counter++;
		current = current->next;
	}
	return (min_pos);
}

//rotate stack_a until the lowest number is at the top
//find the shortest route to get lowest number to the top (lowest cost)
//so if number is in the upper half do ra, if number is in lower half do rra.
//once lowest number is at top push to b.

static void ft_rotate_and_push(t_stack **stack_a, t_stack **stack_b)
{
	int min_pos = ft_min_index(*stack_a);
	while (ft_min_index(*stack_a) != 0)
	{
		int stack_size = ft_stack_size(*stack_a);
		min_pos = ft_min_index(*stack_a);
		if (min_pos <= (stack_size / 2))
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb (stack_b, stack_a);
}

//Do ft_rotate_and_move until stack_a is empty and everything is in stack_b
//then push everything from b back to a.

void ft_selection_sort(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_a != NULL)
	{
		ft_rotate_and_push(stack_a, stack_b);
	}
	while (*stack_b != NULL)
	{
		pa (stack_a, stack_b);
	}
}

// int	main(int argc, char **argv)
// {
// 	t_stack *stack_a = NULL;
// 	t_stack *stack_b = NULL;
// 	int input[argc];
// 	int i;
// 	int j;

// 	i = 0;
// 	j = argc - 1;
// 	while (j > 0)
// 	{
// 		input[i] = ft_atoi(argv[j]);
// 		ft_add_to_stack(&stack_a, input[i]);
// 		i++;
// 		j--;
// 	}
// 	ft_printf("%s\n", "stack_a:");
// 	print_stack(stack_a);
// 	ft_printf("%s\n", "operations used:");
// 	ft_selection_sort(&stack_a, &stack_b);
// 	ft_printf("%s\n", "stack_a:");
// 	print_stack(stack_a);
// 	ft_free_stack(&stack_a);
// 	ft_free_stack(&stack_b);
// 	return (0);
// }
