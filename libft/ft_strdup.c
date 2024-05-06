/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:00:03 by aralves-          #+#    #+#             */
/*   Updated: 2024/04/17 13:06:15 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	if (!s)
		return (0);
	len = ft_strlen(s);
	dup = (char *)malloc(len * sizeof(char) + 1);
	if (!dup)
		return (0);
	ft_strlcpy(dup, s, len + 1);
	return (dup);
}

/* int main()
{
	printf("%s", ft_strdup("Hello World"));
} */