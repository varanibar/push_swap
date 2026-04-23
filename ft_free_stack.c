/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ps_lstclear.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/23 16:43:31 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/04/23 16:50:05 by lekoelma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free_stack(t_stack **stack)
{
	t_stack *next;
	
	while(*stack)
	{
		next = (*stack)->next;
		free (*stack);
		*stack = next;
	}
}