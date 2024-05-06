/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:06:44 by aralves-          #+#    #+#             */
/*   Updated: 2024/04/16 17:50:08 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;

	i = 0;
	dst_len = ft_strlen((const char *)dst);
	if (dst_len > size || size == 0)
		return (ft_strlen(src) + size);
	dst += dst_len;
	while (i + dst_len < size - 1 && src[i])
		dst++[0] = (char)src[i++];
	dst[0] = 0;
	return (dst_len + ft_strlen(src));
}

/* int main()
{
	char *dst= malloc(20 * sizeof(char));	
	size_t size;
	ft_strlcat(dst, "Hello", 6);
	size = ft_strlcat(dst, "Hello World ", 20);
	printf("%s, %zu", dst, size);
} */