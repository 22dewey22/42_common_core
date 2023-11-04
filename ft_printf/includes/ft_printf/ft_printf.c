/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:19:45 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/26 07:05:53 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_printf(const char *s, ...)
{
	va_list	args;
	char	*ptr;
	int		i;
	int		count;

	i = 0;
	count = 0;
	ptr = (char *)s;
	va_start(args, s);
	while (ptr[i])
	{
		if (ptr[i] != '%')
		{
			ft_putchar_fd(ptr[i], 1);
			count++;
			i++;
		}
		else
			printf_parse_entry(args, &ptr[i], &i, &count);
	}
	va_end(args);
	return (count);
}
