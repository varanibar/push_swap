/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/18 13:51:14 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/26 15:07:59 by varaniba      ########   odam.nl         */
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
	t_stack	*stack_b = NULL;
	t_flags	*flags;
	int		disorder;

	stack_a = NULL;
	flags = NULL;
	if (!ft_check_input(argc, argv, &stack_a, &flags))
	{
		ft_free_stack(&stack_a);
		free(flags);
		return (ft_printf("Error\n"), 0);
	}
	ft_printf("Stack_a\n");
	print_stack(stack_a);
	disorder = ft_compute_disorder(stack_a);
	ft_printf("disorder metric = %d\n", disorder);
	ft_printf("%s\n", "operations used:");
	ft_selection_sort(&stack_a, &stack_b);
	ft_printf("%s\n", "stack_a:");
	print_stack(stack_a);
	print_stack(stack_b);
	ft_free_stack(&stack_a);
	free(flags);
	return (0);
}

