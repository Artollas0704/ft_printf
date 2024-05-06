/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 04:42:24 by aralves-          #+#    #+#             */
/*   Updated: 2024/05/06 16:03:16 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_rest(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '%')
		i++;
	return (i);
}

int	ft_check_real_size(int n, t_flags *flags)
{
	int	num;
	int	i;

	i = 0;
	num = flags->precision;
	while (ft_number_size(n) < num)
	{
		i++;
		num--;
	}
	return (i);
}

int	ft_printflags(int start, int end, char c)
{
	int	i;

	i = 0;
	while (start < end)
	{
		i += ft_putchar(c, 0);
		start++;
	}
	return (i);
}

int	ft_printflags_putnbr(long long n, t_flags *flags)
{
	long long	num;

	num = n;
	if (n < 0)
		num = n * -1;
	if (flags->minimum_width)
	{
		if (flags->precision)
			flags->size += ft_check_real_size(num, flags) + ft_number_size(n);
		else
			flags->size += ft_number_size(n);
		if (flags->minimum_width == flags->size)
			flags->size--;
		return (ft_printflags(flags->size, flags->minimum_width, ' '));
		flags->minimum_width = 0;
	}
	else if (flags->precision || flags->zero_padding)
	{
		if (flags->precision)
			return (ft_printflags(ft_number_size(num), flags->precision, '0'));
		else if (flags->zero_padding)
			return (ft_printflags(ft_number_size(n), flags->zero_padding, '0'));
		flags->precision = 0;
		flags->zero_padding = 0;
	}
	return (0);
}
