/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 00:17:23 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/16 00:46:08 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_emptystring(void)
{
	char	*out;

	out = (char *)malloc(sizeof(char));
	if (!out)
		return (0);
	out[0] = 0;
	return (out);
}

static int	ft_ischarset(char c, char const *set)
{
	int	i;

	i = 0;
	while (*(char *)(set + i))
	{
		if (c == *(char *)(set + i))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_getlastindex(char const *s1, char const *set)
{
	int	last_index;

	last_index = 0;
	while (*(char *)(s1 + last_index))
		last_index++;
	last_index--;
	while (last_index && ft_ischarset(*(char *)(s1 + last_index), set))
		last_index--;
	return (last_index);
}

static int	ft_getfirstindex(char const *s1, char const *set)
{
	int	first_index;

	first_index = 0;
	while (*(char *)(s1 + first_index))
	{
		if (!ft_ischarset(*(char *)(s1 + first_index), set))
			return (first_index);
		first_index++;
	}
	return (first_index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		last_index;
	int		first_index;
	int		out_index;
	char	*out;

	last_index = ft_getlastindex(s1, set);
	if (!last_index)
		return (ft_emptystring());
	first_index = ft_getfirstindex(s1, set);
	out = (char *)malloc(sizeof(char) * (last_index - first_index + 2));
	if (!out)
		return (0);
	out_index = 0;
	while (first_index <= last_index)
	{
		out[out_index++] = *(char *)(s1 + first_index);
		first_index++;
	}
	out[out_index] = 0;
	return (out);
}
/*
int	main(void)
{
	__builtin_printf("%s | %s =>%s\n", "   xxxxtripouille   xxx", " x",
		ft_strtrim("   xxxxtripouille   xxx", " x"));
	return (0);
}*/
