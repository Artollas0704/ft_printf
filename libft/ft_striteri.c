/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:13:08 by aralves-          #+#    #+#             */
/*   Updated: 2024/04/17 16:22:54 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* void	test_f (unsigned int c, char *b)
{
	if ((unsigned char )c != 0)
			*b = 'a';
	else
		*b = 'b';
}

int main()
{
	char str[] = "Hello World";
	ft_striteri(str, &test_f);
	printf("%s", str);
} */