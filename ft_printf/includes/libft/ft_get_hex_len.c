/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hex_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 06:12:27 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/23 06:14:44 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_get_hex_len(unsigned long long value, int append)
{
	int	i;

	i = 0;
	while (value)
	{
		i++;
		value /= 16;
	}
	if (append)
		return (i + 2);
	return (i);
}
