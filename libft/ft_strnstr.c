/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:35:15 by aralves-          #+#    #+#             */
/*   Updated: 2024/04/18 20:32:15 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = (char *) big;
	if (!little || !*little)
		return (str1);
	while (*str1 && len > 0)
	{
		i = 0;
		str2 = (char *) little;
		while ((str1[i] == str2[i] || str2[i] == '\0') && i <= len)
		{
			if (str2[i++] == '\0')
				return (str1);
		}
		len--;
		str1++;
	}
	return (0);
}

// int main()
// {
// 	static char haystack[30] = "aaabcabcd";
// 	static char needle[10] = "aabc";
// 	printf("%s", ft_strnstr(haystack, "cd", 8));
// }