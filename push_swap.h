/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 12:26:26 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/23 17:14:51 by lekoelma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}					t_stack;

// validating input
int					ft_check_input(int argc, char **argv);
void				ft_free_stack(t_stack **stack);

// Defining the algorithm to use
double				ft_compute_disorder(t_stack *stack);

// adding nodes to stack
int					ft_add_to_stack(t_stack **stack, int val);

// operations
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_b, t_stack **stack_a);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

// printing stack
void				print_stack(t_stack *stack);

// sorting functions
void				ft_selection_sort(t_stack **stack_a, t_stack **stack_b);

// helper functions (we should fetch them from libft)
// int					ft_atoi(const char *nptr);

#endif
