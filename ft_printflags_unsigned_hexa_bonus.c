/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags_unsigned_hexa_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:12:07 by aralves-          #+#    #+#             */
/*   Updated: 2024/05/06 16:19:29 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkplusminus(t_flags *flags, int n)
{
	if (n >= 0)
	{
		if (flags->plus_sign)
		{
			if (flags->zero_padding)
				flags->zero_padding--;
			if (flags->left)
				flags->left--;
			return (ft_putchar('+', 0));
		}
		else if (flags->space_before_positive)
		{
			if (flags->zero_padding)
				flags->zero_padding--;
			if (flags->left)
				flags->left--;
			return (ft_putchar(' ', 0));
		}
	}
	return (0);
}

int	ft_left_justify(t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->di && flags->left)
		i += ft_printflags(ft_number_size(flags->numberdi), flags->left, ' ');
	else if (flags->u != 0 && flags->left)
		i += ft_printflags(ft_number_size_u(flags->numberu), flags->left, ' ');
	else if (flags->size && flags->left)
		i += ft_printflags(flags->size, flags->left, ' ');
	return (i);
}

int	ft_number_size_u(unsigned int n)
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

int	ft_printflags_unsigned_hexa(unsigned int n, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->minimum_width)
	{
		if (flags->precision)
			flags->size += ft_check_real_size(n, flags) + ft_number_size_u(n);
		else
			flags->size += ft_number_size_u(n);
		if (flags->minimum_width == flags->size)
			flags->size--;
		i += ft_printflags(flags->size, flags->minimum_width, ' ');
		flags->minimum_width = 0;
	}
	else if (flags->precision || flags->zero_padding)
	{
		if (flags->precision)
			i += ft_printflags(ft_number_size_u(n), flags->precision, '0');
		else if (flags->zero_padding)
			i += ft_printflags(ft_number_size_u(n), flags->zero_padding, '0');
		flags->precision = 0;
		flags->zero_padding = 0;
	}
	return (i);
}

void	ft_flagsreset(t_flags *flags)
{
	flags->plus_sign = 0;
	flags->space_before_positive = 0;
	flags->precision = 0;
	flags->zero_padding = 0;
}
