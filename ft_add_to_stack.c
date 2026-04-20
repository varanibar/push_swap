/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_add_to_stack.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 14:14:58 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/20 18:15:31 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_add_to_stack(t_list **stack, int val)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return(-1);
	new_node->val = val;
	new_node->next = *stack;
	*stack = new_node;
	return(1);
}
