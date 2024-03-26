/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:22:47 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/26 07:29:41 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	close_prog(t_prog *state)
{
	mlx_loop_end(state->mlx);
	return (EXIT_SUCCESS);
}

int	key_press(int key, t_prog *state)
{
	if (key == XK_c)
	{
		state->settings.colorset++;
		state->settings.colorset %= 3 + 2 * state->settings.colors_in_file;
		rendu(state);
	}
	if (key == 65451)
	{
		state->settings.z_size *= 1.2;
		reboot_graph(state);
	}
	if (key == 65453)
	{
		state->settings.z_size /= 1.2;
		reboot_graph(state);
	}
	if (key == XK_space)
	{
		state->settings.view++;
		state->settings.view %= 3;
		reboot_graph(state);
	}
	if (key == XK_d)
	{
		state->settings.draw_diag++;
		state->settings.draw_diag %= 3;
		rendu(state);
	}
	return (EXIT_SUCCESS);
}
void	add_hooks(t_prog *state)
{
	mlx_hook(state->win, DestroyNotify, 0L, &close_prog, state);
	mlx_hook(state->win, KeyPress, KeyPressMask, &key_press, state);
	mlx_hook(state->win, ButtonPress, ButtonPressMask, &mouseclick, state);
	mlx_hook(state->win, MotionNotify, PointerMotionMask, &mousemove, state);
	mlx_hook(state->win, ButtonRelease, ButtonReleaseMask, &mouserelease, state);
	
}