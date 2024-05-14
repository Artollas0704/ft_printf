/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:09:29 by aralves-          #+#    #+#             */
/*   Updated: 2024/05/14 16:46:32 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, t_flags *flags)
{
	if (flags && flags->minus)
		flags->size++;
	write(1, &c, 1);
	return (1);
}

void	init_flags(t_flags *flags)
{
	flags->plus_sign = 0;
	flags->space_before_positive = 0;
	flags->hexa = 0;
	flags->minimum_width = 0;
	flags->precision = 0;
	flags->zero_padding = 0;
	flags->minus = 0;
	flags->size = 0;
	flags->temp_size = 0;
	flags->neg = 0;
	flags->entered = 0;
}

int	ft_puthex(unsigned long n, int value, int flag, t_flags *flags)
{
	int	i;

	i = 0;
	if (flag == 1 && value == 0 && n > 0)
		i += ft_putstr("0x", 0);
	if (flag == 1 && value == 1 && n > 0)
		i += ft_putstr("0X", 0);
	if (n > 15)
		i += ft_puthex(n / 16, value, 0, flags);
	if (n % 16 < 10)
		i += ft_putchar(n % 16 + '0', 0);
	else if (value == 0)
		i += ft_putchar(n % 16 - 10 + 'a', 0);
	else
		i += ft_putchar(n % 16 - 10 + 'A', 0);
	return (i);
}

int	ft_putptr(unsigned long n)
{
	int	i;

	i = 0;
	if (!n)
	{
		i += ft_putstr("(nil)", 0);
		return (i);
	}
	i += ft_putstr("0x", 0);
	i += ft_puthex(n, 0, 0, 0);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	t_flags	flags;

	i = 0;
	va_start(args, s);
	if (!s)
		return (-1);
	while (*s)
	{
		init_flags(&flags);
		if (*s == '%')
		{
			s++;
			s += ft_check_bonus((char *)s, &flags);
			i += ft_check(s, args, &flags);
			i += ft_left_justify(&flags);
		}
		else
			i += ft_putchar(*s, 0);
		s++;
	}
	return (i);
}

/* int	main(void)
{
	int	i;

	i = 0;
	
	i = ft_printf("%+10.5d", 1);
	ft_printf("\n");
	ft_printf("Return: %d\n", i);
} */
/* int main()
{
	
} */