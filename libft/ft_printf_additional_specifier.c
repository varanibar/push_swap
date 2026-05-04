/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_additional_specifier.c                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/29 14:42:01 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/29 16:36:10 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	offset(const char *format_str, int *i)
{
	if (*format_str == '.')
	{
		while (*format_str != 'f')
		{
			*i = *i + 1;
			format_str++;
		}
	}
}

int	get_precision(double *nbr, const char *specif, int *multiplier)
{
	int	precision;
	int	i;

	i = 0;
	precision = 0;
	if (*specif == 'f')
		precision = 6;
	else if (*specif == '.' && *(specif + 1) != 'f')
	{
		specif++;
		while (*specif >= '0' && *specif <= '9')
		{
			precision = precision * 10 + *specif - '0';
			specif++;
		}
		if (precision > 15)
			precision = 15;
	}
	while (precision - i++ > 0)
		*multiplier = *multiplier * 10;
	*nbr = *nbr + (0.5 / *multiplier);
	return (precision);
}

int	ft_print_float(double nbr, const char *specif)
{
	int	count;
	int	multiplier;
	int	precision;
	int	decimal_number;

	decimal_number = 0;
	multiplier = 1;
	count = 0;
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		nbr = -nbr;
	}
	precision = get_precision(&nbr, specif, &multiplier);
	count += ft_putnbr_b(nbr, "0123456789");
	if (precision > 0)
	{
		count += write(1, ".", 1);
		decimal_number = nbr * multiplier - (int)nbr * multiplier;
		count += ft_putnbr_b(decimal_number, "0123456789");
		if (decimal_number == 0)
			while (--precision > 0)
				count += write(1, "0", 1);
	}
	return (count);
}
