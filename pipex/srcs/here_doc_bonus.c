/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:32:29 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/02/17 15:48:38 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	px_generate_random(char *output, int size)
{
	int		fd;
	int		rd_bytes;
	char	tmp[100];

	fd = open("/dev/random", O_RDONLY);
	if (fd < 0)
		return (OPEN_ERROR);
	while (size >= 0)
	{
		rd_bytes = read(fd, tmp, 100);
		if (rd_bytes <= 0)
		{
			close(fd);
			return (READ_ERROR);
		}
		rd_bytes = 0;
		while (rd_bytes < 100 && size >= 0)
		{
			if (tmp[rd_bytes] <= 'z' && tmp[rd_bytes] >= 'a')
				output[size--] = tmp[rd_bytes];
			rd_bytes++;
		}
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	px_get_heredoc(t_prog *state)
{
	char	random[35];
	int		error;
	int		i;

	i = 0;
	while (i < 35)
		random[i++] = 0;
	ft_strncpy(state->here_doc_name, ".tmp_here_doc_",
		ft_strlen(".tmp_here_doc_"));
	error = px_generate_random(random, 33);
	if (error)
		return (error);
	ft_strncpy(state->here_doc_name + ft_strlen(state->here_doc_name), random,
		50 - ft_strlen(".tmp_here_doc_") - 1);
	return (EXIT_SUCCESS);
}

int	px_create_hd_file(t_prog *state)
{
	state->error = px_get_heredoc(state);
	if (state->error)
		return (state->error);
	while (access(state->here_doc_name, F_OK) == 0)
	{
		state->error = px_get_heredoc(state);
		if (state->error)
			return (state->error);
	}
	state->here_doc_fd = open(state->here_doc_name, O_CREAT | O_RDWR);
	if (state->here_doc_fd < 0)
		return (OPEN_ERROR);
	state->infile_fd = open(state->here_doc_name, O_RDONLY);
	if (state->infile_fd < 0)
		return (OPEN_ERROR);
	unlink(state->here_doc_name);
	state->limiter = ft_strjoin(state->av[2], "\n");
	if (state->limiter == NULL)
	{
		close(state->infile_fd);
		return (MALLOC_ERROR);
	}
	return (px_write_heredoc(state));
}

int	px_write_heredoc(t_prog *state)
{
	char	*line;

	write(1, ">", 1);
	line = get_next_line(0);
	while (line)
	{
		if (ft_strcmp(line, state->limiter) == 0)
			break ;
		write(1, ">", 1);
		write(state->here_doc_fd, line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	if (line != NULL)
		free(line);
	else
	{
		ft_printf_fd(2,
			"\npipex: warning: here-document delimited by end-of-file");
		ft_printf_fd(2, " (wanted '%s')\n", state->av[2]);
	}
	state->here_doc = 1;
	return (EXIT_SUCCESS);
}
