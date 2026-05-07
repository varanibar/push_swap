/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rotate_operation.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/22 14:17:58 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/05/07 18:41:30 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

void	ra(t_stack **stack_a, t_counter *counter)
{
	rotate(stack_a);
	(counter->ops).ra++;
	if (counter->print == 1)
		ft_printf("%s\n", "ra");
}

void	rb(t_stack **stack_b, t_counter *counter)
{
	rotate(stack_b);
	(counter->ops).rb++;
	if (counter->print == 1)
		ft_printf("%s\n", "rb");
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_counter *counter)
{
	rotate(stack_a);
	rotate(stack_b);
	(counter->ops).rr++;
	if (counter->print == 1)
		ft_printf("%s\n", "rr");
}
