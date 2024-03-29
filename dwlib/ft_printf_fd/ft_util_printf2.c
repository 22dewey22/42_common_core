/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_printf2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:01:07 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/12/02 22:32:50 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	printf_putuint(unsigned int var, t_conv to_print, char *base)
{
	int				i;
	int				j;
	int				base_size;
	unsigned int	pow[10];

	i = 0;
	j = 0;
	base_size = ft_strlen(base);
	if (to_print.precision == -1 && var == 0)
		ft_putchar_fd('0', to_print.fd);
	while (var)
	{
		pow[i++] = var % base_size;
		var /= base_size;
	}
	while (to_print.precision > 0 && j++ < to_print.precision - i)
		ft_putchar_fd('0', to_print.fd);
	while (i)
	{
		ft_putchar_fd(base[pow[i - 1]], to_print.fd);
		i--;
	}
}

void	printf_putalign(t_conv to_print, int *count)
{
	int	i;

	i = 0;
	while (i++ < to_print.width - to_print.end_len)
	{
		if (to_print.flag == '0')
			ft_putchar_fd('0', to_print.fd);
		else
			ft_putchar_fd(' ', to_print.fd);
		*count += 1;
	}
}
