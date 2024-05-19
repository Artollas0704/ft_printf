/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags_unsigned_hexa_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:12:07 by aralves-          #+#    #+#             */
/*   Updated: 2024/05/20 00:00:20 by aralves-         ###   ########.fr       */
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
}

int	handle_hexa(t_flags *flags, unsigned long n, int value)
{
	int	i;

	i = 0;
	if (!flags->size)
		flags->size += number_len_hexa(n);
	if (flags->hexa && value == 0 && n)
		flags->size += 2;
	else if (flags->hexa && value == 1 && n)
		flags->size += 2;
	// print min width, precision and zero padding!!
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
