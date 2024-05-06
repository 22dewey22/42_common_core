/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:19:45 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/12/05 11:42:43 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_printf_fd(int fd, const char *s, ...)
{
	va_list	args;
	char	*ptr;
	t_count	state;

	if (!s || fd < 0)
		return (-1);
	state.i = 0;
	state.count = 0;
	ptr = (char *)s;
	va_start(args, s);
	while (ptr[state.i])
	{
		if (ptr[state.i] != '%')
		{
			ft_putchar_fd(ptr[state.i], fd);
			state.count += 1;
			state.i += 1;
		}
		else
			printf_parse_entry(args, &ptr[state.i], &state, fd);
	}
	va_end(args);
	return (state.count);
}
