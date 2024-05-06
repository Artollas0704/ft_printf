/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:49:33 by aralves-          #+#    #+#             */
/*   Updated: 2024/04/18 19:24:04 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	s += i;
	while (i > 0)
	{
		if (s[0] == (char)c)
			return ((char *)s);
		s--;
		i--;
	}
	if (s[0] == (char)c)
		return ((char *)s);
	return (0);
}
