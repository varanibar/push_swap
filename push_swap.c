/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/18 13:51:14 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/22 11:59:06 by lekoelma      ########   odam.nl         */
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

// int	main(int argc, char **argv)
// {
// 	// t_stack *stack_a;
// 	// t_stack *stack_b = NULL;
// 	// int input[argc];
// 	// int i;
// 	// int j;
// 	// i = 0;
// 	// j = 1;
// 	// stack_a = NULL;

// 	if (!ft_check_input(argc, argv))
// 		return(ft_printf("%s\n", "Error"), 0);


// 	// j = argc - 1;
// 	// while (j > 0)
// 	// {
// 	// 	input[i] = ft_atoi(argv[j]);
// 	// 	if (new_node(&stack_a, input[i]) == -1)
// 	// 		return(write(1, "error", 5));
// 	// 	i++;
// 	// 	j--;
// 	// }

// 	// double disorder;
// 	// disorder = ft_compute_disorder(stack_a);
// 	// printf("disorder = %f\n\n", disorder);

// 	// printf("%s\n", "Stack before operation:");
// 	// print_stack(stack_a);
// 	// // rotate(&stack_a);

// 	// // printf("%s\n", "Stack after operation:");

// 	// // print_stack(stack_a);

// 	// //moving first node to stack b
// 	// stack_b = stack_a;
// 	// stack_a = stack_a->next;
// 	// stack_b->next = NULL;
// 	// printf("%s\n", "Stack a:");
// 	// print_stack(stack_a);
// 	// printf("%s\n", "Stack b:");
// 	// print_stack(stack_b);
// 	return (0);
// }
