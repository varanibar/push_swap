/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 12:26:26 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/22 10:18:33 by varaniba      ########   odam.nl         */
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

//validating input
int					ft_check_input(int argc, char **argv);

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
