/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:05:25 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/02/18 06:09:34 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int ac, char **av, char **envp)
{
	t_prog	state;

	if (ac != 5)
	{
		write(2, "Invalid number of arguments\n", 28);
		write(2, "Usage :\n./pipex infile cmd1 cmd2 outfile\n", 41);
		return (INVALID_ARGS);
	}
	px_init_prog(&state, ac, av, envp);
	if (px_parse_entries(&state) != EXIT_SUCCESS)
		return (px_kill_switch(&state, EXIT_FAILURE));
	px_init_dup(&state);
	if (px_pipex_loop(&state) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	exit(px_kill_switch(&state, state.error));
}
