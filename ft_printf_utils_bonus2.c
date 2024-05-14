/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 04:42:24 by aralves-          #+#    #+#             */
/*   Updated: 2024/05/14 16:47:13 by aralves-         ###   ########.fr       */
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

void	plus_space(t_flags *flags)
{
	if (flags->space_before_positive || flags->plus_sign)
		flags->size++;
}

int	ft_plus_space_hexa(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	if (s[i] == '+')
	{
		flags->plus_sign = (s[i] == '+');
		i++;
		while (s[i] == '+')
			i++;
	}
	else if (s[i] == ' ')
	{
		flags->space_before_positive = (s[i] == ' ');
		i++;
		while (s[i] == ' ')
			i++;
	}
	else if (s[i] == '#')
	{
		flags->hexa = (s[i] == '#');
		i++;
		while (s[i] == '#')
			i++;
	}
	return (i);
}
