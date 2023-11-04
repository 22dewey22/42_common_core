/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:20:54 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/31 11:06:53 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tmp;
	size_t	i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb < 0 || size < 0)
		return (0);
	if (nmemb > 2147483647 / size)
		return (0);
	tmp = (char *)malloc(size * nmemb);
	if (!tmp)
		return (0);
	i = 0;
	while (i < size * nmemb)
		tmp[i++] = 0;
	return ((void *)tmp);
}
