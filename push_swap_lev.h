/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_lev.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lekoelma <lekoelma@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/16 15:01:02 by lekoelma      #+#    #+#                 */
/*   Updated: 2026/04/18 15:19:41 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_LEV_H
# define PUSH_SWAP_LEV_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	int				val;
	struct s_node	*next;
}					t_node;

void	push(t_node **stack, int val);

#endif
