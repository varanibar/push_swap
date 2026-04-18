/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekoelma <lekoelma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:51:39 by lekoelma          #+#    #+#             */
/*   Updated: 2026/04/18 20:12:20 by lekoelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	sign;

	sign = 1;
	i = 0;
	nb = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}

void	push(t_node **stack, int val)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->val = val;
	new->next = *stack;
	*stack = new;
}

void	del_top(t_node **stack)
{
	t_node	*current;
	t_node	*new_top;

	if (*stack == NULL)
		return ;
	current = *stack;
	new_top = current->next;
	free(current);
	*stack = new_top;
}

void	print_stack(t_node *stack)
{
	t_node	*current;

	current = stack;
	while (current != NULL)
	{
		printf("%d\n", current->val);
		current = current->next;
	}
}

void	swap(t_node **stack)
{
	t_node	*current;
	t_node	*next_node;

	current = *stack;
	if (*stack == NULL || current->next == NULL)
		return ;
	next_node = current->next;
	current->next = next_node->next;
	next_node->next = current;
	*stack = next_node;
}

void	rotate(t_node **stack)
{
	t_node	*current;
	t_node	*top;
	t_node	*second;

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

void	reverse_rotate(t_node **stack)
{
	t_node	*current;
	t_node	*top;
	t_node	*prev;

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

int	main(int argc, char **argv)
{
	t_node *stack_a;
	int input[argc];
	int i;
	int j;
	i = 0;
	j = argc - 1;
	stack_a = NULL;
	if (argc == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}

	while (j > 0)
	{
		input[i] = ft_atoi(argv[j]);
		push(&stack_a, input[i]);
		i++;
		j--;
	}

	printf("%s\n", "Stack before operation:");

	print_stack(stack_a);
	rotate(&stack_a);
	printf("%s\n", "Stack after operation:");

	print_stack(stack_a);
	return (0);
}