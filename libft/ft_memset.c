/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:46:52 by aralves-          #+#    #+#             */
/*   Updated: 2024/04/17 12:41:06 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
	{
		*((char *)s) = c;
		s++;
	}
	while (i > 0)
	{
		s--;
		i--;
	}
	return (s);
}

/* int main()
{
	void	*mem;
	int		arg;

	if (!(mem = malloc(sizeof(*mem) * 15)))
		return (0);
	memset(mem, 'j', 15);
	mem = ft_memset(mem, 'c', 5);
	printf("ft\n");
	write(1, mem, 15);
	write(1, "\n", 1);
	mem = memset(mem, 'c', 5);
	printf("og\n");
	write(1, mem, 15);
} */
