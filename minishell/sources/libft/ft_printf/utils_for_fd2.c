/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_fd2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 03:02:47 by cdutel            #+#    #+#             */
/*   Updated: 2024/05/07 03:31:06 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	int	i;

	i = 0;
	if (n <= 9)
	{
		i += ft_putchar_to_fd(n + '0', fd);
	}
	if (n > 9)
	{
		i += ft_putnbr_unsigned_fd(n / 10, fd);
		i += ft_putnbr_unsigned_fd(n % 10, fd);
	}
	return (i);
}

int	ft_convert_adress_fd(unsigned long long n, int fd)
{
	char	*hexabase;
	int		i;

	if (!n)
	{
		ft_putstr_to_fd("(nil)", fd);
		return (5);
	}
	i = 0;
	hexabase = "0123456789abcdef";
	ft_putchar_to_fd('0', fd);
	ft_putchar_to_fd('x', fd);
	i += 2;
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
