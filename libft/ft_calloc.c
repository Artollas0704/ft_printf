/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:53:14 by aralves-          #+#    #+#             */
/*   Updated: 2024/05/07 21:46:11 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	mult;

	mult = nmemb * size;
	if (nmemb > size && size != 0 && nmemb > mult)
		return (0);
	else if (size > nmemb && nmemb != 0 && size > mult)
		return (0);
	else if (size == nmemb && size != 0 && size > mult)
		return (0);
	arr = (void *)malloc(nmemb * size);
	if (!arr)
		return (0);
	ft_bzero(arr, size * nmemb);
	return (arr);
}
