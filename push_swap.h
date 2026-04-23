/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 12:26:26 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/23 17:17:29 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}	t_stack;

typedef enum e_method
{
	NONE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTATIVE
}	t_method;

typedef struct s_flags
{
	bool		bench;
	t_method	method;
}	t_flags;

//validating input
int					ft_check_input(int argc, char **argv, t_stack **stack, t_flags **flags);
void				ft_free_stack(t_stack **stack);
int					ft_flag_strcmp(char *s1, char *s2);
char				*ft_get_flag_type(int j);
int					ft_flag_checker(char **input, int n, t_flags *flags);
int					ft_create_t_flag(t_flags **flags);

//Defining the algorithm to use
double				ft_compute_disorder(t_stack *stack);

//adding nodes to stack
int					ft_add_to_stack(t_stack **stack, int val);

//operations
void				del_top(t_stack **stack);
void				swap(t_stack **stack);
void				rotate(t_stack **stack);
void				reverse_rotate(t_stack **stack);

//printing stack
void				print_stack(t_stack *stack);

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

// printing stack DELETE THIS BEFORE SUBMITTINGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
void				print_stack(t_stack *stack);

// sorting functions
void				ft_selection_sort(t_stack **stack_a, t_stack **stack_b);

//helper functions (we should fetch them from libft)
// int					ft_atoi(const char *nptr);

#endif
