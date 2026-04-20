/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekoelma <lekoelma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:04:01 by lekoelma          #+#    #+#             */
/*   Updated: 2026/04/20 17:27:32 by lekoelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_to_stack(t_list **stack, int val)
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
