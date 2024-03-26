/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 07:33:22 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/25 20:40:34 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	draw(t_prog *state, t_grid *elem0, t_grid *elem1)
{
	t_bres	bres;

	if (elem0 == NULL || elem1 == NULL)
		return ;
	bres.x0 = (int)elem0->coords.x_calc;
	bres.x1 = (int)elem1->coords.x_calc;
	bres.y0 = (int)elem0->coords.y_calc;
	bres.y1 = (int)elem1->coords.y_calc;
	bres.dx = ft_abs(bres.x0 - bres.x1);
	bres.dy = -ft_abs(bres.y0 - bres.y1);
	bres.sx = ft_signof(bres.x1 - bres.x0);
	bres.sy = ft_signof(bres.y1 - bres.y0);
	bres.error = bres.dx + bres.dy;
	bres.d_error = 0;
	bres.dist = sqrt(pow(bres.dx, 2) + pow(bres.dy, 2));
	bres.color0 = elem0->color[state->settings.colorset];
	bres.color1 = elem1->color[state->settings.colorset];
	bres.step = 0;
	bresenham(bres, state);
}

void	bresenham(t_bres bres, t_prog *state)
{
	while (1)
	{
		put_pxl_to_img(state->img, bres.x0, bres.y0, get_mid_color(bres.color0,
				bres.color1, bres.dist, bres.step));
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
		bres.step++;
	}
}

void	put_pxl_to_img(t_img img, int x, int y, int color)
{
	unsigned char	*pxl;

	if (!is_in_img(x, y, img))
		return ;
	pxl = (unsigned char *)img.addr + y * img.line_len + x * img.bpp / 8;
	if (img.endian != 0)
		color = get_color(get_trgb(color, 'b'), get_trgb(color, 'r'),
				get_trgb(color, 'g'), get_trgb(color, 't'));
	*(unsigned int *)pxl = color;
}

int	is_in_img(int x, int y, t_img img)
{
	(void)img;
	if (x >= 0 && y >= 0 && y <= IMG_HEIGHT && x < IMG_WIDTH)
		return (1);
	return (0);
}