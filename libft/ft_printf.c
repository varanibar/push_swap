/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/09 14:31:51 by varaniba      #+#    #+#                 */
/*   Updated: 2026/04/29 14:55:47 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_format(const char *specif, va_list arg)
{
	int	count;

	count = 0;
	if (*specif == 'c')
		count += ft_print_char(va_arg(arg, int));
	else if (*specif == 's')
		count += ft_print_str(va_arg(arg, char *));
	else if (*specif == 'd' || *specif == 'i')
		count += ft_putnbr_b(va_arg(arg, int), "0123456789");
	else if (*specif == 'u' )
		count += ft_putnbr_b_uns(va_arg(arg, unsigned int), "0123456789");
	else if (*specif == 'x')
		count += ft_putnbr_b_uns(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (*specif == 'X')
		count += ft_putnbr_b_uns(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (*specif == 'p')
		count += ft_print_ptr(va_arg(arg, void *));
	else if (*specif == '%')
		count += write(1, "%", 1);
	else if (*specif == 'f' || *specif == '.')
		count += ft_print_float(va_arg(arg, double), specif);
	return (count);
}

static int	ft_check_format(const char *specif, int *counter)
{
	if (*specif == '\0' || !ft_strchr("csdiuxXp.f%", *specif))
	{
		*counter = -1;
		return (0);
	}
	if (*(specif++) == '.')
	{
		while (*specif >= '0' && *specif <= '9')
			specif++;
		if (*specif != 'f')
		{
			*counter = -1;
			return (0);
		}
	}
	return (1);
}

int	ft_printf(const char *format_str, ...)
{
	int		i;
	int		counter;
	va_list	arg;

	if (!format_str)
		return (-1);
	va_start(arg, format_str);
	i = 0;
	counter = 0;
	while (format_str[i])
	{
		if (format_str[i] == '%')
		{
			if (!ft_check_format(&format_str[i + 1], &counter))
				break ;
			counter += ft_print_format(&format_str[++i], arg);
			offset(&format_str[i], &i);
		}
		else
			counter += write(1, &format_str[i], 1);
		i++;
	}
	va_end(arg);
	return (counter);
}
