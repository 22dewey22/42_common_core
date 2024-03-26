/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:21:07 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/25 14:24:08 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_stuff.h>

long	ft_atol(char *str)
{
	int		i;
	int		isneg;
	long	out;

	i = 0;
	out = 0;
	isneg = 1;
	if (str[i] == '-')
	{
		i++;
		isneg *= -1;
	}
	while (str[i] && str[i] <= '9' && str[i] >= '0')
		out = out * 10 + str[i++] - '0';
	return (out * isneg);
}

int	ft_atoi(char *str)
{
	int	i;
	int	isneg;
	int	out;

	i = 0;
	out = 0;
	isneg = 1;
	if (str[i] == '-')
	{
		i++;
		isneg *= -1;
	}
	while (str[i] && str[i] <= '9' && str[i] >= '0')
		out = out * 10 + str[i++] - '0';
	return (out * isneg);
}

static int	get_base_size(char *base)
{
	int	size;

	size = 0;
	while (base[size])
	{
		if (base[size + 1] && ft_ischarset(base[size], &base[size + 1]))
			return (0);
		size++;
	}
	return (size);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	size;
	int	j;
	int	output;

	size = get_base_size(base);
	output = 0;
	if (size <= 1)
		return (0);
	i = 0;
	while (str[i] && ft_ischarset(str[i], base))
	{
		j = 0;
		while (str[i] != base[j])
			j++;
		output = output * size + j;
		i++;
	}
	return (output);
}
