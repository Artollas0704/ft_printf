/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:55:05 by aralves-          #+#    #+#             */
/*   Updated: 2024/05/20 17:08:11 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexa_min_width(t_flags *flags, unsigned long n)
{
	int	i;

	i = 0;
	if (flags-> minimum_width)
	{
		if (flags->precision)
			i += print_min_width_hexa(flags, n);
		else
			i += print_minwidth(flags);
	}
	return (i);
}

int	print_min_width_hexa(t_flags *flags, unsigned long n)
{
	int	i;

	i = 0;
	flags->temp_size = flags->size;
	if (flags->precision > number_len_hexa(n))
	{
		flags->temp_size += flags->precision - number_len_hexa(n);
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

int	zero_padding_hexa(t_flags *flags, unsigned long n)
{
	int	i;

	i = 0;
	if (flags->hexa && n)
		flags->zero_padding -= 2;
	while (flags->zero_padding > number_len_hexa(n))
	{
		i += ft_putchar('0', 0);
		flags->zero_padding--;
		flags->size++;
	}
	return (i);
}
