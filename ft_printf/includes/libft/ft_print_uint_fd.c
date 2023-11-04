/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 06:29:49 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/23 07:36:09 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_print_uint_fd(unsigned int value, int is_hex, int fd)
{
	int	i;
	int	pow[32];

	i = 0;
	if (is_hex)
		ft_print_hex_fd((unsigned long long) value, is_hex - 1, 0, fd);
	else
	{
		if (value == 0)
			write(fd, "0", 1);
		while (value)
		{
			pow[i++] = value % 10;
			value /= 10;
		}
		while (i)
		{
			ft_putchar_fd(pow[i - 1] + '0', fd);
			i--;
		}
	}
}
