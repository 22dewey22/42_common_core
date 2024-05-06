/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 06:42:23 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/12/02 22:32:47 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	printf_atoi_lite(char *str, int *index)
{
	int	i;
	int	output;

	i = 0;
	output = 0;
	while (ft_isdigit(str[i]))
		output = output * 10 + str[i++] - '0';
	*index += i;
	return (output);
}

void	printf_putstr(t_conv to_print, char *str, int *count)
{
	int	i;

	i = 0;
	if (to_print.var_len >= to_print.precision && to_print.precision >= 0)
		to_print.var_len = to_print.precision;
	*count += to_print.var_len;
	if (to_print.flag == '-' && to_print.var_len)
		write(to_print.fd, str, to_print.var_len);
	while (i++ < to_print.width - to_print.var_len)
	{
		ft_putchar_fd(' ', to_print.fd);
		*count += 1;
	}
	if (to_print.flag != '-' && to_print.var_len)
		write(to_print.fd, str, to_print.var_len);
}

t_conv	printf_init_conf(int fd)
{
	t_conv	to_print;

	to_print.width = 0;
	to_print.flag = 0;
	to_print.precision = -1;
	to_print.conv = '\0';
	to_print.hash = '\0';
	to_print.sign = '\0';
	to_print.fd = fd;
	return (to_print);
}

int	printf_get_len(int var, t_conv to_print)
{
	int	length;
	int	i;
	int	j;

	i = 0;
	j = 0;
	length = 0;
	if (var < 0 || to_print.sign)
		length++;
	if (!var && to_print.precision == -1)
		length++;
	while (var)
	{
		i++;
		var /= 10;
	}
	while (to_print.precision > -1 && j++ < to_print.precision - i)
		length++;
	while (i--)
		length++;
	return (length);
}

int	printf_getuint_len(unsigned int var, t_conv to_print, int base_size)
{
	int	length;
	int	i;
	int	j;

	i = 0;
	j = 0;
	length = 0;
	if (!var && to_print.precision == -1)
		length++;
	if (ft_ischarset(to_print.conv, "xX") && to_print.hash == '#' && var)
		length += 2;
	while (var)
	{
		i++;
		var /= base_size;
	}
	while (to_print.precision > -1 && j++ < to_print.precision - i)
		length++;
	while (i--)
		length++;
	return (length);
}
