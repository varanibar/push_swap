/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_selection_sort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/22 16:57:01 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/04/23 11:29:04 by lekoelma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include "libft.h"

int	ft_ps_lstsize(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

int ft_min_index(t_stack *stack)
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

void ft_move_to_b (t_stack **stack_a, t_stack **stack_b)
{
	int min_pos = ft_min_index(*stack_a);
	while (ft_min_index(*stack_a) != 0)
	{
		int stack_size = ft_ps_lstsize(*stack_a);
		min_pos = ft_min_index(*stack_a);
		if (min_pos <= (stack_size / 2))
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb (stack_b, stack_a);
}

void ft_selection_sort(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_a != NULL)
	{
		ft_move_to_b(stack_a, stack_b);
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
// 	return (0);
// }