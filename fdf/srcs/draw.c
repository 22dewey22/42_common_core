/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:03:44 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/04/10 08:06:36 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	put_pxl_to_img(t_img img, int x, int y, int color)
{
	unsigned char	*pxl;

	if (!is_in_img(x, y))
		return ;
	pxl = (unsigned char *)img.addr + y * img.line_len + x * img.bpp / 8;
	*(unsigned int *)pxl = color;
}

void	draw_right(t_fdf *fdf, int x, int y, t_points *calc_map)
{
	t_line	line;

	if (x < fdf->map->width - 1)
	{
		line.x1 = (int)(calc_map + y * fdf->map->width + x + 1)->x;
		line.y1 = (int)(calc_map + y * fdf->map->width + x + 1)->y;
		line.color1 = fdf->alternate_colorset[fdf->current_colorset][y
			* fdf->map->width + x + 1];
	}
	else
		return ;
	line.x0 = (int)(calc_map + y * fdf->map->width + x)->x;
	line.y0 = (int)(calc_map + y * fdf->map->width + x)->y;
	line.color0 = fdf->alternate_colorset[fdf->current_colorset][y
		* fdf->map->width + x];
	draw_line(fdf->img, line);
}

void	draw_down(t_fdf *fdf, int x, int y, t_points *calc_map)
{
	t_line	line;

	if (y < fdf->map->height - 1)
	{
		line.x1 = (int)(calc_map + (y + 1) * fdf->map->width + x)->x;
		line.y1 = (int)(calc_map + (y + 1) * fdf->map->width + x)->y;
		line.color1 = fdf->alternate_colorset[fdf->current_colorset][(y + 1)
			* fdf->map->width + x];
	}
	else
		return ;
	line.x0 = (int)(calc_map + y * fdf->map->width + x)->x;
	line.y0 = (int)(calc_map + y * fdf->map->width + x)->y;
	line.color0 = fdf->alternate_colorset[fdf->current_colorset][y
		* fdf->map->width + x];
	draw_line(fdf->img, line);
}

void	draw_line(t_img *img, t_line line)
{
	t_bres	bres;

	if (!line_on_screen(line))
		return ;
	if (!is_in_img(line.x0, line.y0))
		line = (t_line){line.x1, line.y1, line.color1, line.x0, line.y0,
			line.color0};
	bres.x0 = line.x0;
	bres.x1 = line.x1;
	bres.y0 = line.y0;
	bres.y1 = line.y1;
	bres.dx = ft_abs(bres.x0 - bres.x1);
	bres.dy = -ft_abs(bres.y0 - bres.y1);
	bres.sx = ft_signof(bres.x1 - bres.x0);
	bres.sy = ft_signof(bres.y1 - bres.y0);
	bres.error = bres.dx + bres.dy;
	bres.d_error = 0;
	bres.dist = sqrt(pow(bres.dx, 2) + pow(bres.dy, 2));
	init_bres_color(&bres, line);
	bresenham(bres, img, 0);
}
