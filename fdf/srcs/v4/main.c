/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:21:53 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/29 09:52:43 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_v3.h"

int	main(int ac, char **av)
{
	t_fdf		*fdf;
	t_points	*calc_map;
	int			size;

	if (ac != 2)
		return (0);
	fdf = init_fdf();
	if (fdf == NULL)
		return (EXIT_FAILURE);
	if (get_grid(av, fdf) != EXIT_SUCCESS)
		return (kill_program(fdf, EXIT_FAILURE));
	calc_map = NULL;
	calc_map = init_array(fdf->map.z_val, calc_map, fdf->map.width,
			fdf->map.height);
	if (calc_map == NULL)
		return (kill_program(fdf, EXIT_FAILURE));
	size = fdf->map.height * fdf->map.width;
	init_graph(calc_map, size, M_PI/6, M_PI/12);
	get_first_img(fdf);
	if (fdf->mlx == NULL || fdf->img == NULL)
		return (kill_program(fdf, EXIT_FAILURE));
	buff_img(fdf, calc_map);
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->mlx_img, 0, 0);
	printf("elem_count : %d\n", fdf->map.height * fdf->map.width);
	mlx_loop(fdf->mlx);
	free(calc_map);
	return (kill_program(fdf, EXIT_SUCCESS));
}

void	buff_img(t_fdf *fdf, t_points *calc_map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < IMG_WIDTH * IMG_HEIGHT)
		fdf->img->addr[i++] = (unsigned int)0;
	y = 0;
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.width)
		{
			draw_right(fdf, x, y, calc_map);
			draw_down(fdf, x, y, calc_map);
			x++;
		}
		y++;
	}
}

void	draw_right(t_fdf *fdf, int x, int y, t_points *calc_map)
{
	t_line	line;

	if (x < fdf->map.width - 1)
	{
		line.x1 = (int)(calc_map + y * fdf->map.width + x + 1)->x;
		line.y1 = (int)(calc_map + y * fdf->map.width + x + 1)->y;
		if (fdf->map.has_color)
			line.color1 = fdf->map.colors[y * fdf->map.width + x + 1];
		else
			line.color1 = 0xffffff;
	}
	else
		return ;
	line.x0 = (int)(calc_map + y * fdf->map.width + x)->x;
	line.y0 = (int)(calc_map + y * fdf->map.width + x)->y;
	if (fdf->map.has_color)
		line.color0 = fdf->map.colors[y * fdf->map.width + x];
	else
		line.color0 = 0xffffff;
	draw_line(fdf->img, line);
}

void	draw_down(t_fdf *fdf, int x, int y, t_points *calc_map)
{
	t_line	line;

	if (y < fdf->map.height - 1)
	{
		line.x1 = (int)(calc_map + (y + 1) * fdf->map.width + x)->x;
		line.y1 = (int)(calc_map + (y + 1) * fdf->map.width + x)->y;
		if (fdf->map.has_color)
			line.color1 = fdf->map.colors[(y + 1) * fdf->map.width];
		else
			line.color1 = 0xffffff;
	}
	else
		return ;
	line.x0 = (int)(calc_map + y * fdf->map.width + x)->x;
	line.y0 = (int)(calc_map + y * fdf->map.width + x)->y;
	if (fdf->map.has_color)
		line.color0 = fdf->map.colors[y * fdf->map.width + x];
	else
		line.color0 = 0xffffff;
	draw_line(fdf->img, line);
}

void	get_first_img(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (fdf->mlx == NULL)
		return ;
	fdf->img = malloc(sizeof(t_img));
	if (fdf->img == NULL)
		return ;
	fdf->img->mlx_img = mlx_new_image(fdf->mlx, IMG_WIDTH, IMG_HEIGHT);
	if (fdf->img->mlx_img == NULL)
		return ;
	fdf->img->addr = mlx_get_data_addr(fdf->img->mlx_img, &fdf->img->bpp,
			&fdf->img->line_len, &fdf->img->endian);
}

t_fdf	*init_fdf(void)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
		return (NULL);
	fdf->map.has_color = 0;
	fdf->map.height = 0;
	fdf->map.width = 0;
	fdf->map.colors = NULL;
	fdf->map.z_val = NULL;
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->img = NULL;
	return (fdf);
}
int	kill_program(t_fdf *fdf, int return_value)
{
	if (fdf->img)
	{
		if (fdf->img->mlx_img)
			mlx_destroy_image(fdf->mlx, fdf->img->mlx_img);
		free(fdf->img);
	}
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
	if (fdf->map.colors)
		free(fdf->map.colors);
	if (fdf->map.z_val)
		free(fdf->map.z_val);
	if (fdf)
		free(fdf);
	return (return_value);
}
