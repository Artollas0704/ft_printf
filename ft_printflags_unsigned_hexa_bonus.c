/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags_unsigned_hexa_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:12:07 by aralves-          #+#    #+#             */
/*   Updated: 2024/05/20 17:07:51 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_left_justify(t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->minus)
	{
		while (flags->minus > flags->size)
		{
			i += ft_putchar(' ', 0);
			flags->minus--;
		}
	}
	return (i);
}

int	ft_number_size(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_flagsreset(t_flags *flags)
{
	flags->plus_sign = 0;
	flags->space_before_positive = 0;
	flags->precision = 0;
	flags->zero_padding = 0;
	flags->minimum_width = 0;
	flags->neg = 0;
	flags->hexa = 0;
}

int	handle_hexa(t_flags *flags, unsigned long n, int value)
{
	int	i;

	i = 0;
	if (!flags->size)
		flags->size += number_len_hexa(n);
	if (flags->hexa && n)
		flags->size += 2;
	i += hexa_min_width(flags, n);
	if (flags->hexa && value && n)
		i += ft_putstr("0X", 0);
	else if (flags->hexa && !value && n)
		i += ft_putstr("0x", 0);
	if (flags->precision > number_len_hexa(n))
	{
		while (flags->precision > number_len_hexa(n))
		{
			i += ft_putchar('0', 0);
			flags->precision--;
			flags->size++;
		}
	}
	else if (flags->zero_padding)
		i += zero_padding_hexa(flags, n);
	return (i);
}

int	number_len_hexa(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}
