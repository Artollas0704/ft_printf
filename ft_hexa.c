/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:55:05 by aralves-          #+#    #+#             */
/*   Updated: 2024/06/19 18:39:28 by aralves-         ###   ########.fr       */
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

int	handle_str(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->entered && flags->precision < (int)ft_strlen(s))
		flags->size += flags->precision;
	else
		flags->size += ft_strlen(s);
	if (flags->minimum_width)
		i += print_minwidth(flags);
	if (flags->entered && flags->precision < (int)ft_strlen(s))
	{
		while (flags->precision && *s)
		{
			i += ft_putchar(*s, 0);
			flags->precision--;
			s++;
		}
	}
	else
		i += ft_putstr(s, 0);
	return (i);
}

int	lesszero(long num, t_flags *flags, int i)
{
	flags->space_before_positive = 0;
	flags->plus_sign = 0;
	num *= -1;
	flags->neg = 1;
	if (!flags->size)
		flags->size = ft_number_size(num);
	flags->size++;
	i += ft_check_flags(num, flags);
	return (i);
}
