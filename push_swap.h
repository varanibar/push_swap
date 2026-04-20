/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/20 12:26:26 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/20 15:58:14 by varaniba      ########   odam.nl         */
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

int		new_node(t_list **stack, int val);
void	del_top(t_list **stack);
void	print_stack(t_list *stack);
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
double	compute_disorder(t_list *stack);

#endif
