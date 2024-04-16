/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:21:10 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/12/03 08:15:49 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ps_error_handler(int error)
{
	if (!error)
		return (0);
	else
	{
		if (error == MALLOC_LIST_ERROR)
		{
			ft_printf_fd(2, "Oups, there's been a problem with malloc...\n");
			return (-1);
		}
		else if (error == INVALID_LIST || error == WRONG_INPUT)
		{
			ft_printf_fd(2, "Error\n");
			return (-1);
		}
		else
			return (-1);
	}
}

int	ps_check_len_digits(int ac, char **av, int isnt_split)
{
	int	i;
	int	j;

	i = isnt_split;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-')
			j++;
		while (av[i][j] == '0' && av[i][j + 1] == '0')
			j++;
		if (ft_strlen(&av[i][j]) > ft_dec_len(INT_MAX)
			|| ft_strlen(&av[i][j]) == 0)
			return (-1);
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
