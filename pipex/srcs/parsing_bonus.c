/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:07:22 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/02/17 14:46:33 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	px_parse_entries_bonus(t_prog *state)
{
	int	error;

	error = px_parse_path(state);
	if (error)
		return (error);
	error = px_parse_files_bonus(state);
	if (error)
		return (error);
	return (px_parse_cmds(state));
}

int	px_parse_files_bonus(t_prog *state)
{
	if (ft_strcmp(state->av[1], "here_doc") == 0)
	{
		state->error = px_create_hd_file(state);
		if (state->error)
			return (state->error);
	}
	else
	{
		state->infile = state->av[1];
		state->infile_fd = open(state->infile, O_RDONLY);
		if (state->infile_fd < 0)
			px_error_msg(state->infile);
	}
	px_get_outfile(state);
	if (state->outfile_fd < 0)
		px_error_msg(state->outfile);
	return (EXIT_SUCCESS);
}
