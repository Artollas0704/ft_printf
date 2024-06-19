/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:12:44 by aralves-          #+#    #+#             */
/*   Updated: 2024/06/19 18:42:03 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	if (!flags && s)
	{
		while (s[i])
			i += ft_putchar(s[i], 0);
		return (i);
	}
	else if (!flags && !s)
	{
		i += ft_putstr("(null)", 0);
		return (i);
	}
	else if (flags && flags->entered && !s && flags->precision < 6)
	{
		i += print_minwidth(flags);
		return (i);
	}
	else if (flags && s)
		i += handle_str(s, flags);
	else
		i += handle_str("(null)", flags);
	return (i);
}

int	ft_putunbr(unsigned int n, t_flags *flags)
{
	int		i;

	i = 0;
	flags->space_before_positive = 0;
	flags->plus_sign = 0;
	if (flags->entered && n == 0 && !flags->precision)
	{
		i += print_minwidth(flags);
		return (i);
	}
	if (!flags->size)
		flags->size = ft_number_size(n);
	i += ft_check_flags(n, flags);
	ft_flagsreset(flags);
	if (n > 9)
		i += ft_putunbr(n / 10, flags);
	i += ft_putchar(n % 10 + '0', 0);
	return (i);
}

int	ft_putnbr(int n, t_flags *flags)
{
	int		i;
	long	num;

	num = n;
	i = 0;
	if (flags->entered && num == 0 && !flags->precision)
	{
		i += print_minwidth(flags);
		return (i);
	}
	if (num < 0)
	{
		i += lesszero(num, flags, i);
		num *= -1;
	}
	flags->neg = 0;
	if (!flags->size)
		flags->size = ft_number_size(num);
	i += ft_check_flags(num, flags);
	ft_flagsreset(flags);
	if (num > 9)
		i += ft_putnbr(num / 10, flags);
	i += ft_putchar(num % 10 + '0', 0);
	return (i);
}

int	ft_check(const char *s, va_list args, t_flags *flags)
{
	int	i;

	i = 0;
	if (*s == 'c')
		i += ft_putchar(va_arg(args, int), flags);
	else if (*s == 's')
		i += ft_putstr(va_arg(args, char *), flags);
	else if (*s == 'd' || *s == 'i')
		i += ft_putnbr(va_arg(args, int), flags);
	else if (*s == 'u')
		i += ft_putunbr(va_arg(args, unsigned int), flags);
	else if (*s == 'x')
		i += ft_puthex(va_arg(args, unsigned int), 0, flags);
	else if (*s == 'X')
		i += ft_puthex(va_arg(args, unsigned int), 1, flags);
	else if (*s == 'p')
		i += ft_putptr(va_arg(args, unsigned long), flags);
	else if (*s == '%')
		i += ft_putchar('%', flags);
	return (i);
}
