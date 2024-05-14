/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:38:46 by aralves-          #+#    #+#             */
/*   Updated: 2024/05/14 16:22:41 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_minwidth(unsigned long long n, t_flags *flags)
{
	int	i;

	i = 0;
	flags->temp_size = flags->size;
	if (flags->precision > ft_number_size(n))
	{
		flags->temp_size += flags->precision - ft_number_size(n);
		while (flags->minimum_width > flags->temp_size)
		{
			i += ft_putchar(' ', 0);
			flags->minimum_width--;
			flags->size++;
		}
	}
	else
		i += print_minwidth(flags);
	return (i);
}

int	print_minwidth(t_flags *flags)
{
	int	i;

	i = 0;
	flags->temp_size = flags->size;
	while (flags->minimum_width > flags->temp_size)
	{
		i += ft_putchar(' ', 0);
		flags->minimum_width--;
		flags->size++;
	}
	return (i);
}

int	print_precision(unsigned long long n, t_flags *flags)
{
	int	i;

	i = 0;
	while (flags->precision > ft_number_size(n))
	{
		i += ft_putchar('0', 0);
		flags->precision--;
		flags->size++;
	}
	return (i);
}

int	print_zero(unsigned long long n, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->space_before_positive || flags->plus_sign)
		flags->zero_padding--;
	if (flags->neg)
		flags->zero_padding--;
	while (flags->zero_padding > ft_number_size(n))
	{
		i += ft_putchar('0', 0);
		flags->zero_padding--;
		flags->size++;
	}
	return (i);
}
