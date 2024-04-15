/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:05:00 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/04/10 09:16:16 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	get_window(t_fdf *fdf, t_points *calc_map, char *filename)
{
	buff_img(fdf, calc_map);
	get_menu(fdf);
	fdf->title = ft_strjoin("fdf - ", filename);
	if (fdf->title == NULL)
		return (EXIT_FAILURE);
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, fdf->title);
	free(fdf->title);
	fdf->title = NULL;
	if (fdf->win == NULL)
		return (EXIT_FAILURE);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->mlx_img, 0, 0);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->menu->mlx_img, IMG_WIDTH,
		0);
	print_menu_content(fdf->mlx, fdf->win);
	return (EXIT_SUCCESS);
}

void	buff_img(t_fdf *fdf, t_points *calc_map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < IMG_WIDTH * IMG_HEIGHT * fdf->img->bpp / 8)
		fdf->img->addr[i++] = 0;
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			draw_right(fdf, x, y, calc_map);
			draw_down(fdf, x, y, calc_map);
			x++;
		}
		y++;
	}
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
