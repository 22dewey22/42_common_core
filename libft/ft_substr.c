/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:09:32 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/15 20:32:00 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			out_size;
	char			*p;

	p = (char *)s;
	i = 0;
	out_size = 0;
	while (s[i] && i < start)
		i++;
	while (s[i++] && out_size < len)
		out_size++;
	p = (char *)malloc(sizeof(char) * (out_size + 1));
	if (!p)
		return (0);
	p[out_size] = 0;
	i = 0;
	while (out_size)
	{
		p[i] = *(char *)(s + start + i);
		out_size--;
		i++;
	}
	return (p);
}
/*
int	main(void)
{
	__builtin_printf("%s\n", ft_substr("prout", 0, 100));
	return (0);
}



*/
