/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:50:36 by cdutel            #+#    #+#             */
/*   Updated: 2024/05/21 13:58:30 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_flags_fd(char *s, va_list args, int fd)
{
	if (s[0] == 'c')
		return (ft_putchar_to_fd(va_arg(args, int), fd));
	else if (s[0] == 's')
		return (ft_putstr_to_fd(va_arg(args, char *), fd));
	else if (s[0] == 'd' || s[0] == 'i')
		return (ft_putnbr_to_fd(va_arg(args, int), fd));
	else if (s[0] == 'u')
		return (ft_putnbr_unsigned_fd(va_arg(args, unsigned), fd));
	else if (s[0] == 'x')
		return (ft_convert_hexa_fd(va_arg(args, unsigned), fd));
	else if (s[0] == 'X')
		return (ft_convert_hexa_maj_fd(va_arg(args, unsigned), fd));
	else if (s[0] == 'p')
		return (ft_convert_adress_fd(va_arg(args, unsigned long), fd));
	else if (s[0] == '%')
		return (ft_putchar_to_fd(s[0], fd));
	else
		return (0);
}

int	ft_printf_fd(int fd, const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;
	char	*str;

	va_start(args, s);
	i = 0;
	len = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_check_flags_fd(&str[i + 1], args, fd);
			i += 2;
		}
		else if (str[i] && str[i] != '%')
		{
			len += ft_putchar_to_fd(str[i], fd);
			i++;
		}
		if (len == -1)
			return (-1);
	}
	return (va_end(args), len);
}
