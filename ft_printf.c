/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:09:29 by aralves-          #+#    #+#             */
/*   Updated: 2024/05/21 16:52:19 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c, t_flags *flags)
{
	int	i;

	i = 0;
	if (!flags)
	{
		write(1, &c, 1);
		return (1);
	}
	flags->size++;
	if (flags->minimum_width)
		i += print_minwidth(flags);
	i += write(1, &c, 1);
	return (i);
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

int	ft_puthex(unsigned long n, int value, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->entered && !flags->precision && n == 0)
	{
		i += print_minwidth(flags);
		return (i);
	}
	if (!flags->size)
		i += handle_hexa(flags, n, value);
	ft_flagsreset(flags);
	if (n > 15)
		i += ft_puthex(n / 16, value, flags);
	if (n % 16 < 10)
		i += ft_putchar(n % 16 + '0', 0);
	else if (value == 0)
		i += ft_putchar(n % 16 - 10 + 'a', 0);
	else
		i += ft_putchar(n % 16 - 10 + 'A', 0);
	return (i);
}

int	ft_putptr(unsigned long n, t_flags *flags)
{
	int	i;

	i = 0;
	if (!n)
	{
		i += ft_putstr("(nil)", flags);
		return (i);
	}
	flags->hexa = 1;
	i += ft_puthex(n, 0, flags);
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
	ft_printf("%-20carigatou", 'w');
}  */