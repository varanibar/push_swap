/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/18 13:51:14 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/26 18:34:55 by varaniba      ########   odam.nl         */
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
	// ft_printf("Stack_a\n");
	// print_stack(stack_a);

	disorder = ft_compute_disorder(stack_a);
	if (!disorder)
		return (ft_free_stack(&stack_a), free(flags), 0);


	if (flags->method == 1)
		ft_selection_sort(&stack_a, &stack_b);
	// else if (flags->method == 2)
	// 	ft_selection_sort(&stack_a, &stack_b);
	else
		ft_selection_sort(&stack_a, &stack_b);


	if (flags->bench == 1)
		write(2,"[bench]",7);

	return (ft_free_stack(&stack_a), free(flags), 0);
}

/*
** TO DO :
** 	-ft_compute_disorder needs to return a decimal number, i changed it to int bc ft_printf cant print it for now
** 	-ft_printf: add a specifier to print decimal numbers
** 	-create ft_fprintf: this one would allow us to print to any
** 	 file descriptor (like STDERR for the --bench flag)
** 	-modify operations so each one has a counter that will be used when using --bench
**
*/
