/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_parsing_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:07:29 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/05/25 11:21:29 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd	*create_new_cmd(t_split *first, int length, t_heredocs **heredocs)
{
	t_cmd	*output;

	output = malloc(sizeof(t_cmd));
	if (!output)
		return (NULL);
	ft_bzero(output, sizeof(t_cmd));
	if (set_cmd_arg(output, first, length + 1, heredocs) == EXIT_FAILURE)
	{
		destroy_file_list(&output->files);
		destroy_tab(&output->args);
		free(output);
		return (NULL);
	}
	return (output);
}
