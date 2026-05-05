/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_t_flags.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/04 09:48:28 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/05 17:29:03 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_init_t_flags(t_flags *flags)
{
	flags->bench = 0;
	flags->method = NONE;
}
