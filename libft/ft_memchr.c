/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:06:12 by aralves-          #+#    #+#             */
/*   Updated: 2024/04/18 19:18:25 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (!s)
		return (0);
	while (n > 0)
	{
		if (*(unsigned char *)s == (unsigned char )c)
			return ((void *)s);
		s++;
		n--;
	}
	return (0);
}

/* int main()
{
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};

	printf("%s", (char *)ft_memchr(tab, -1, 7));
	printf("%s", (char *)memchr(tab, -1, 7));
} */