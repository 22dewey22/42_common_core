/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:30:43 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/13 09:49:50 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_stuff.h>

static int	ft_count_words(char const *s, char *set)
{
	int	inword;
	int	i;
	int	count;

	i = 0;
	inword = 0;
	count = 0;
	if (!s)
		return (0);
	while (*(char *)(s + i))
	{
		if (ft_ischarset(*(char *)(s + i), set) && inword)
		{
			count++;
			inword = 0;
		}
		if (!ft_ischarset(*(char *)(s + i), set))
			inword = 1;
		i++;
	}
	if (inword)
		count++;
	return (count);
}

static int	ft_alloc_single(char **out, int j, int letter_count,
		int *norm_arnaque)
{
	if (norm_arnaque[1] == 0)
		return (0);
	out[j] = (char *)malloc(sizeof(char) * (letter_count + 1));
	if (!out[j])
	{
		while (j > 0)
		{
			free(out[j - 1]);
			j--;
		}
		return (-1);
	}
	norm_arnaque[1] = 0;
	return (0);
}

static int	ft_alloc_words(char **out, char *s, char *set, int *norm_arnaque)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		norm_arnaque[0] = 0;
		while (!ft_ischarset(s[i], set) && s[i])
		{
			norm_arnaque[1] = 1;
			norm_arnaque[0] += 1;
			i++;
		}
		if (ft_ischarset(s[i], set) && norm_arnaque[1] == 1 && s[i])
		{
			if (ft_alloc_single(out, j, norm_arnaque[0], norm_arnaque))
				return (-1);
			j++;
			i++;
		}
		else if (s[i])
			i++;
	}
	return (ft_alloc_single(out, j, norm_arnaque[0], norm_arnaque));
}

static void	ft_write_words(char **out, char *s, char *set, int inword)
{
	int	i;
	int	j;
	int	letter_index;

	i = 0;
	j = 0;
	while (s[i])
	{
		letter_index = 0;
		while (!ft_ischarset(s[i], set) && s[i])
		{
			inword = 1;
			out[j][letter_index++] = s[i++];
		}
		if (ft_ischarset(s[i], set) && inword == 1 && s[i])
		{
			out[j++][letter_index] = 0;
			inword = 0;
			i++;
		}
		else if (s[i])
			i++;
	}
	if (inword)
		out[j][letter_index] = 0;
}

char	**ft_split(char const *s, char *set)
{
	int		i;
	int		count;
	char	**out;
	int		norm_arnaque[2];

	i = 0;
	norm_arnaque[0] = 0;
	norm_arnaque[1] = 0;
	count = ft_count_words(s, set);
	out = (char **)malloc(sizeof(char *) * (count + 1));
	if (!out)
		return (0);
	out[count] = 0;
	if (!count || *(char *)s == 0)
		return (out);
	while (*(char *)(s + i) && ft_ischarset(*(char *)(s + i), set))
		i++;
	if (ft_alloc_words(out, (char *)s + i, set, norm_arnaque))
	{
		free(out);
		return (0);
	}
	ft_write_words(out, (char *)s + i, set, 0);
	return (out);
}
