/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 05:03:40 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/25 20:55:41 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	translate_one(t_grid *current_elem, double x, double y)
{
	current_elem->coords.x_calc += x;
	current_elem->coords.y_calc += y;
}

void	translate_all(t_prog *state, double x, double y)
{
	t_grid	*current_line;
	t_grid	*current_elem;

	current_line = state->top_left;
	while (current_line)
	{
		current_elem = current_line;
		while (current_elem)
		{
			translate_one(current_elem, x, y);
			current_elem = current_elem->right;
		}
		current_line = current_line->down;
	}
	state->settings.x_center += x;
	state->settings.y_center += y;
}
