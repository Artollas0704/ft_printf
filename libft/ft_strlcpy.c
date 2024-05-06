/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:02:09 by aralves-          #+#    #+#             */
/*   Updated: 2024/04/16 18:28:24 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lensrc;

	lensrc = ft_strlen(src);
	i = -1;
	if (size == 0)
		return (lensrc);
	while (++i < size - 1 && *src)
		*(char *)dst++ = *(char *)src++;
	*dst = 0;
	return (lensrc);
}

/* int main()
{
	char *str = (char *)malloc(15 * sizeof(char));
	memset(str, 0, 15);
	memset(str, 'r', 6);
	ft_strlcpy(str, "lorem", 15);
	printf("%s", str);
} */