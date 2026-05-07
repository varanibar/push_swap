/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 12:26:26 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/07 11:56:21 by varaniba      ########   odam.nl         */
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

typedef struct s_counter
{
	bool		print;
	t_ops		ops;
}	t_counter;

typedef struct s_bounds
{
	int				min;
	int				max;
	int				size;
}	t_bounds;

//initializing variables
void				ft_init_variables(t_stack **stack_a, t_flags *flags, t_counter *counter);

//validating input
int					ft_check_input(int argc, char **argv, t_stack **stack, t_flags *flags);
void				ft_free_array(char **input);
int					ft_flag_strcmp(char *s1, char *s2);
char				*ft_get_flag_type(int j);
int					ft_flag_checker(char **input, int n, t_flags *flags);

//Defining the algorithm to use
float				ft_compute_disorder(t_stack *current);

//stack operations
int					ft_add_to_stack(t_stack **stack, int val);
void				ft_free_stack(t_stack **stack);
int					ft_stack_size(t_stack *stack);
int					ft_is_stack_sorted(t_stack **stack_a);
void				ft_assign_rank(t_stack **stack);

// operations
void				sa(t_stack **stack_a, t_counter *counter);
void				sb(t_stack **stack_b, t_counter *counter);
void				ss(t_stack **stack_a, t_stack **stack_b, t_counter *counter);
void				pa(t_stack **stack_a, t_stack **stack_b, t_counter *counter);
void				pb(t_stack **stack_b, t_stack **stack_a, t_counter *counter);
void				ra(t_stack **stack_a, t_counter *counter);
void				rb(t_stack **stack_b, t_counter *counter);
void				rr(t_stack **stack_a, t_stack **stack_b, t_counter *counter);
void				rra(t_stack **stack_a, t_counter *counter);
void				rrb(t_stack **stack_b, t_counter *counter);
void				rrr(t_stack **stack_a, t_stack **stack_b, t_counter *counter);

// printing stack DELETE THIS BEFORE SUBMITTINGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
void				print_stack(t_stack *stack);
void				print_rank(t_stack *stack);

//benchmark mode
void				ft_benchmark(t_flags *flags, t_counter *counter, float disorder);
// sorting functions
void				ft_selection_sort(t_stack **stack_a, t_counter *counter);
void				ft_chunk_sort(t_stack **stack_a, t_counter *counter);
void				ft_radix_sort(t_stack **stack_a, t_counter *counter);

// chunk sort utils
int					ft_sqrt(int nb);
int					ft_max_index(t_stack *stack_b);
int					ft_find_chunk_index(t_stack **stack_a, int chunk_min,
						int chunk_max);

#endif
