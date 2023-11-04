/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 07:00:55 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/31 08:52:18 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	printf_print_int(t_conv to_print, va_list args, int *count)
{
	int	var;

	var = va_arg(args, int);
	to_print.end_len = printf_get_len(var, to_print);
	if (var < 0)
		to_print.sign = '-';
	*count += to_print.end_len;
	if (to_print.flag == '-')
	{
		if (to_print.sign != '\0')
			ft_putchar_fd(to_print.sign, 1);
		printf_putuint((unsigned int)var * ft_signof(var), to_print,
			"0123456789");
		printf_putalign(to_print, count);
	}
	else
	{
		if (to_print.flag == '0' && to_print.sign != '\0')
			ft_putchar_fd(to_print.sign, 1);
		printf_putalign(to_print, count);
		if (to_print.flag != '0' && to_print.sign != '\0')
			ft_putchar_fd(to_print.sign, 1);
		printf_putuint((unsigned int)var * ft_signof(var), to_print,
			"0123456789");
	}
}

void	printf_print_uint(t_conv to_print, va_list args, int *count, char *base)
{
	unsigned int	var;

	var = va_arg(args, unsigned int);
	to_print.end_len = printf_getuint_len(var, to_print, ft_strlen(base));
	*count += to_print.end_len;
	if (to_print.flag != '-')
		printf_putalign(to_print, count);
	if (ft_is_charset(to_print.conv, "xX") && to_print.hash == '#' && var)
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd(to_print.conv, 1);
	}
	printf_putuint(var, to_print, base);
	if (to_print.flag == '-')
		printf_putalign(to_print, count);
}

void	printf_print_char(t_conv to_print, va_list args, int *count)
{
	int	i;
	int	var;

	var = va_arg(args, int);
	*count += 1;
	i = 0;
	if (to_print.flag == '-')
		ft_putchar_fd((char)var, 1);
	while (i++ < to_print.width - 1)
	{
		ft_putchar_fd(' ', 1);
		*count += 1;
	}
	if (to_print.flag != '-')
		ft_putchar_fd((char)var, 1);
}

void	printf_print_str(t_conv to_print, va_list args, int *count)
{
	char	*str;

	str = va_arg(args, char *);
	if (str)
		to_print.var_len = ft_strlen(str);
	else if (to_print.precision == -1 || to_print.precision >= 6)
	{
		to_print.var_len = 6;
		str = "(null)";
	}
	else
	{
		to_print.var_len = 0;
		str = "";
	}
	printf_putstr(to_print, str, count);
}

void	printf_print_ptr(t_conv to_print, va_list args, int *count)
{
	int		i;
	void	*ptr;

	i = 0;
	ptr = va_arg(args, void *);
	to_print.var_len = ft_get_hex_len((unsigned long long)ptr, 1);
	if (!ptr)
		to_print.var_len = 5;
	if (to_print.flag == '-' && ptr)
		ft_print_hex_fd((unsigned long long)ptr, 0, 1, 1);
	else if (to_print.flag == '-')
		ft_putstr_fd("(nil)", 1);
	while (i++ < to_print.width - to_print.var_len)
	{
		ft_putchar_fd(' ', 1);
		*count += 1;
	}
	if (to_print.flag != '-' && ptr)
		ft_print_hex_fd((unsigned long long)ptr, 0, 1, 1);
	else if (to_print.flag != '-')
		ft_putstr_fd("(nil)", 1);
	*count += to_print.var_len;
}
