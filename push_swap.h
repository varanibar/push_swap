/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 12:26:26 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/01 16:46:41 by varaniba      ########   odam.nl         */
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
	int				rank;
	struct s_stack	*next;
}	t_stack;

typedef enum e_method
{
	NONE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_method;

typedef struct s_flags
{
	bool		bench;
	t_method	method;
}	t_flags;

typedef struct s_ops
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}	t_ops;

//validating input
int					ft_check_input(int argc, char **argv, t_stack **stack, t_flags **flags);
int					ft_flag_strcmp(char *s1, char *s2);
char				*ft_get_flag_type(int j);
int					ft_flag_checker(char **input, int n, t_flags *flags);
int					ft_create_t_flag(t_flags **flags);

//Defining the algorithm to use
float				ft_compute_disorder(t_stack *current);

//adding nodes to stack
int					ft_add_to_stack(t_stack **stack, int val);
void				ft_free_stack(t_stack **stack);
int					ft_stack_size(t_stack *stack);

// operations
void				sa(t_stack **stack_a, t_ops *counter);
void				sb(t_stack **stack_b, t_ops *counter);
void				ss(t_stack **stack_a, t_stack **stack_b, t_ops *counter);
void				pa(t_stack **stack_a, t_stack **stack_b, t_ops *counter);
void				pb(t_stack **stack_b, t_stack **stack_a, t_ops *counter);
void				ra(t_stack **stack_a, t_ops *counter);
void				rb(t_stack **stack_b, t_ops *counter);
void				rr(t_stack **stack_a, t_stack **stack_b, t_ops *counter);
void				rra(t_stack **stack_a, t_ops *counter);
void				rrb(t_stack **stack_b, t_ops *counter);
void				rrr(t_stack **stack_a, t_stack **stack_b, t_ops *counter);

// printing stack DELETE THIS BEFORE SUBMITTINGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
void				print_stack(t_stack *stack);

// sorting functions
void				ft_selection_sort(t_stack **stack_a, t_stack **stack_b, t_ops *counter);

//helper functions (we should fetch them from libft)
// int					ft_atoi(const char *nptr);

#endif
