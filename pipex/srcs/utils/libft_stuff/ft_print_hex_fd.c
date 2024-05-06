/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 06:03:37 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/12/02 22:32:08 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_stuff.h>

void	ft_print_hex_fd(unsigned long long value, int upcase, int append,
		int fd)
{
	int		i;
	char	tmp[16];
	char	*base;

	if (!upcase)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (append)
		write(fd, "0x", 2);
	i = 0;
	if (value == 0)
		write(fd, "0", 1);
	while (value)
	{
		tmp[i++] = base[value % 16];
		value /= 16;
	}
	while (i)
	{
		write(fd, &tmp[i - 1], 1);
		i--;
	}
}
