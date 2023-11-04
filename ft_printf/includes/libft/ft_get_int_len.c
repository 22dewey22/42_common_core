/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 06:53:49 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/23 07:30:17 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_get_int_len(int value, int is_hex)
{
	int	i;
	int	buf;
	int	size;

	if (value == 0)
		return (1);
	size = 10;
	if (is_hex)
		size = 16;
	i = 0;
	buf = value;
	while (buf)
	{
		i++;
		buf /= size;
	}
	if (value < 0)
		return (i + 1);
	return (i);
}
