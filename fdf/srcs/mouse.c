/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:12:38 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/04/10 08:26:05 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	zoom_in_graph(t_points *elems, int size, int x, int y)
{
	int	i;

	i = 0;
	while (i <= size)
		zoom(elems + i++, 1.2, x, y);
}

void	zoom_out_graph(t_points *elems, int size, int x, int y)
{
	int	i;

	i = 0;
	while (i <= size)
		zoom(elems + i++, 1 / 1.2, x, y);
}

void	translate_graph(t_points *elems, int size, int x, int y)
{
	int	i;

	i = 0;
	while (i <= size)
		translate(elems + i++, x, y);
}

int	mouse_click(int button, int x, int y, t_hooks *utils)
{
	if (utils->mouse->button == 0)
	{
		utils->mouse->button = button;
		utils->mouse->x_prev = x;
		utils->mouse->y_prev = y;
	}
	if (button == FDF_WHEEL_UP || button == FDF_WHEEL_DOWN)
		load_next_image_with_zoom(utils, x, y, button);
	return (0);
}

int	mouse_release(int button, int x, int y, t_mouse *mouse)
{
	if (mouse->button == button)
	{
		mouse->button = 0;
		mouse->buffer = 0;
	}
	return (x + y);
}
