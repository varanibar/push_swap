/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_rank.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/04 10:52:59 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/04 10:53:20 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	print_rank(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current != NULL)
	{
		ft_printf("%d\n", current->rank);
		current = current->next;
	}
}
