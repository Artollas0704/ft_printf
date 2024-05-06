/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:10:01 by aralves-          #+#    #+#             */
/*   Updated: 2024/05/06 16:06:00 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_flags
{
	int				plus_sign;
	int				space_before_positive;
	int				hexa;
	int				minimum_width;
	int				precision;
	int				zero_padding;
	int				left;
	int				size;
	long			numberdi;
	unsigned long	numberxp;
	unsigned int	numberu;
	int				di;
	int				xp;
	int				u;
}	t_flags;

int		ft_printf(const char *s, ...);
int		ft_putchar(char c, t_flags *flags);
int		ft_check(const char *s, va_list args, t_flags *flags);
int		ft_putstr(char *s, t_flags *flags);
int		ft_putunbr(unsigned int n, t_flags *flags);
int		ft_putnbr(int n, t_flags *flags);
int		ft_puthex(unsigned long n, int value, int flag, t_flags *flags);
int		ft_putptr(unsigned long n);
int		ft_check_bonus(char *s, t_flags *flags, va_list args);
int		ft_check_padding(char *s, t_flags *flags);
int		ft_check_left(char *s, t_flags *flags);
int		ft_check_precision(char *s, t_flags *flags, va_list args);
int		ft_number_size(long n);
int		ft_check_rest(char *s);
int		ft_printflags_putnbr(long long n, t_flags *flags);
int		ft_printflags(int start, int end, char c);
int		ft_check_real_size(int n, t_flags *flags);
int		ft_printflags_unsigned_hexa(unsigned int n, t_flags *flags);
int		ft_number_size_u(unsigned int n);
int		ft_left_justify(t_flags *flags);
int		ft_checkplusminus(t_flags *flags, int n);
void	ft_flagsreset(t_flags *flags);

#endif