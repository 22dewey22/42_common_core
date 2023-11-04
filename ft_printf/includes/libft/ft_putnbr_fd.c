/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:39:58 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/15 19:54:45 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		isneg;
	int		pow[10];
	char	c;

	isneg = 1;
	i = 0;
	if (n == 0)
		write(fd, "0", 1);
	if (n < 0)
	{
		write(fd, "-", 1);
		isneg *= -1;
	}
	while (n)
	{
		pow[i++] = isneg * (n % 10);
		n /= 10;
	}
	while (i > 0)
	{
		c = pow[i - 1] + '0';
		write(fd, &c, 1);
		i--;
	}
}
/*
int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(0, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(2147483647, 1);
	write(1, "\n", 1);
}
*/
