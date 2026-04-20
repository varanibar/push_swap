/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekoelma <lekoelma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:51:39 by lekoelma          #+#    #+#             */
/*   Updated: 2026/04/20 11:56:02 by lekoelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9' || c == '-')
		return (1);
	else
		return (0);
}

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

void	push(t_list **stack, int val)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->val = val;
	new->next = *stack;
	*stack = new;
}

void	del_top(t_list **stack)
{
	t_list	*current;
	t_list	*new_top;

	if (*stack == NULL)
		return ;
	current = *stack;
	new_top = current->next;
	free(current);
	*stack = new_top;
}

void	print_stack(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current != NULL)
	{
		printf("%d\n", current->val);
		current = current->next;
	}
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

int check_input(char *input)
{
	int i;
	i = 0;

	while (input[i])
	{
		if (!(ft_isdigit(input[i])))
			return(0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list *stack_a;
	int input[argc];
	int i;
	int j;
	i = 0;
	j = 1;
	stack_a = NULL;
	if (argc == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (argv[j])
	{
		if (!check_input(argv[j]))
		{
			printf("%s\n", "Error");
			return(0);
		}
		j++;
	}
	j = argc - 1;
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