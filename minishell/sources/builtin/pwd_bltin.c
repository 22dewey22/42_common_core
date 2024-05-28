/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_bltin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:16:40 by cdutel            #+#    #+#             */
/*   Updated: 2024/05/22 13:27:54 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	print_pwd_error(t_mini *mini, int is_child, char *pathname)
{
	perror(ERR_MSG_PWD_WRITE);
	mini->exit_status = 1;
	free(pathname);
	if (is_child == 1)
		(exit(1));
	return (EXIT_SUCCESS);
}

int	pwd_bltin(t_mini *mini, int is_child)
{
	char	*pathname;
	int		err_val;

	pathname = NULL;
	err_val = get_curr_dir_name(&pathname, 1);
	if (err_val == EXIT_FAILURE)
	{
		free_on_failure(mini);
		return (ft_printf_fd(2, "%s", ERR_MSG_PWD_FAT_ERR),
			EXIT_FAILURE);
	}
	else if (err_val == ERR_GETCWD)
	{
		mini->exit_status = 1;
		if (is_child == 1)
			exit(1);
		return (EXIT_SUCCESS);
	}
	if (printf("%s\n", pathname) == -1)
		return (print_pwd_error(mini, is_child, pathname));
	free(pathname);
	mini->exit_status = 0;
	if (is_child == 1)
		exit(0);
	return (EXIT_SUCCESS);
}

int	get_curr_dir_name(char **pathname, int print_err_msg)
{
	char	*wd;
	int		size;

	size = 128;
	wd = malloc(sizeof(char) * size);
	if (!wd)
		return (EXIT_FAILURE);
	while (!getcwd(wd, size))
	{
		if (errno != ERANGE)
		{
			if (print_err_msg)
				perror(ERR_MSG_PWD);
			return (free(wd), ERR_GETCWD);
		}
		free(wd);
		size += 128;
		wd = malloc(sizeof(char) * size);
		if (!wd)
			return (EXIT_FAILURE);
	}
	*pathname = wd;
	return (EXIT_SUCCESS);
}
