/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 08:17:51 by aralves-          #+#    #+#             */
/*   Updated: 2024/05/19 23:45:24 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_flags(unsigned long long n, t_flags *flags)
{
	int	i;

	i = 0;
	plus_space(flags);
	if (flags->minimum_width)
	{
		if (flags->precision)
			i += ft_minwidth(n, flags);
		else
			i += print_minwidth(flags);
	}
	if (flags->neg)
		i += ft_putchar('-', 0);
	if (flags->space_before_positive || flags->plus_sign)
	{
		if (flags->space_before_positive)
			i += ft_putchar(' ', 0);
		else
			i += ft_putchar('+', 0);
	}
	if (flags->precision)
		i += print_precision(n, flags);
	else if (flags->zero_padding)
		i += print_zero(n, flags);
	return (i);
}

int	ft_check_precision(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	flags->entered = 1;
	if (s[i] == '.')
	{
		i++;
		if (flags->zero_padding)
		{
			flags->minimum_width = flags->zero_padding;
			flags->zero_padding = 0;
		}
		while (s[i] == '0')
			i++;
		if (ft_isdigit(s[i]))
		{
			flags->precision = ft_atoi(s + i);
			i += ft_number_size(flags->precision);
		}
	}
	return (i);
}

int	ft_check_left(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	if (s[i] == '-')
	{
		i++;
		if (flags->minimum_width && ft_isdigit(s[i]))
		{
			flags->minus = 0;
			while (ft_isdigit(s[i]))
				i++;
			return (i);
		}
		while (s[i] == '0')
			i++;
		if (ft_isdigit(s[i]))
		{
			flags->minus = ft_atoi(s + i);
			i += ft_number_size(flags->minus);
		}
	}
	return (i);
}

int	ft_check_padding(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	if (s[i] == '0')
	{
		i++;
		while (s[i] == '0')
		{
			flags->zero_padding = 0;
			i++;
		}
		if (ft_isdigit(s[i]))
		{
			flags->zero_padding = ft_atoi(s + i);
			i += ft_number_size(flags->zero_padding);
		}
	}
	return (i);
}

int	ft_check_bonus(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	i += ft_plus_space_hexa(s, flags);
	if (ft_isdigit(s[i]) && s[i] != '0')
	{
		flags->minimum_width = ft_atoi(s);
		while (ft_isdigit(s[i]) && flags->minimum_width != 0)
			i++;
	}
	while (s[i] == '-' || s[i] == '.' || s[i] == '0')
	{
		if (s[i] == '0')
			i += ft_check_padding(s + i, flags);
		else if (s[i] == '-')
			i += ft_check_left(s + i, flags);
		else if (s[i] == '.')
			i += ft_check_precision(s + i, flags);
	}
	return (i);
}
