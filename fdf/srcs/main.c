/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:27:40 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/25 18:31:51 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
t_grid	*current_line;
t_grid	*current_elem;

current_line = state->top_left;
while (current_line)
{
	current_elem = current_line;
	while (current_elem)
	{
		prout;
		prout ;
		current_elem = current_elem->right;
	}
	current_line = current_line->down;
}
*/

int	main(int ac, char **av)
{
	t_prog	state;

	if (ac != 2)
		return (kill_program(&state, INVALID_ARGS,
				"Invalid number of arguments.\nUsage : ./fdf map\n"));
	if (init_prog(&state, av) != EXIT_SUCCESS)
		return (kill_program(&state, MLX_ERROR,
				"Failure during MLX initialization\n"));
	if (get_grid(&state) != EXIT_SUCCESS)
		return (kill_program(&state, GRID_ERROR,
				"Failure during file parsing\n"));
	init_graph(&state);
	if (rendu(&state) != EXIT_SUCCESS)
		return (kill_program(&state, MLX_ERROR,
				"Failure during rendering process\n"));
	add_hooks(&state);
	state.loop_on = 1;
	mlx_loop(state.mlx);
	return (kill_program(&state, EXIT_SUCCESS, 0));
}

int	kill_program(t_prog *state, int return_value, char *err_msg)
{
	if (return_value == INVALID_ARGS)
	{
		ft_printf_fd(2, err_msg);
		return (INVALID_ARGS);
	}
	if (state->loop_on == 1)
	{
		mlx_loop_end(state->mlx);
		state->loop_on = 0;
	}
	if (state->img.mlx_img)
		mlx_destroy_image(state->mlx, state->img.mlx_img);
	if (state->win)
		mlx_destroy_window(state->mlx, state->win);
	if (state->mlx)
	{
		mlx_destroy_display(state->mlx);
		free(state->mlx);
	}
	if (state->top_left)
		destroy_grid(state->top_left);
	if (state->title != NULL)
		free(state->title);
	ft_printf_fd(2, err_msg);
	return (return_value);
}

void	destroy_grid(t_grid *top_left)
{
	t_grid	*current_line;
	t_grid	*temp_line;
	t_grid	*current_elem;
	t_grid	*temp_elem;

	if (top_left == NULL)
		return ;
	current_line = top_left;
	while (current_line)
	{
		temp_line = current_line->down;
		current_elem = current_line;
		while (current_elem)
		{
			temp_elem = current_elem->right;
			free(current_elem);
			current_elem = temp_elem;
		}
		current_line = temp_line;
	}
}
