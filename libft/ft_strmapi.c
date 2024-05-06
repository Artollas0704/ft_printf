/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:56:24 by aralves-          #+#    #+#             */
/*   Updated: 2024/04/17 16:12:19 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*copy;
	unsigned int	i;

	i = 0;
	copy = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!copy)
		return (0);
	while (s[i])
	{
		copy[i] = f(i, s[i]);
		i++;
	}
	return (copy);
}

/* char	test_f (unsigned int c, char b)
{
	if ((unsigned char )c != 0 && b != '0')
			return ('a');
	return ('v');
	
}
int	main()
{
	char (*f)(unsigned int, char) =  &test_f;
	printf("%s", ft_strmapi("hello", &test_f));
} */