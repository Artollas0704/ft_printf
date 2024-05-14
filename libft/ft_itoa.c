/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:11:55 by aralves-          #+#    #+#             */
/*   Updated: 2024/05/07 18:12:19 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	toalloc(long num)
{
	unsigned int	size;

	size = 0;
	if (num == 0)
		return (1);
	else if (num < 0)
	{
		num *= -1;
		size++;
	}
	if (num > 0)
	{
		while (num > 0)
		{
			num = num / 10;
			size++;
		}
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long			num;
	int				size;
	char			*str;

	num = n;
	size = toalloc(num);
	str = ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (0);
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	size--;
	while (size >= 0 && str[size] != '-')
	{
		str[size--] = (num % 10) + 48;
		num = num / 10;
	}
	return (str);
}

/* int main()
{
	printf("%s", ft_itoa(0));
} */