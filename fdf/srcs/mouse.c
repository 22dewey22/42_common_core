/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:03:30 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/26 07:25:46 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	mousemove(int x, int y, t_prog *state)
{
	if (state->mouse.button >= 1 && state->mouse.button <= 3)
		process_mouse_move(state->mouse.button, x, y, state);
	return (EXIT_SUCCESS);
}

void	process_mouse_move(int button, int x, int y, t_prog *state)
{
	if (button == FDF_LEFT_CLICK && state->mouse.buffer == 15)
	{
		translate_all(state, x - state->mouse.x_prev, y - state->mouse.y_prev);
		state->mouse.buffer = 0;
		state->mouse.x_prev = x;
		state->mouse.y_prev = y;
		rendu(state);
	}
	if (button == FDF_RIGHT_CLICK && state->mouse.buffer == 15)
	{
		rotate(state, (y - state->mouse.y_prev) * 2 * M_PI / WIN_HEIGHT, (x
				- state->mouse.x_prev) * 2 * M_PI / WIN_WIDTH, 0);
		state->mouse.buffer = 0;
		state->mouse.x_prev = x;
		state->mouse.y_prev = y;
		rendu(state);
	}
	if (button == FDF_MIDDLE_CLICK && state->mouse.buffer == 15)
	{
		rotate(state, 0, 0, (x - state->mouse.x_prev) * 2 * M_PI / WIN_WIDTH);
		state->mouse.buffer = 0;
		state->mouse.x_prev = x;
		rendu(state);
	}
	state->mouse.buffer++;
}

void	process_mouse_zoom(int button, int x, int y, t_prog *state)
{
	if (button == FDF_WHEEL_DOWN)
		apply_zoom(state, x, y, 1 / state->settings.zoom);
	else
		apply_zoom(state, x, y, state->settings.zoom);
	rendu(state);
}

int	mouseclick(int button, int x, int y, t_prog *state)
{
	if (state->mouse.button == 0)
	{
		state->mouse.button = button;
		state->mouse.x_pressed = x;
		state->mouse.y_pressed = y;
		state->mouse.x_prev = x;
		state->mouse.y_prev = y;
		state->mouse.buffer = 0;
	}
	// if (on_menu(x, y) && state->mouse.button == FDF_LEFT_CLICK)
	//     process_menu(x, y, state);
	if (button == FDF_WHEEL_UP || button == FDF_WHEEL_DOWN)
		process_mouse_zoom(button, x, y, state);
	return (EXIT_SUCCESS);
}

int	mouserelease(int button, int x, int y, t_prog *state)
{
	if (button == state->mouse.button)
	{
		state->mouse.buffer = 0;
		state->mouse.button = 0;
	}
	(void)x;
	(void)y;
	return (EXIT_SUCCESS);
}