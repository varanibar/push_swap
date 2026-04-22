/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_reverse_rotate_operation.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 15:35:33 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/04/22 16:46:46 by lekoelma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*current;
	t_stack	*top;
	t_stack	*prev;

	current = *stack;
	if (*stack == NULL || current->next == NULL)
		return ;
	top = *stack;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	current->next = top;
	prev->next = NULL;
	*stack = current;
}
void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("%s\n", "rra");
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("%s\n", "rrb");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("%s\n", "rrr");
}
// int	main(void)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;
// 	int		i;
// 	int		j;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	i = 4;
// 	j = 8;
// 	while (i > 0)
// 	{
// 		ft_add_to_stack(&stack_a, i);
// 		ft_add_to_stack(&stack_b, j);
// 		i--;
// 		j--;
// 	}
// 	ft_printf("%s\n", "stack_a before operation:");
// 	print_stack(stack_a);
// 	ft_printf("%s\n", "stack_b before operation:");
// 	print_stack(stack_b);
// 	rrr(&stack_a, &stack_b);
// 	ft_printf("%s\n", "stack_a after operation:");
// 	print_stack(stack_a);
// 	ft_printf("%s\n", "stack_b after operation:");
// 	print_stack(stack_b);
// 	return (0);
// }
