/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:13:58 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/04/10 09:07:46 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

t_points	*init_array(t_map *map, t_points *calc_map)
{
	int	x;
	int	y;

	if (calc_map == NULL)
		calc_map = malloc(sizeof(t_points) * (map->width * map->height + 1));
	if (calc_map == NULL)
		return (NULL);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			calc_map[y * map->width + x] = (t_points){x, y, map->z_val[y
				* map->width + x] * map->z_alt};
			x++;
		}
		y++;
	}
	calc_map[map->width * map->height].x = map->width / 2.0;
	calc_map[map->width * map->height].y = map->height / 2.0;
	calc_map[map->width * map->height].z = 0;
	return (calc_map);
}

void	rotate(t_points *elem, double angle, char axis)
{
	float	tmp;

	if (angle == 0)
		return ;
	if (axis == 'x')
	{
		tmp = elem->y;
		elem->y = tmp * cos(angle) - elem->z * sin(angle);
		elem->z = tmp * sin(angle) + elem->z * cos(angle);
	}
	if (axis == 'y')
	{
		tmp = elem->x;
		elem->x = tmp * cos(angle) + elem->z * sin(angle);
		elem->z = elem->z * cos(angle) - tmp * sin(angle);
	}
	if (axis == 'z')
	{
		tmp = elem->x;
		elem->x = tmp * cos(angle) - elem->y * sin(angle);
		elem->y = elem->y * cos(angle) + tmp * sin(angle);
	}
}

void	translate(t_points *elem, float x, float y)
{
	if (!x && !y)
		return ;
	elem->x += x;
	elem->y += y;
}

void	zoom(t_points *elem, float zoom, float x, float y)
{
	translate(elem, -x, -y);
	elem->x *= zoom;
	elem->y *= zoom;
	elem->z *= zoom;
	translate(elem, x, y);
}
