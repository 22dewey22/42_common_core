/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 23:13:08 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/15 23:22:51 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*p;

	i = 0;
	len = 0;
	p = (char *)s;
	while (p[len])
		len++;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (0);
	p[len] = 0;
	while (i < len)
	{
		p[i] = f(i, *(char *)(s + i));
		i++;
	}
	return (p);
}
