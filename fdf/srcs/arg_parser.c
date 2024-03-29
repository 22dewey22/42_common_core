/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:26:52 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/28 08:13:14 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	get_grid(t_prog *state)
{
	char	*line;
	int		fd;
	int		error;

	fd = open(state->av[1], O_RDONLY);
	if (fd < 0)
		return (OPEN_ERROR);
	line = get_next_line(fd);
	if (!line)
		return (GNL_ERROR);
	while (line)
	{
		if (is_valid_line(line))
			error = process_line(line, state);
		else
			error = 0;
		free(line);
		if (error)
			break ;
		line = get_next_line(fd);
	}
	close(fd);
	exit(1);
	if (error == 0)
		return (connect_grid(state));
	return (error);
}

int	process_line(char *line, t_prog *state)
{
	int		error;
	char	**split;

	split = ft_split(line, " \n");
	if (!split)
		return (MALLOC_ERROR);
	error = add_split_to_grid(split, state);
	ft_free_split(split, 0);
	return (error);
}

int	add_split_to_grid(char **split, t_prog *state)
{
	t_grid	*current;
	int		i;

	i = 1;
	if (state->top_left == NULL)
	{
		state->top_left = create_line(split, 0, state);
		if (state->top_left == NULL)
			return (MALLOC_ERROR);
		return (EXIT_SUCCESS);
	}
	current = state->top_left;
	while (current->down)
	{
		current = current->down;
		i++;
	}
	current->down = create_line(split, i, state);
	if (!current->down)
		return (MALLOC_ERROR);
	return (EXIT_SUCCESS);
}

static t_grid	*destroy_line(t_grid *first)
{
	t_grid	*tmp;

	while (first)
	{
		tmp = first->right;
		free(first);
		first = tmp;
	}
	return (NULL);
}

t_grid	*create_line(char **split, int y, t_prog *state)
{
	int		x;
	t_grid	*current;
	t_grid	*first;
	t_grid	*tmp;

	first = create_grid_elem(0, y, ft_atoi(split[0]));
	if (!first)
		return (NULL);
	get_elem_colors(first, state, split[0]);
	x = 1;
	current = first;
	while (split[x])
	{
		tmp = create_grid_elem(x, y, ft_atoi(split[x]));
		if (!tmp)
			return (destroy_line(first));
		current->right = tmp;
		tmp->left = current;
		current = tmp;
		get_elem_colors(current, state, split[x]);
		x++;
	}
	return (first);
}

int	connect_grid(t_prog *state)
{
	t_grid	*current;
	t_grid	*current_line;
	t_grid	*down_line;

	if (state->top_left == NULL)
		return (EMPTY_GRID);
	current_line = state->top_left;
	while (current_line->down)
	{
		down_line = current_line->down;
		current = current_line;
		connect_right_down(down_line, current);
		current_line = current_line->down;
	}
	return (EXIT_SUCCESS);
}
