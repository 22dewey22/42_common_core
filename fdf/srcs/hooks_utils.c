/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 08:13:35 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/04/08 22:21:24 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	rotate_xy(t_points *elems, int size, float angle_x, float angle_y)
{
	float	tmp_x;
	float	tmp_y;
	int		i;

	tmp_x = (elems + size)->x;
	tmp_y = (elems + size)->y;
	i = 0;
	while (i <= size)
	{
		translate(elems + i, -tmp_x, -tmp_y);
		rotate(elems + i, -angle_x, 'x');
		rotate(elems + i, angle_y, 'y');
		translate(elems + i++, tmp_x, tmp_y);
	}
}

void	rotate_z(t_points *elems, int size, float angle_z)
{
	float	tmp_x;
	float	tmp_y;
	int		i;

	tmp_x = (elems + size)->x;
	tmp_y = (elems + size)->y;
	i = 0;
	while (i <= size)
	{
		translate(elems + i, -tmp_x, -tmp_y);
		rotate(elems + i, angle_z, 'z');
		translate(elems + i++, tmp_x, tmp_y);
	}
}

void	process_zoom(int x, int y, int button, t_hooks *utils)
{
	if (button == FDF_WHEEL_DOWN)
		zoom_out_graph(utils->map_calc, utils->fdf->map->height
			* utils->fdf->map->width, x, y);
	if (button == FDF_WHEEL_UP)
		zoom_in_graph(utils->map_calc, utils->fdf->map->height
			* utils->fdf->map->width, x, y);
}

int	close_prog(t_hooks *utils)
{
	mlx_loop_end(utils->fdf->mlx);
	return (EXIT_SUCCESS);
}
