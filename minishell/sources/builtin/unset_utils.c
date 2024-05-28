/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:27:05 by cdutel            #+#    #+#             */
/*   Updated: 2024/05/22 13:31:05 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	env_len(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

void	unset_malloc_err(t_mini *mini)
{
	mini->fatal_error = 1;
	ft_printf_fd(2, "%s", ERR_MSG_UNSET_FAT_ERR);
}
