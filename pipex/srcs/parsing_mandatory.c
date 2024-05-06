/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_mandatory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:20:16 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/02/16 12:28:08 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	px_parse_entries(t_prog *state)
{
	int	error;

	error = px_parse_path(state);
	if (error)
		return (error);
	error = px_parse_files(state);
	if (error)
		return (error);
	return (px_parse_cmds(state));
}

int	px_parse_files(t_prog *state)
{
	state->infile = state->av[1];
	state->infile_fd = open(state->infile, O_RDONLY);
	if (state->infile_fd < 0)
		px_error_msg(state->infile);
	px_get_outfile(state);
	if (state->outfile_fd < 0)
		px_error_msg(state->outfile);
	return (EXIT_SUCCESS);
}
