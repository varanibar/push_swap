/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chunk_sort_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/04 15:59:56 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/05/05 12:43:04 by lekoelma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	n;

	n = 1;
	while (n * n <= nb)
	{
		if (n * n == nb)
			return (n);
		n++;
	}
	return (n - 1);
}

// finds the node with the lowest value in the stack
// that did not get a rank yet. Rank is set to -1 by default (in add_to_stack)

static t_stack	*ft_find_min(t_stack *stack)
{
	t_stack	*current;
	t_stack	*min;

	while (stack != NULL && stack->rank != -1)
		stack = stack->next;
	current = stack;
	min = stack;
	while (current != NULL)
	{
		if (current->val < min->val && current->rank == -1)
			min = current;
		current = current->next;
	}
	return (min);
}

//returns the index of the highest number in stack_b

int	ft_max_index(t_stack *stack_b)
{
	t_stack	*current;
	t_stack	*max;
	int		max_pos;
	int		counter;

	current = stack_b;
	max = stack_b;
	max_pos = 0;
	counter = 0;
	while (current != NULL)
	{
		if (current->val > max->val)
		{
			max = current;
			max_pos = counter;
		}
		counter++;
		current = current->next;
	}
	return (max_pos);
}

// Goes trough the entire stack and sets the minimal value to i (rank).

void	ft_assign_rank(t_stack **stack)
{
	int		size;
	t_stack	*min;
	int		i;

	size = ft_stack_size(*stack);
	i = 0;
	while (i < size)
	{
		min = ft_find_min(*stack);
		min->rank = i;
		i++;
	}
}

// returns the index of the first node that is within the chunk

int	ft_find_chunk_index(t_stack **stack_a, int chunk_min, int chunk_max)
{
	t_stack	*current;
	int		index;

	index = 0;
	current = *stack_a;
	while (current != NULL)
	{
		if (!(current->rank >= chunk_min && current->rank <= chunk_max))
		{
			current = current->next;
			index++;
		}
		else
			return (index);
	}
	return (-1);
}
