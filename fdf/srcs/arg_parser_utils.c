/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 08:14:24 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/25 02:51:23 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	connect_right_down(t_grid *down_line, t_grid *current)
{
	while (down_line->right && current->right)
	{
		current->down = down_line;
		down_line->up = current;
		current = current->right;
		down_line = down_line->right;
	}
	current->down = down_line;
	if (down_line)
		current->down->up = current;
}

int	is_valid_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] >= '0' && line[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

t_grid	*create_grid_elem(int x, int y, int z)
{
	t_grid	*output;

	output = malloc(sizeof(t_grid));
	if (!output)
		return (NULL);
	output->coords.x_init = (double)x;
	output->coords.y_init = (double)y;
	output->coords.z_init = (double)z;
	output->coords.x_calc = 0;
	output->coords.y_calc = 0;
	output->coords.z_calc = 0;
	output->down = 0;
	output->up = 0;
	output->left = 0;
	output->right = 0;
	return (output);
}
