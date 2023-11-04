/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_uint_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 06:49:02 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/23 06:53:39 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_get_uint_len(unsigned int value, int is_hex)
{
	int	i;

	i = 0;
	if (value == 0)
		return (1);
	if (is_hex)
		return (ft_get_hex_len((unsigned long long) value, 0));
	while (value)
	{
		i++;
		value /= 10;
	}
	return (i);
}
