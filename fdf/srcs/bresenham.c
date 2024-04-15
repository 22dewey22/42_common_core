/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 08:32:41 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/04/10 08:06:54 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

static void	next_color(t_bres *bres);
static void	get_next_pxl(t_bres *bres, char c);

void	bresenham(t_bres bres, t_img *img, int in_img)
{
	while (1)
	{
		if (is_in_img(bres.x0, bres.y0))
			in_img = 1;
		put_pxl_to_img(*img, bres.x0, bres.y0, bres.color0);
		if (bres.x0 == bres.x1 && bres.y0 == bres.y1)
			break ;
		bres.d_error = 2 * bres.error;
		if (bres.d_error >= bres.dy)
		{
			if (bres.x0 == bres.x1)
				break ;
			get_next_pxl(&bres, 'x');
		}
		if (bres.d_error <= bres.dx)
		{
			if (bres.y0 == bres.y1)
				break ;
			get_next_pxl(&bres, 'y');
		}
		if (!is_in_img(bres.x0, bres.y0) && in_img)
			break ;
		next_color(&bres);
	}
}

void	init_bres_color(t_bres *bres, t_line line)
{
	bres->color0 = line.color0;
	bres->color1 = line.color1;
	bres->r0 = get_trgb(bres->color0, 'r');
	bres->g0 = get_trgb(bres->color0, 'g');
	bres->b0 = get_trgb(bres->color0, 'b');
	bres->dr = (get_trgb(line.color1, 'r') - bres->r0) / bres->dist;
	bres->dg = (get_trgb(line.color1, 'g') - bres->g0) / bres->dist;
	bres->db = (get_trgb(line.color1, 'b') - bres->b0) / bres->dist;
}

static void	next_color(t_bres *bres)
{
	bres->r0 += bres->dr;
	bres->g0 += bres->dg;
	bres->b0 += bres->db;
	bres->color0 = get_color(0, bres->r0, bres->g0, bres->b0);
}

static void	get_next_pxl(t_bres *bres, char c)
{
	if (c == 'x')
	{
		bres->error += bres->dy;
		bres->x0 += bres->sx;
	}
	if (c == 'y')
	{
		bres->error += bres->dx;
		bres->y0 += bres->sy;
	}
}
