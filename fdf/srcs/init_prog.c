/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:37:33 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/25 19:16:04 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	init_prog(t_prog *state, char **av)
{
	state->av = av;
	state->img.mlx_img = NULL;
	state->win = NULL;
	state->top_left = NULL;
	state->mlx = NULL;
	state->loop_on = 0;
	state->title = ft_strjoin("fdf - ", av[1]);
	if (!state->title)
		return (MALLOC_ERROR);
	if (init_mlx(state) != EXIT_SUCCESS)
		return (MLX_ERROR);
	init_settings(state);
	init_mouse(state);
	return (EXIT_SUCCESS);
}

int	init_mlx(t_prog *state)
{
	state->mlx = mlx_init();
	if (state->mlx == NULL)
		return (MLX_ERROR);
	state->win = mlx_new_window(state->mlx, WIN_WIDTH, WIN_HEIGHT,
			state->title);
	if (state->win == NULL)
		return (MLX_ERROR);
	state->img_tmp = NULL;
	return (EXIT_SUCCESS);
}

void	init_settings(t_prog *state)
{
	state->settings.colors_in_file = 0;
	state->settings.colorset = 0;
	state->settings.colors[0][0] = 0xffffff;
	state->settings.colors[0][1] = 0xff0000;
	state->settings.colors[1][0] = 0x555555;
	state->settings.colors[1][1] = 0x00ff00;
	state->settings.colors[2][0] = 0x0000ff;
	state->settings.colors[2][1] = 0x00ff00;
	state->settings.draw_diag = 0;
	state->settings.zoom = 1.2;
	state->settings.z_size = 1.0;
	init_rot(state);
}

void	init_rot(t_prog *state)
{
	state->settings.view = 0;
	state->settings.rot[0].alpha = M_PI / 3;
	state->settings.rot[0].beta = 0;
	state->settings.rot[0].gamma = M_PI / 12;
	state->settings.rot[1].alpha = M_PI / 2;
	state->settings.rot[1].beta = 0;
	state->settings.rot[1].gamma = 0;
	state->settings.rot[2].alpha = 0;
	state->settings.rot[2].beta = 0;
	state->settings.rot[2].gamma = 0;
}

void	init_mouse(t_prog *state)
{
	state->mouse.buffer = 0;
	state->mouse.button = 0;
	state->mouse.offset_x = 0;
	state->mouse.offset_y = 0;
	state->mouse.x_pressed = 0;
	state->mouse.y_pressed = 0;
	state->mouse.x_prev = 0;
	state->mouse.y_prev = 0;
}
