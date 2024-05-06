/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 08:17:51 by aralves-          #+#    #+#             */
/*   Updated: 2024/04/27 12:29:05 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_number_size(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_check_precision(char *s, t_flags *flags, va_list args)
{
	int	i;

	i = 0;
	if (s[i] == '.')
	{
		i++;
		if (s[i] == '*')
		{
			flags->precision = va_arg(args, int);
			i++;
		}
		else if (ft_isdigit(s[i]))
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
	if (flags->minimum_width && ft_isdigit(s[i + 1]))
	{
		flags->left = 0;
		return (ft_atoi(s + i));
	}
	if (s[i] == '-')
	{
		i++;
		if (ft_isdigit(s[i]))
		{
			flags->left = ft_atoi(s + i);
			i += ft_number_size(flags->left);
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
		if (ft_isdigit(s[i]))
		{
			flags->zero_padding = ft_atoi(s + i);
			i += ft_number_size(flags->zero_padding);
		}
	}
	return (i);
}

int	ft_check_bonus(char *s, t_flags *flags, va_list args)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == ' ' || s[i] == '#')
	{
		flags->plus_sign = (s[i] == '+');
		flags->space_before_positive = (s[i] == ' ' && !flags->plus_sign);
		flags->hexa = (s[i] == '#');
		i++;
	}
	if (ft_isdigit(s[i]) && s[i] != '0')
	{
		flags->minimum_width = ft_atoi(s);
		while (ft_isdigit(s[i]) && flags->minimum_width != 0)
			i++;
	}
	if (s[i] == '-' || s[i] == '.' || s[i] == '0' || s[i] == '*')
	{
		if (s[i] == '0')
			i += ft_check_padding(s + i, flags);
		else if (s[i] == '-')
			i += ft_check_left(s + i, flags);
		else if (s[i] == '.')
			i += ft_check_precision(s + i, flags, args);
	}
	return (i);
}
