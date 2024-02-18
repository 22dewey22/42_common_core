/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hex_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 06:12:27 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/12/02 22:31:56 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_stuff.h>

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
