/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:10:01 by aralves-          #+#    #+#             */
/*   Updated: 2024/05/19 23:58:11 by aralves-         ###   ########.fr       */
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
	int					plus_sign;
	int					space_before_positive;
	int					hexa;
	int					minimum_width;
	int					precision;
	int					zero_padding;
	int					minus;
	int					size;
	int					temp_size;
	int					neg;
	int					entered;
}	t_flags;

int		ft_printf(const char *s, ...);
int		ft_putchar(char c, t_flags *flags);
int		ft_check(const char *s, va_list args, t_flags *flags);
int		ft_putstr(char *s, t_flags *flags);
int		ft_putunbr(unsigned int n, t_flags *flags);
int		ft_putnbr(int n, t_flags *flags);
int		ft_puthex(unsigned long n, int value, t_flags *flags);
int		ft_putptr(unsigned long n);
int		ft_check_bonus(char *s, t_flags *flags);
int		ft_check_padding(char *s, t_flags *flags);
int		ft_check_left(char *s, t_flags *flags);
int		ft_check_precision(char *s, t_flags *flags);
int		ft_number_size(unsigned long long n);
int		ft_check_rest(char *s);
int		ft_left_justify(t_flags *flags);
int		ft_checkplusminus(t_flags *flags, int n);
void	ft_flagsreset(t_flags *flags);
int		ft_check_flags(unsigned long long n, t_flags *flags);
int		ft_minwidth(unsigned long long n, t_flags *flags);
int		print_minwidth(t_flags *flags);
int		print_precision(unsigned long long n, t_flags *flags);
int		print_zero(unsigned long long n, t_flags *flags);
void	plus_space(t_flags *flags);
int		ft_plus_space_hexa(char *s, t_flags *flags);
int		handle_hexa(t_flags *flags, unsigned long n, int value);
int		number_len_hexa(unsigned long n);
#endif