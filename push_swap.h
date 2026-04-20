/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/16 15:01:02 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/04/20 17:39:42 by lekoelma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				val;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *nptr);
int					add_to_stack(t_list **stack, int val);
void				del_top(t_list **stack);
void				print_stack(t_list *stack);
void				swap(t_list **stack);
void				rotate(t_list **stack);
void				reverse_rotate(t_list **stack);
int					check_input(char *input);
int					check_dup(char **input);
double				compute_disorder(t_list *stack);
int					ft_lstsize(t_list *lst);

#endif