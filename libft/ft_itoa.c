/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 23:24:25 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/15 23:59:09 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_zero(void)
{
	char	*out;

	out = (char *)malloc(sizeof(char) * 2);
	if (!out)
		return (0);
	out[0] = '0';
	out[1] = 0;
	return (out);
}

static char	*ft_itoa_neg(int *pow, int i)
{
	char	*out;
	int		index;

	out = (char *)malloc(sizeof(char) * (i + 2));
	if (!out)
		return (0);
	out[i + 1] = 0;
	out[0] = '-';
	index = 1;
	while (i)
	{
		out[index++] = pow[i - 1] + '0';
		i--;
	}
	return (out);
}

static char	*ft_itoa_pos(int *pow, int i)
{
	char	*out;
	int		index;

	out = (char *)malloc(sizeof(char) * (i + 1));
	if (!out)
		return (0);
	out[i] = 0;
	index = 0;
	while (i)
	{
		out[index++] = pow[i - 1] + '0';
		i--;
	}
	return (out);
}

char	*ft_itoa(int n)
{
	int	isneg;
	int	pow[11];
	int	i;

	if (n == 0)
		return (ft_itoa_zero());
	i = 0;
	isneg = 1;
	if (n < 0)
		isneg *= -1;
	while (n)
	{
		pow[i++] = isneg * (n % 10);
		n /= 10;
	}
	if (isneg == -1)
		return (ft_itoa_neg(pow, i));
	else
		return (ft_itoa_pos(pow, i));
}
/*
int	main(void)
{
	__builtin_printf("%ld => %s\n", -2147483648, ft_itoa(-2147483648));
	return (0);
}*/
