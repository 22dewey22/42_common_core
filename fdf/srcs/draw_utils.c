/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:23:53 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/04/10 08:01:28 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	is_in_img(int x, int y)
{
	if (x >= 0 && y >= 0 && y <= IMG_HEIGHT && x < IMG_WIDTH)
		return (1);
	return (0);
}

int	line_on_screen(t_line line)
{
	if (is_in_img(line.x0, line.y0) || is_in_img(line.x1, line.y1))
		return (1);
	return (intersect(line, (t_line){0, 0, 0, IMG_WIDTH - 1, 0, 0})
		|| intersect(line, (t_line){0, 0, 0, 0, IMG_HEIGHT - 1, 0})
		|| intersect(line, (t_line){IMG_WIDTH - 1, 0, 0, IMG_WIDTH - 1,
			IMG_HEIGHT - 1, 0}) || intersect(line, (t_line){0, IMG_HEIGHT - 1,
			0, IMG_WIDTH - 1, IMG_HEIGHT - 1, 0}));
}

int	intersect(t_line line1, t_line line2)
{
	float	s;

	s = -1;
	if (line2.x0 == line2.x1)
	{
		if (line1.x0 == line1.x1)
			return (0);
		s = (line2.x0 - line1.x0) / (line1.x1 - line1.x0);
	}
	if (line2.y0 == line2.y1)
		s = (line2.x0 - line1.x0) / (line2.x1 - line2.x0);
	if (s >= 0 && s <= 1)
		return (1);
	return (0);
}
