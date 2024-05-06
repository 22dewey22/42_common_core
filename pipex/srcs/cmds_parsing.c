/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:54:20 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/02/16 10:16:26 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	px_parse_cmds(t_prog *state)
{
	int	first_cmd_index;
	int	last_cmd_index;
	int	error;

	last_cmd_index = state->ac - 2;
	first_cmd_index = 2 + state->here_doc;
	while (first_cmd_index <= last_cmd_index)
	{
		error = px_addback_cmd_list(state, state->av[first_cmd_index]);
		if (error)
			return (error);
		first_cmd_index++;
	}
	return (error);
}

int	px_addback_cmd_list(t_prog *state, char *av)
{
	t_cmds	*new;

	new = malloc(sizeof(*new));
	if (new == 0)
		return (MALLOC_ERROR);
	if (px_only_spaces(av) == 1)
	{
		if (px_weird_arg(new, av) == MALLOC_ERROR)
			return (MALLOC_ERROR);
	}
	else
	{
		if (px_splittable_arg(new, av) == MALLOC_ERROR)
			return (MALLOC_ERROR);
	}
	new->count = ft_get_split_len(new->args);
	new->next = 0;
	return (px_place_cmd(state, new));
}

int	px_place_cmd(t_prog *state, t_cmds *new)
{
	t_cmds	*current;

	current = state->first_cmd;
	if (!current)
	{
		state->first_cmd = new;
		return (EXIT_SUCCESS);
	}
	while (current->next)
		current = current->next;
	current->next = new;
	return (EXIT_SUCCESS);
}

int	px_free_cmd_list(t_prog *state, int error)
{
	t_cmds	*current;
	t_cmds	*tmp;

	current = state->first_cmd;
	if (!current)
		return (error);
	while (current)
	{
		tmp = current->next;
		ft_free_split(current->args, error);
		free(current);
		current = tmp;
	}
	state->first_cmd = NULL;
	return (error);
}
