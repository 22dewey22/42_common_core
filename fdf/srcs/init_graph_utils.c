/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graph_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:38:38 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/26 04:54:37 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	get_center(t_prog *state)
{
	state->settings.x_center = (state->settings.x_max + state->settings.x_min)
		/ 2;
	state->settings.y_center = (state->settings.y_max + state->settings.y_min)
		/ 2;
}
void	get_max(t_prog *state)
{
	t_grid	*current_elem;
	t_grid	*current_line;

	current_line = state->top_left;
	if (current_line)
	{
		state->settings.x_max = current_line->coords.x_calc;
		state->settings.y_max = current_line->coords.y_calc;
	}
	while (current_line)
	{
		current_elem = current_line;
		while (current_elem)
		{
			if (current_elem->coords.x_calc > state->settings.x_max)
				state->settings.x_max = current_elem->coords.x_calc;
			if (current_elem->coords.y_calc > state->settings.y_max)
				state->settings.y_max = current_elem->coords.y_calc;
			current_elem = current_elem->right;
		}
		current_line = current_line->down;
	}
}

void	get_min(t_prog *state)
{
	t_grid	*current_elem;
	t_grid	*current_line;

	current_line = state->top_left;
	if (current_line)
	{
		state->settings.x_min = current_line->coords.x_calc;
		state->settings.y_min = current_line->coords.y_calc;
	}
	while (current_line)
	{
		current_elem = current_line;
		while (current_elem)
		{
			if (current_elem->coords.x_calc < state->settings.x_min)
				state->settings.x_min = current_elem->coords.x_calc;
			if (current_elem->coords.y_calc < state->settings.y_min)
				state->settings.y_min = current_elem->coords.y_calc;
			current_elem = current_elem->right;
		}
		current_line = current_line->down;
	}
}
void	get_z_min_max(t_prog *state)
{
	t_grid	*current_elem;
	t_grid	*current_line;

	current_line = state->top_left;
	if (current_line)
	{
		state->settings.z_max = current_line->coords.z_init;
		state->settings.z_min = current_line->coords.z_init;
	}
	while (current_line)
	{
		current_elem = current_line;
		while (current_elem)
		{
			if (current_elem->coords.z_init > state->settings.z_max)
				state->settings.z_max = current_elem->coords.z_init;
			if (current_elem->coords.z_init < state->settings.z_min)
				state->settings.z_min = current_elem->coords.z_init;
			current_elem = current_elem->right;
		}
		current_line = current_line->down;
	}
}

double	calc_zoom(double x_max, double y_max)
{
	double	zoom_y;
	double	zoom_x;

	zoom_x = IMG_WIDTH / (x_max + 0.1);
	zoom_y = IMG_HEIGHT / (y_max + 0.1);
	if (zoom_x < zoom_y)
		return (zoom_x);
	return (zoom_y);
}

void	apply_zoom(t_prog *state, int x, int y, double zoom)
{
	t_grid	*current_line;
	t_grid	*current_elem;

	current_line = state->top_left;
	while (current_line)
	{
		current_elem = current_line;
		while (current_elem)
		{
			translate_one(current_elem, -x, -y);
			current_elem->coords.x_calc *= zoom;
			current_elem->coords.y_calc *= zoom;
			current_elem->coords.z_calc *= zoom;
			translate_one(current_elem, x, y);
			current_elem = current_elem->right;
		}
		current_line = current_line->down;
	}
	state->settings.x_center -= x;
	state->settings.x_center *= zoom;
	state->settings.x_center += x;
	state->settings.y_center -= y;
	state->settings.y_center *= zoom;
	state->settings.y_center += y;
}
