/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init_t_flags.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/04 09:48:28 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/04 09:49:06 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	ft_init_t_flags(t_flags **flags)
{
	*flags = malloc(sizeof(t_flags));
	if (!*flags)
		return (0);
	(*flags)->bench = 0;
	(*flags)->method = 0;
	return (1);
}
