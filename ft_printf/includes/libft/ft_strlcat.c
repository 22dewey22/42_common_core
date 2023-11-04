/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:20:42 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/14 12:22:51 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
		j++;
	if (i >= size)
		return (size + j);
	j = 0;
	while (src[j] && j < size - i - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	j = 0;
	while (src[j])
	{
		j++;
	}
	return (i + j);
}
