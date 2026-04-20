/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_to_list.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 14:14:58 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/20 15:58:24 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	new_node(t_list **stack, int val)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return(-1);
	new->val = val;
	new->next = *stack;
	*stack = new;
	return (1);
}
