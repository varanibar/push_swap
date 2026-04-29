/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/18 13:51:14 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/29 17:21:56 by varaniba      ########   odam.nl         */
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

int ft_create_t_counter(t_ops **counter)
{
	*counter = malloc(sizeof(t_ops));
	if (!*counter)
		return (0);
	(*counter)->sa = 0;
	(*counter)->sb = 0;
	(*counter)->ss = 0;
	(*counter)->pa = 0;
	(*counter)->pb = 0;
	(*counter)->ra = 0;
	(*counter)->rb = 0;
	(*counter)->rr = 0;
	(*counter)->rra = 0;
	(*counter)->rrb = 0;
	(*counter)->rrr = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_flags	*flags;
	t_ops	*counter;
	float	disorder;

	stack_a = NULL;
	stack_b = NULL;
	flags = NULL;
	counter = NULL;
	if (!ft_check_input(argc, argv, &stack_a, &flags))
	{
		ft_free_stack(&stack_a);
		free(flags);
		return (ft_printf("Error\n"), 0);
	}
	if (ft_stack_size(stack_a) == 1)
		return (ft_free_stack(&stack_a), free(flags), 0);
	disorder = ft_compute_disorder(stack_a);
	ft_printf("disorder = %.2f\n", disorder);
	if (!disorder || !ft_create_t_counter(&counter))
		return (ft_free_stack(&stack_a), free(flags), 0);
	if (flags->method == 1)
		ft_selection_sort(&stack_a, &stack_b, counter);
	// else if (flags->method == 2)
	// 	ft_selection_sort(&stack_a, &stack_b, &counter);
	else
		ft_selection_sort(&stack_a, &stack_b, counter);
	if (flags->bench == 1)
		write(2,"[bench]",7);
	return (ft_free_stack(&stack_a), free(flags), free(counter), 0);
}

/*
** TO DO :
** 	-create ft_fprintf: this one would allow us to print to any
** 	 file descriptor (like STDERR for the --bench flag)
** 	-modify operations so each one has a counter that will be used when using --bench
**
*/
