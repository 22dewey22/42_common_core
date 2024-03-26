/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:10:02 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/25 21:30:37 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	apply_colorset_all(t_prog *state)
{
	t_grid	*current_line;
	t_grid	*current_elem;

	current_line = state->top_left;
	while (current_line)
	{
		current_elem = current_line;
		while (current_elem)
		{
			apply_colorset_one(state, current_elem);
			current_elem = current_elem->right;
		}
		current_line = current_line->down;
	}
}

// void	print_points(t_prog *state)
// {
// 	t_grid	*current_line;
// 	t_grid	*current_elem;

// 	printf("=========DEBUG=====\n");
// 	current_line = state->top_left;
// 	while (current_line)
// 	{
// 		current_elem = current_line;
// 		while (current_elem)
// 		{
// 			printf("x = %f, y = %f, z = %f, color = %#x\n",
// 				current_elem->coords.x_calc, current_elem->coords.y_calc,
// 				current_elem->coords.z_calc, current_elem->color[0]);
// 			current_elem = current_elem->right;
// 		}
// 		current_line = current_line->down;
// 	}
// }
void	reboot_graph(t_prog *state)
{
	init_grid(state);
	get_z_min_max(state);
	get_max(state);
	get_min(state);
	get_center(state);
	rotate(state, state->settings.rot[state->settings.view].alpha,
		state->settings.rot[state->settings.view].beta,
		state->settings.rot[state->settings.view].gamma);
	init_offset(state);
	init_zoom(state);
	if (rendu(state) != EXIT_SUCCESS)
		kill_program(state, MLX_IMG_ERROR,
			"Failure during rendering process\n");
}

void	init_graph(t_prog *state)
{
	init_grid(state);
	get_z_min_max(state);
	get_max(state);
	get_min(state);
	get_center(state);
	if (state->settings.colors_in_file == 1)
		state->settings.colorset = 3;
	apply_colorset_all(state);
	rotate(state, state->settings.rot[state->settings.view].alpha,
		state->settings.rot[state->settings.view].beta,
		state->settings.rot[state->settings.view].gamma);
	init_offset(state);
	init_zoom(state);
}

void	init_grid(t_prog *state)
{
	t_grid	*current_line;
	t_grid	*current_elem;

	current_line = state->top_left;
	while (current_line)
	{
		current_elem = current_line;
		while (current_elem)
		{
			current_elem->coords.x_calc = current_elem->coords.x_init;
			current_elem->coords.y_calc = current_elem->coords.y_init;
			current_elem->coords.z_calc = current_elem->coords.z_init
				* state->settings.z_size;
			current_elem = current_elem->right;
		}
		current_line = current_line->down;
	}
}

void	init_offset(t_prog *state)
{
	t_grid	*current_elem;
	t_grid	*current_line;
	double	x_min;
	double	y_min;

	current_line = state->top_left;
	if (current_line)
	{
		x_min = current_line->coords.x_calc;
		y_min = current_line->coords.y_calc;
	}
	while (current_line)
	{
		current_elem = current_line;
		while (current_elem)
		{
			if (current_elem->coords.x_calc < x_min)
				x_min = current_elem->coords.x_calc;
			if (current_elem->coords.y_calc < y_min)
				y_min = current_elem->coords.y_calc;
			current_elem = current_elem->right;
		}
		current_line = current_line->down;
	}
	translate_all(state, -x_min, -y_min);
}

void	init_zoom(t_prog *state)
{
	double	zoom;

	get_max(state);
	zoom = calc_zoom(state->settings.x_max, state->settings.y_max);
	apply_zoom(state, 0, 0, zoom);
}
