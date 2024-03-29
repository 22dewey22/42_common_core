/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:03:44 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/29 09:49:01 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_v3.h"

void	draw_line(t_img *img, t_line line)
{
	t_bres	bres;

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
	bres.color0 = line.color0;
	bres.r0 = get_trgb(bres.color0, 'r');
	bres.g0 = get_trgb(bres.color0, 'g');
	bres.b0 = get_trgb(bres.color0, 'b');
	bres.dr = (get_trgb(line.color1, 'r') - bres.r0) / bres.dist;
	bres.dg = (get_trgb(line.color1, 'g') - bres.g0) / bres.dist;
	bres.db = (get_trgb(line.color1, 'b') - bres.b0) / bres.dist;
	bresenham(bres, img);
}

void	bresenham(t_bres bres, t_img *img)
{
	while (1)
	{
		put_pxl_to_img(*img, bres.x0, bres.y0, get_color(0, bres.r0, bres.g0, bres.b0));
		if (bres.x0 == bres.x1 && bres.y0 == bres.y1)
			break ;
		bres.d_error = 2 * bres.error;
		if (bres.d_error >= bres.dy)
		{
			if (bres.x0 == bres.x1)
				break ;
			bres.error += bres.dy;
			bres.x0 += bres.sx;
		}
		if (bres.d_error <= bres.dx)
		{
			if (bres.y0 == bres.y1)
				break ;
			bres.error += bres.dx;
			bres.y0 += bres.sy;
		}
		bres.r0 += bres.dr;
		bres.g0 += bres.dg;
		bres.b0 += bres.db;
	}
}

void	put_pxl_to_img(t_img img, int x, int y, int color)
{
	unsigned char	*pxl;

	if (!is_in_img(x, y))
		return ;
	pxl = (unsigned char *)img.addr + y * img.line_len + x * img.bpp / 8;
	*(unsigned int *)pxl = color;
}

int	is_in_img(int x, int y)
{
	if (x >= 0 && y >= 0 && y <= IMG_HEIGHT && x < IMG_WIDTH)
		return (1);
	return (0);
}