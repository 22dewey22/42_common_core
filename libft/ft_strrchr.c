/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:31:46 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/14 13:02:34 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (p[i])
		i++;
	while (i >= 0)
	{
		if ((unsigned char)p[i] == (unsigned char)c)
			return (&p[i]);
		i--;
	}
	return (0);
}
// tester cas int trop grand && s null avec vraie fonction