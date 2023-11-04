/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 00:03:06 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/16 00:15:34 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_full_len(const char *s1, const char *s2)
{
	int	i;
	int	full_len;

	full_len = 0;
	while (*(char *)(s1 + full_len))
		full_len++;
	i = 0;
	while (*(char *)(s2 + i))
	{
		full_len++;
		i++;
	}
	return (full_len);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*out;
	int		full_len;
	int		i;
	int		index;

	full_len = ft_get_full_len(s1, s2);
	out = (char *)malloc(sizeof(char) * (full_len + 1));
	if (!out)
		return (0);
	out[full_len] = 0;
	i = 0;
	index = 0;
	while (*(char *)(s1 + i))
	{
		out[index++] = *(char *)(s1 + i);
		i++;
	}
	i = 0;
	while (*(char *)(s2 + i))
	{
		out[index++] = *(char *)(s2 + i);
		i++;
	}
	return (out);
}
