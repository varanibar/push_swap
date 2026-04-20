/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 12:26:26 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/20 18:32:35 by varaniba      ########   odam.nl         */
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

int					ft_atoi(const char *nptr);
int					ft_add_to_stack(t_list **stack, int val);
void				del_top(t_list **stack);
void				print_stack(t_list *stack);
void				swap(t_list **stack);
void				rotate(t_list **stack);
void				reverse_rotate(t_list **stack);
int					ft_check_input(char *input);
double				compute_disorder(t_list *stack);
int					ft_lstsize(t_list *lst);
#endif
