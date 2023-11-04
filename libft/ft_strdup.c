/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 08:40:02 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/15 08:44:23 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*p;
	char	*out;

	i = 0;
	len = 0;
	if (s == 0)
		return (0);
	p = (char *)s;
	while (p[len])
		len++;
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (!out)
		return (0);
	while (p[i])
	{
		out[i] = p[i];
		i++;
	}
	out[i] = 0;
	return (out);
}
