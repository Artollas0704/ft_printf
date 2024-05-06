/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:09:29 by aralves-          #+#    #+#             */
/*   Updated: 2024/05/06 16:20:59 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, t_flags *flags)
{
	if (flags && flags->left)
		flags->size = 1;
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
	flags->left = 0;
	flags->size = -1;
	flags->numberdi = 0;
	flags->numberxp = 0;
	flags->numberu = 0;
	flags->di = 0;
	flags->xp = 0;
	flags->u = 0;
}

int	ft_puthex(unsigned long n, int value, int flag, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags && flags->minimum_width)
		i += ft_printflags_putnbr(n, flags);
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
			s += ft_check_bonus((char *)s, &flags, args);
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
	//ft_printf("%d\n", ft_printf("%-1s", 0));
	//printf("%-1s", printf("%+d", 9));
	ft_printf("%-1s", "");
} */