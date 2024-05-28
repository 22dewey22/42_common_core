/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_fd1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:58:12 by cdutel            #+#    #+#             */
/*   Updated: 2024/05/21 14:17:20 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_to_fd(int c, int fd)
{
	if (write (fd, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr_to_fd(char *s, int fd)
{
	int	i;

	if (!s)
	{
		ft_putstr_to_fd("(null)", fd);
		return (6);
	}
	i = 0;
	while (s[i])
		i++;
	if (write(fd, s, i) == -1)
		return (-1);
	return (i);
}

int	ft_putnbr_to_fd(long n, int fd)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += ft_putchar_to_fd('-', fd);
		n = -n;
	}
	if (n <= 9)
	{
		i += ft_putchar_to_fd(n + '0', fd);
	}
	if (n > 9)
	{
		i += ft_putnbr_to_fd(n / 10, fd);
		i += ft_putnbr_to_fd(n % 10, fd);
	}
	return (i);
}

int	ft_convert_hexa_fd(unsigned long long n, int fd)
{
	char	*hexabase;
	int		i;

	i = 0;
	hexabase = "0123456789abcdef";
	if (n < 16)
	{
		i += ft_putchar_to_fd(hexabase[n], fd);
	}
	if (n >= 16)
	{
		i += ft_convert_hexa_fd(n / 16, fd);
		i += ft_convert_hexa_fd(n % 16, fd);
	}
	return (i);
}

int	ft_convert_hexa_maj_fd(unsigned long long n, int fd)
{
	char	*hexa_maj;
	int		i;

	i = 0;
	hexa_maj = "0123456789ABCDEF";
	if (n < 16)
	{
		i += ft_putchar_to_fd(hexa_maj[n], fd);
	}
	if (n >= 16)
	{
		i += ft_convert_hexa_maj_fd(n / 16, fd);
		i += ft_convert_hexa_maj_fd(n % 16, fd);
	}
	return (i);
}
