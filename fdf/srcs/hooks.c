/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:18:25 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/04/10 08:12:59 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

static int	get_buffer_size(int elem_count)
{
	if (elem_count <= 50000)
		return (1);
	if (elem_count <= 100000)
		return (2);
	if (elem_count <= 275000)
		return (4);
	if (elem_count <= 1000000)
		return (12);
	return (50);
}

static int	mouse_move(int x, int y, t_hooks *utils)
{
	int	buffer;

	buffer = get_buffer_size(utils->fdf->map->height * utils->fdf->map->width);
	if (utils->mouse->button == 0)
		return (0);
	if (utils->mouse->button == FDF_LEFT_CLICK
		&& utils->mouse->buffer == buffer)
		left_click(utils, x, y);
	if (utils->mouse->button == FDF_RIGHT_CLICK
		&& utils->mouse->buffer == buffer)
		right_click(utils, x, y);
	if (utils->mouse->button == FDF_MIDDLE_CLICK
		&& utils->mouse->buffer == buffer)
		middle_click(utils, x);
	if (utils->mouse->buffer == buffer)
		load_next_image(utils);
	utils->mouse->buffer++;
	return (0);
}

static void	process_key(int key, t_hooks *utils)
{
	if (key == XK_c)
		utils->fdf->current_colorset = (utils->fdf->current_colorset + 1) % (5
				+ 2 * utils->fdf->map->has_color);
	if (key == FDF_PLUS)
		utils->fdf->map->z_alt *= 1.2;
	if (key == FDF_MINUS)
		utils->fdf->map->z_alt /= 1.2;
	if (key == FDF_MINUS || key == FDF_PLUS || key == XK_i)
	{
		init_array(utils->fdf->map, utils->fdf->calc_map);
		init_graph(utils->fdf->calc_map, utils->fdf->map->width
			* utils->fdf->map->height, M_PI / 3, -M_PI / 4);
	}
	if (key == XK_t || key == XK_s)
	{
		init_array(utils->fdf->map, utils->fdf->calc_map);
		if (key == XK_t)
			init_graph(utils->fdf->calc_map, utils->fdf->map->width
				* utils->fdf->map->height, 0, 0);
		else
			init_graph(utils->fdf->calc_map, utils->fdf->map->width
				* utils->fdf->map->height, M_PI / 2, 0);
	}
	load_next_image(utils);
}

static int	key_press(int key, t_hooks *utils)
{
	if (key == FDF_ESC)
		return (close_prog(utils));
	if (key == XK_c || key == FDF_PLUS || key == FDF_MINUS || key == XK_t
		|| key == XK_i || key == XK_s)
		process_key(key, utils);
	return (EXIT_SUCCESS);
}

void	set_hooks(t_hooks *utils)
{
	utils->mouse->button = 0;
	utils->mouse->buffer = 0;
	mlx_hook(utils->fdf->win, DestroyNotify, 0L, &close_prog, utils);
	mlx_hook(utils->fdf->win, KeyRelease, KeyReleaseMask, &key_press, utils);
	mlx_hook(utils->fdf->win, ButtonPress, ButtonPressMask, &mouse_click,
		utils);
	mlx_hook(utils->fdf->win, MotionNotify, PointerMotionMask, &mouse_move,
		utils);
	mlx_hook(utils->fdf->win, ButtonRelease, ButtonReleaseMask, &mouse_release,
		utils->mouse);
}
