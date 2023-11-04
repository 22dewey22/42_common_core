/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:57:48 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/14 12:16:15 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*p1;
	const unsigned char	*p2;

	p1 = dest;
	p2 = src;
	while (n > 0)
	{
		*(p1 + n - 1) = *(p2 + n - 1);
		n--;
	}
	return (dest);
}
/*
int	main(void)
{
	char	s[] = "0123456789";

	__builtin_printf("BEFORE\n%s\n", s);
	ft_memmove(s + 2, s, 5);
	__builtin_printf("AFTER\n%s\n", s);
	return (0);
}
*/
