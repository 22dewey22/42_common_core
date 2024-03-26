/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:35:38 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/25 21:17:47 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	rotate(t_prog *state, double alpha_x, double beta_y, double gamma_z)
{
	t_grid	*current_line;
	t_grid	*current_elem;

	current_line = state->top_left;
	while (current_line)
	{
		current_elem = current_line;
		while (current_elem)
		{
			translate_one(current_elem, -state->settings.x_center,
				-state->settings.y_center);
			rotate_z(&current_elem->coords.x_calc, &current_elem->coords.y_calc,
				&current_elem->coords.z_calc, gamma_z);
			rotate_x(&current_elem->coords.x_calc, &current_elem->coords.y_calc,
				&current_elem->coords.z_calc, alpha_x);
			rotate_y(&current_elem->coords.x_calc, &current_elem->coords.y_calc,
				&current_elem->coords.z_calc, beta_y);
			translate_one(current_elem, state->settings.x_center,
				state->settings.y_center);
			current_elem = current_elem->right;
		}
		current_line = current_line->down;
	}
}

void	rotate_x(double *x, double *y, double *z, double angle)
{
	double	y_tmp;

	if (angle == 0)
		return ;
	(void)x;
	y_tmp = *y;
	*y = y_tmp * cos(angle) - *z * sin(angle);
	*z = y_tmp * sin(angle) + *z * cos(angle);
}

void	rotate_y(double *x, double *y, double *z, double angle)
{
	double	x_tmp;

	if (angle == 0)
		return ;
	(void)y;
	x_tmp = *x;
	*x = x_tmp * cos(angle) + *z * sin(angle);
	*z = *z * cos(angle) - x_tmp * sin(angle);
}

void	rotate_z(double *x, double *y, double *z, double angle)
{
	double	x_tmp;

	if (angle == 0)
		return ;
	(void)z;
	x_tmp = *x;
	*x = x_tmp * cos(angle) - *y * sin(angle);
	*y = *y * cos(angle) + x_tmp * sin(angle);
}
