/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:07:21 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/25 11:34:07 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	rendu(t_prog *state)
{
	t_grid	*current_line;
	t_grid	*current_elem;

	if (buff_new_img(state) != EXIT_SUCCESS)
		return (MLX_IMG_ERROR);
	current_line = state->top_left;
	while (current_line)
	{
		current_elem = current_line;
		while (current_elem)
		{
			draw_one(state, current_elem);
			current_elem = current_elem->right;
		}
		current_line = current_line->down;
	}
	mlx_put_image_to_window(state->mlx, state->win, state->img.mlx_img,
		IMG_TOP_LEFT_X, IMG_TOP_LEFT_Y);
	if (state->img_tmp)
		mlx_destroy_image(state->mlx, state->img_tmp);
	return (EXIT_SUCCESS);
}

void	draw_one(t_prog *state, t_grid *current_elem)
{
	draw(state, current_elem, current_elem->right);
	draw(state, current_elem, current_elem->down);
	if (current_elem->down && state->settings.draw_diag)
	{
		draw(state, current_elem, current_elem->down->left);
		if (state->settings.draw_diag == 2)
			draw(state, current_elem, current_elem->down->right);
	}
}

int	buff_new_img(t_prog *state)
{
	void	*tmp;
	int		i;

	i = 0;
	tmp = state->img.mlx_img;
	state->img.mlx_img = mlx_new_image(state->mlx, IMG_WIDTH, IMG_HEIGHT);
	if (state->img.mlx_img == NULL)
	{
		if (tmp)
			state->img.mlx_img = tmp;
		return (MLX_IMG_ERROR);
	}
	if (tmp)
		state->img_tmp = tmp;
	state->img.addr = mlx_get_data_addr(state->img.mlx_img, &state->img.bpp,
			&state->img.line_len, &state->img.endian);
	while (i < IMG_HEIGHT * IMG_WIDTH * state->img.bpp / 8)
		state->img.addr[i++] = 0;
	return (EXIT_SUCCESS);
}
