/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:35:41 by aralves-          #+#    #+#             */
/*   Updated: 2024/04/18 19:59:22 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_check(int c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

static char	*ft_write(char const *s1, char const *set, char *trimmed)
{
	unsigned int	count;
	unsigned int	i;
	unsigned int	len;

	len = ft_strlen(s1) - 1;
	i = 0;
	count = 0;
	while (!ft_check(s1[i], set) && s1[i])
		i++;
	while (!ft_check(s1[len], set) && len > 0)
		len--;
	while (i <= len)
		trimmed[count++] = s1[i++];
	return (trimmed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trimmed;
	unsigned int	count;
	unsigned int	i;
	unsigned int	len;

	len = ft_strlen(s1) - 1;
	i = 0;
	count = 0;
	if (!*s1)
		return (ft_strdup(""));
	while (!ft_check(s1[i], set) && s1[i])
		i++;
	while (!ft_check(s1[len], set) && len > 0)
		len--;
	while (i <= len)
	{
		i++;
		count++;
	}
	trimmed = ft_calloc(count + 1, sizeof(char));
	if (!trimmed)
		return (0);
	return (ft_write(s1, set, trimmed));
}

/* int main()
{
	char *str;
	char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
	str = ft_strtrim(s1, " ");
	printf(("%s"), str);
	free(str);
} */