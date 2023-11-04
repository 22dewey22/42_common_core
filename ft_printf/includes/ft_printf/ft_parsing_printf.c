/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 06:44:57 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/31 08:43:27 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	printf_parse_conf(t_conv to_print, va_list args, int *count)
{
	int	*ptr;

	if (ft_is_charset(to_print.conv, "di"))
		return (printf_print_int(to_print, args, count));
	if (to_print.conv == 'u')
		return (printf_print_uint(to_print, args, count, "0123456789"));
	if (to_print.conv == 'x')
		return (printf_print_uint(to_print, args, count, "0123456789abcdef"));
	if (to_print.conv == 'X')
		return (printf_print_uint(to_print, args, count, "0123456789ABCDEF"));
	if (to_print.conv == 'c')
		return (printf_print_char(to_print, args, count));
	if (to_print.conv == 's')
		return (printf_print_str(to_print, args, count));
	if (to_print.conv == 'p')
		return (printf_print_ptr(to_print, args, count));
	if (to_print.conv == 'n')
	{
		ptr = va_arg(args, int *);
		*ptr = *count;
	}
}

void	printf_parse_width(va_list args, t_conv *to_print, char *str,
		int *index)
{
	int	i;

	i = 0;
	while (str[i] == '0')
		to_print->flag = str[i++];
	while (str[i] == '-')
		to_print->flag = str[i++];
	while (str[i] == '#')
		to_print->hash = str[i++];
	while (str[i] == ' ')
		to_print->sign = str[i++];
	while (str[i] == '+')
		to_print->sign = str[i++];
	while (str[i] == '0' || str[i] == '-' || str[i] == '#' || str[i] == ' '
		|| str[i] == '+')
		i++;
	if (str[i] == '*')
	{
		to_print->width = va_arg(args, int);
		i++;
	}
	else if (ft_isdigit(str[i]))
		to_print->width = printf_atoi_lite(&str[i], &i);
	*index += i;
}

void	printf_parse_precision(va_list args, t_conv *to_print, char *str,
		int *index)
{
	int	i;

	i = 0;
	if (str[i] == '.')
	{
		to_print->precision = 0;
		if (to_print->flag == '0')
			to_print->flag = 0;
		i++;
	}
	if (ft_isdigit(str[i]))
		to_print->precision = printf_atoi_lite(&str[i], &i);
	else if (str[i] == '*')
	{
		to_print->precision = va_arg(args, int);
		i++;
	}
	*index += i;
}

void	printf_parse_entry(va_list args, char *str, int *index, int *count)
{
	int		i;
	t_conv	to_print;

	i = 1;
	if (str[i] == '%')
	{
		*index += 2;
		*count += 1;
		return (ft_putchar_fd('%', 1));
	}
	to_print = printf_init_conf();
	printf_parse_width(args, &to_print, &str[i], &i);
	printf_parse_precision(args, &to_print, &str[i], &i);
	if (ft_is_charset(str[i], "ncspdiuxX"))
		to_print.conv = str[i++];
	*index += i;
	printf_parse_conf(to_print, args, count);
}
