/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 12:26:26 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/21 17:52:34 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				val;
	struct s_list	*next;
}					t_list;

//validating input
int					ft_check_input(int argc, char **argv);

//Defining the algorithm to use
double				ft_compute_disorder(t_list *stack);

//adding nodes to stack
int					ft_add_to_stack(t_list **stack, int val);

//operations
void				del_top(t_list **stack);
void				swap(t_list **stack);
void				rotate(t_list **stack);
void				reverse_rotate(t_list **stack);

//printing stack
void				print_stack(t_list *stack);

//helper functions (we should fetch them from libft)
int					ft_atoi(const char *nptr);
int					ft_lstsize(t_list *lst);

#endif
