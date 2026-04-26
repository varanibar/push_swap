/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/18 13:51:14 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/26 12:14:52 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current != NULL)
	{
		ft_printf("%d\n", current->val);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_flags	*flags;

	stack_a = NULL;
	flags = NULL;
	if (!ft_check_input(argc, argv, &stack_a, &flags))
	{
		ft_free_stack(&stack_a);
		free(flags);
		return (ft_printf("Error\n"), 0);
	}
	print_stack(stack_a);
	ft_free_stack(&stack_a);
	free(flags);
	return (0);
}
