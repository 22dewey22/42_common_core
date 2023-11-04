/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:14:59 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/15 00:20:19 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*p;
	int		i;
	int		out;
	int		isneg;

	i = 0;
	p = (char *)nptr;
	isneg = 1;
	out = 0;
	while ((p[i] <= 13 && p[i] >= 9) || p[i] == 32)
		i++;
	if (p[i] == '+' || p[i] == '-')
	{
		if (p[i] == '-')
			isneg *= -1;
		i++;
	}
	while (p[i] <= '9' && p[i] >= '0')
	{
		out = out * 10 + p[i] - '0';
		i++;
	}
	return (out * isneg);
}
