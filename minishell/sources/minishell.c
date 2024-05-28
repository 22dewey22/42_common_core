/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:35:14 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/05/27 10:58:57 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_global;

int	main(int ac, char **av, char **envp)
{
	int		exit_status;
	t_mini	mini;

	(void)ac;
	(void)av;
	ft_bzero(&mini, sizeof(t_mini));
	if (init_mini_struct(&mini, envp) == EXIT_FAILURE)
		return (free_everything(&mini, ERR_INIT));
	signal_ms();
	if ((mini.is_tty && !DEBUG_TTY) || DEBUG_RL)
	{
		printf(ART);
		exit_status = readline_loop(&mini, PROMPT_RL);
		rl_clear_history();
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		exit_status = gnl_loop(&mini);
	}
	mini.line = NULL;
	if (!exit_status)
		exit_status = mini.exit_status;
	return (free_everything(&mini, exit_status));
}
