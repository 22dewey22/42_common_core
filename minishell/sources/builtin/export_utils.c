/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 01:36:56 by cdutel            #+#    #+#             */
/*   Updated: 2024/05/27 22:57:06 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	contains_equal(char *env_line)
{
	int	i;

	i = 0;
	while (env_line[i])
	{
		if (env_line[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	get_size(char *to_add, char *env_line)
{
	if (contains_equal(to_add) == 1 && contains_equal(env_line) == 1)
	{
		if (ft_strlen_to_c(to_add, '=') > ft_strlen_to_c(env_line, '='))
			return (ft_strlen_to_c(to_add, '='));
		return (ft_strlen_to_c(env_line, '='));
	}
	else if (contains_equal(to_add) == 1 && contains_equal(env_line) == 0)
	{
		if (ft_strlen_to_c(to_add, '=') > ft_strlen(env_line))
			return (ft_strlen_to_c(to_add, '='));
		return (ft_strlen(env_line));
	}
	else if (contains_equal(to_add) == 0 && contains_equal(env_line) == 1)
	{
		if (ft_strlen_to_c(env_line, '=') > ft_strlen(to_add))
			return (ft_strlen_to_c(env_line, '='));
		return (ft_strlen(to_add));
	}
	if (ft_strlen(to_add) > ft_strlen(env_line))
		return (ft_strlen(to_add));
	return (ft_strlen(env_line));
}

static int	is_valid_id(char *to_add, int i)
{
	if (i == 0 && to_add[i] == '=')
		return (1);
	else if (i == 0 && (to_add[i] >= 0 && to_add[i] <= 9))
		return (1);
	else if (i == 0 && to_add[i] == '$' && to_add[i + 1] == '\0')
		return (1);
	else if (to_add[i] == '=' && to_add[i - 1] == ' ')
		return (1);
	else if (to_add[i] == ' ' || to_add[i] == '@')
		return (1);
	else if (to_add[i] == '-')
		return (1);
	return (0);
}

int	check_to_add(char *to_add, int *trigger)
{
	int	i;

	i = 0;
	while (to_add[i])
	{
		if (is_valid_id(to_add, i) == 1)
		{
			*trigger = -1;
			err_printf("%s%s%s", ERR_MSG_EXPORT,
				to_add, ERR_MSG_EXPORT_ID);
			return (1);
		}
		i++;
	}
	return (0);
}

void	export_malloc_error(t_mini *mini)
{
	mini->fatal_error = 1;
	ft_printf_fd(2, "%s", ERR_MSG_EXPORT_FAT_ERR);
}
