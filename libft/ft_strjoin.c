/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:28:20 by aralves-          #+#    #+#             */
/*   Updated: 2024/04/17 13:34:59 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*concat;

	len = ft_strlen(s1);
	len += ft_strlen(s2);
	concat = ft_calloc(len + 1, sizeof(char));
	if (!concat)
		return (0);
	ft_strlcpy(concat, s1, ft_strlen(s1) + 1);
	ft_strlcat(concat, s2, len + 1);
	return (concat);
}

/* int main()
{
	printf("%s", ft_strjoin("Hello", "World"));
} */