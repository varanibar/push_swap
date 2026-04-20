/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekoelma <lekoelma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:35:33 by lekoelma          #+#    #+#             */
/*   Updated: 2026/04/20 17:24:17 by lekoelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void 	push(t_list **dest, t_list **src)
{
	t_list *tmp;
	if (!*src)
		return;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = NULL;
	ft_lstadd_front(dest, *src);
}

void	swap(t_list **stack)
{
	t_list	*current;
	t_list	*next_node;

	current = *stack;
	if (*stack == NULL || current->next == NULL)
		return ;
	next_node = current->next;
	current->next = next_node->next;
	next_node->next = current;
	*stack = next_node;
}

void	rotate(t_list **stack)
{
	t_list	*current;
	t_list	*top;
	t_list	*second;

	current = *stack;
	top = *stack;
	if (*stack == NULL || current->next == NULL)
		return ;
	second = current->next;
	while (current->next != NULL)
		current = current->next;
	current->next = top;
	top->next = NULL;
	*stack = second;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*current;
	t_list	*top;
	t_list	*prev;

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
