/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:07:31 by aralves-          #+#    #+#             */
/*   Updated: 2024/04/17 13:16:51 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*dest1;
	void	*src1;

	if (dest < src)
		dest = ft_memcpy(dest, src, n);
	else
	{
		dest1 = (void *)dest + n - 1;
		src1 = (void *)src + n - 1;
		while (n--)
			*(char *)dest1-- = *(char *)src1--;
	}
	return (dest);
}

/* int main()
{
	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest;

	dest = src + 1;
	printf("%s\n", dest);
	printf("%s\n", (char *)ft_memmove(dest, src, 8));
	write(1, dest, 22);
	printf("%s\n", (char *)memmove(dest, src, 8));
	write(1, dest, 22);
} */