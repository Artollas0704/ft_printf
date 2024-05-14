/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags_unsigned_hexa_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:12:07 by aralves-          #+#    #+#             */
/*   Updated: 2024/05/14 16:40:16 by aralves-         ###   ########.fr       */
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
