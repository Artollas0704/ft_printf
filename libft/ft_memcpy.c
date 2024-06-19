/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:03:12 by aralves-          #+#    #+#             */
/*   Updated: 2024/06/19 18:17:59 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (!src)
		return (dest);
	while (++i < n)
		*(char *)dest++ = *(char *)src++;
	while (i-- > 0)
	{
		dest--;
		src--;
	}
	return (dest);
}

/* int main()
{
	char *str = (char *)malloc(2 * sizeof(char));
	str = ft_memcpy(str, "55", 2);
	printf("%s", str);
} */