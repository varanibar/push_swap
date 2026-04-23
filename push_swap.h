/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 12:26:26 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/23 14:31:09 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

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

//helper functions (we should fetch them from libft)
// int					ft_atoi(const char *nptr);

#endif
