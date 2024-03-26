/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 00:03:06 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/22 22:39:51 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_stuff.h"

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

static void	write_word(char *out, const char *s1, const char *s2)
{
	int	i;
	int	index;

	out[ft_get_full_len(s1, s2)] = 0;
	i = 0;
	index = 0;
	while (*(char *)(s1 + i))
	{
		out[index++] = *(char *)(s1 + i);
		i++;
	}
	out[index++] = '/';
	i = 0;
	while (*(char *)(s2 + i))
	{
		out[index++] = *(char *)(s2 + i);
		i++;
	}
	out[index] = 0;
}

char	*ft_pathjoin(const char *s1, const char *s2)
{
	char	*out;

	if (!s1 || !s2)
		return (0);
	out = (char *)malloc(sizeof(char) * (ft_get_full_len(s1, s2) + 2));
	if (!out)
		return (0);
	write_word(out, s1, s2);
	return (out);
}
