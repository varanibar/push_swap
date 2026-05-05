/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_e_printf_utils.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/14 13:55:04 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/05 10:50:33 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_e_putnbr_b(long long nbr, char *base)
{
	char		c;
	long long	len_base;
	int			index;
	int			count;

	count = 1;
	len_base = ft_strlen(base);
	if (nbr < 0)
	{
		write (2, "-", 1);
		nbr = -nbr;
		count ++;
	}
	if (nbr >= len_base)
		count += ft_e_putnbr_b(nbr / len_base, base);
	index = nbr % len_base;
	c = base[index];
	write (2, &c, 1);
	return (count);
}

int	ft_e_putnbr_b_u(unsigned long long nbr, char *base)
{
	char				c;
	unsigned long long	len_base;
	int					index;
	int					count;

	count = 1;
	len_base = ft_strlen(base);
	if (nbr >= len_base)
		count += ft_e_putnbr_b_u(nbr / len_base, base);
	index = nbr % len_base;
	c = base[index];
	write (2, &c, 1);
	return (count);
}

int	ft_e_print_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		count += write (2, "(nil)", 5);
	else
	{
		count += write (2, "0x", 2);
		count += ft_e_putnbr_b_u((uintptr_t)ptr, "0123456789abcdef");
	}
	return (count);
}

int	ft_e_print_char(int c)
{
	write (2, &c, 1);
	return (1);
}

int	ft_e_print_str(char *str)
{
	int	len;

	if (str == NULL)
	{
		write (2, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write (2, str, len);
	return (len);
}
