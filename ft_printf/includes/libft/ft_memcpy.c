/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:54:35 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/14 12:15:56 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dest, const void *src, int n)
{
	int					i;
	unsigned char		*p1;
	const unsigned char	*p2;

	i = 0;
	p1 = dest;
	p2 = src;
	while (i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	return (dest);
}
