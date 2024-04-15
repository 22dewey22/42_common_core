/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:16:00 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/04/08 22:21:24 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	init_graph(t_points *elems, int size, float angle_x, float angle_z)
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
		rotate(elems + i, angle_x, 'x');
		translate(elems + i++, tmp_x, tmp_y);
	}
	resize_translate(elems, size);
	resize_zoom(elems, size);
}

void	resize_translate(t_points *elems, int size)
{
	float	tmp_x;
	float	tmp_y;
	int		i;

	tmp_x = (elems)->x;
	tmp_y = (elems)->y;
	i = 0;
	while (i < size)
	{
		if ((elems + i)->x < tmp_x)
			tmp_x = (elems + i)->x;
		if ((elems + i)->y < tmp_y)
			tmp_y = (elems + i)->y;
		i++;
	}
	while (i >= 0)
		translate(elems + i--, -tmp_x, -tmp_y);
}

void	resize_zoom(t_points *elems, int size)
{
	float	tmp_x;
	float	tmp_y;
	float	tmp_zoom;
	int		i;

	tmp_x = (elems)->x;
	tmp_y = (elems)->y;
	i = 0;
	while (i < size)
	{
		if ((elems + i)->x > tmp_x)
			tmp_x = (elems + i)->x;
		if ((elems + i)->y > tmp_y)
			tmp_y = (elems + i)->y;
		i++;
	}
	tmp_zoom = IMG_WIDTH / tmp_x;
	if (tmp_zoom > IMG_HEIGHT / tmp_y)
		tmp_zoom = IMG_HEIGHT / tmp_y;
	while (i >= 0)
	{
		zoom(elems + i, tmp_zoom, 0, 0);
		i--;
	}
}
