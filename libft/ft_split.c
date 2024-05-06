/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:16:36 by aralves-          #+#    #+#             */
/*   Updated: 2024/04/17 14:43:06 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_writealloc(char const *s, char c, char **sp, size_t words)
{
	size_t	i;
	size_t	x;
	size_t	a;
	size_t	b;

	i = 0;
	x = 0;
	a = 0;
	while (s[i] && a < words)
	{
		b = 0;
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			x = i;
		while (s[i] != c && s[i])
			i++;
		if (i - x != 0)
		{
			sp[a++] = ft_calloc(i - x + 1, sizeof(char));
			while (x != i)
				sp[a - 1][b++] = s[x++];
		}
	}
	return (sp);
}

static size_t	wordcount(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t		words;
	char		**sp;

	words = wordcount(s, c);
	sp = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!sp)
		return (0);
	return (ft_writealloc(s, c, sp, words));
}

/* int main()
{
	char **sp;
	size_t i = 0;
	while (i < 13) 
		printf("%s\n", sp[i++]);
} */