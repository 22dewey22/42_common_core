/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:05:25 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/02/18 06:13:01 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int ac, char **av, char **envp)
{
	t_prog	state;

	if (ac < 5 || (ft_strcmp(av[1], "here_doc") == 0 && ac < 6))
	{
		write(2, "Invalid number of arguments\n", 28);
		write(2, "Usage : ./pipex infile cmd1 ... cmdn outfile\n", 45);
		write(2, "or\n", 3);
		write(2, "Usage : ./pipex here_doc LIMITER cmd1 ... cmdn outfile\n",
			55);
		return (INVALID_ARGS);
	}
	px_init_prog(&state, ac, av, envp);
	if (px_parse_entries_bonus(&state) != EXIT_SUCCESS)
		return (px_kill_switch(&state, EXIT_FAILURE));
	px_init_dup(&state);
	if (px_pipex_loop(&state) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	exit(px_kill_switch(&state, state.error));
}
