/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rotate_operation.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/22 14:17:58 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/04/29 16:43:00 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*current;
	t_stack	*second;

	current = *stack;
	if (*stack == NULL || current->next == NULL)
		return ;
	second = current->next;
	while (current->next != NULL)
		current = current->next;
	current->next = *stack;
	(*stack)->next = NULL;
	*stack = second;
}

void	ra(t_stack **stack_a, t_ops *counter)
{
	rotate(stack_a);
	counter->ra++;
	ft_printf("%s\n", "ra");
}

void	rb(t_stack **stack_b, t_ops *counter)
{
	rotate(stack_b);
	counter->rb++;
	ft_printf("%s\n", "rb");
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_ops *counter)
{
	rotate(stack_a);
	rotate(stack_b);
	counter->rr++;
	ft_printf("%s\n", "rr");
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
// 	rr(&stack_a, &stack_b);
// 	ft_printf("%s\n", "stack_a after operation:");
// 	print_stack(stack_a);
// 	ft_printf("%s\n", "stack_b after operation:");
// 	print_stack(stack_b);
// 	return (0);
// }
