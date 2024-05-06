/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 06:44:57 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/12/02 22:32:39 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	printf_parse_conf(t_conv to_print, va_list args, int *count)
{
	if (ft_ischarset(to_print.conv, "di"))
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
}

void	printf_parse_width(t_conv *to_print, char *str, int *index)
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
	if (ft_isdigit(str[i]))
		to_print->width = printf_atoi_lite(&str[i], &i);
	*index += i;
}

void	printf_parse_precision(t_conv *to_print, char *str,
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
	*index += i;
}

void	printf_parse_entry(va_list args, char *str, t_count *state, int fd)
{
	int		i;
	t_conv	to_print;

	i = 1;
	if (str[i] == '%')
	{
		state->i += 2;
		state->count += 1;
		return (ft_putchar_fd('%', fd));
	}
	to_print = printf_init_conf(fd);
	printf_parse_width(&to_print, &str[i], &i);
	printf_parse_precision(&to_print, &str[i], &i);
	if (ft_ischarset(str[i], "cspdiuxXn"))
		to_print.conv = str[i++];
	state->i += i;
	printf_parse_conf(to_print, args, &(state->count));
}
