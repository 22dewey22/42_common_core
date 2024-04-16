/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:21:07 by david             #+#    #+#             */
/*   Updated: 2023/12/02 22:31:49 by dwayenbo         ###   ########.fr       */
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
	while (str[i])
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
	while (str[i])
		out = out * 10 + str[i++] - '0';
	return (out * isneg);
}
