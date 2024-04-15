/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 08:03:03 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/04/10 09:19:03 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	left_click(t_hooks *utils, int x, int y)
{
	translate_graph(utils->map_calc, utils->fdf->map->height
		* utils->fdf->map->width, x - utils->mouse->x_prev, y
		- utils->mouse->y_prev);
	utils->mouse->x_prev = x;
	utils->mouse->y_prev = y;
}

void	right_click(t_hooks *utils, int x, int y)
{
	rotate_xy(utils->map_calc, utils->fdf->map->height * utils->fdf->map->width,
		(y - utils->mouse->y_prev) * 4 * M_PI / IMG_HEIGHT, (x
			- utils->mouse->x_prev) * 4 * M_PI / IMG_WIDTH);
	utils->mouse->x_prev = x;
	utils->mouse->y_prev = y;
}

void	middle_click(t_hooks *utils, int x)
{
	rotate_z(utils->map_calc, utils->fdf->map->height * utils->fdf->map->width,
		(x - utils->mouse->x_prev) * 4 * M_PI / IMG_HEIGHT);
	utils->mouse->x_prev = x;
}

void	load_next_image(t_hooks *utils)
{
	void	*tmp;
	void	*tmp2;

	tmp = mlx_new_image(utils->fdf->mlx, IMG_WIDTH, IMG_HEIGHT);
	if (tmp == NULL)
		exit(kill_program(utils->fdf, EXIT_FAILURE,
				"Unable to load next image"));
	tmp2 = utils->fdf->img->mlx_img;
	utils->fdf->img->mlx_img = tmp;
	utils->fdf->img->addr = mlx_get_data_addr(utils->fdf->img->mlx_img,
			&utils->fdf->img->bpp, &utils->fdf->img->line_len,
			&utils->fdf->img->endian);
	utils->mouse->buffer = 0;
	buff_img(utils->fdf, utils->map_calc);
	mlx_put_image_to_window(utils->fdf->mlx, utils->fdf->win,
		utils->fdf->img->mlx_img, 0, 0);
	mlx_destroy_image(utils->fdf->mlx, tmp2);
}

void	load_next_image_with_zoom(t_hooks *utils, int x, int y, int button)
{
	void	*tmp;
	void	*tmp2;

	tmp = mlx_new_image(utils->fdf->mlx, IMG_WIDTH, IMG_HEIGHT);
	if (tmp == NULL)
		exit(kill_program(utils->fdf, EXIT_FAILURE,
				"Unable to load next image"));
	tmp2 = utils->fdf->img->mlx_img;
	utils->fdf->img->mlx_img = tmp;
	utils->fdf->img->addr = mlx_get_data_addr(utils->fdf->img->mlx_img,
			&utils->fdf->img->bpp, &utils->fdf->img->line_len,
			&utils->fdf->img->endian);
	process_zoom(x, y, button, utils);
	buff_img(utils->fdf, utils->map_calc);
	mlx_put_image_to_window(utils->fdf->mlx, utils->fdf->win,
		utils->fdf->img->mlx_img, 0, 0);
	mlx_destroy_image(utils->fdf->mlx, tmp2);
}
