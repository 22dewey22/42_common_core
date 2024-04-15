/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   war_machine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:18:58 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/04/10 10:29:10 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

static void	kill_colorsets(int **colorsets, int has_color);
static void	kill_mlx(t_fdf *fdf);
static void	kill_map(t_fdf *fdf);

int	kill_program(t_fdf *fdf, int return_value, char *err_msg)
{
	if (err_msg != NULL)
		ft_printf_fd(2, "fdf error: %s\n", err_msg);
	if (fdf == NULL)
		return (return_value);
	if (fdf->map != NULL)
	{
		kill_colorsets(fdf->alternate_colorset, fdf->map->has_color);
		if (fdf->calc_map != NULL)
			free(fdf->calc_map);
		if (fdf->title != NULL)
			free(fdf->title);
		kill_mlx(fdf);
		kill_map(fdf);
	}
	free(fdf);
	return (return_value);
}

static void	kill_mlx(t_fdf *fdf)
{
	if (fdf->img != NULL)
	{
		if (fdf->img->mlx_img != NULL)
			mlx_destroy_image(fdf->mlx, fdf->img->mlx_img);
		free(fdf->img);
	}
	if (fdf->menu != NULL)
	{
		if (fdf->menu->mlx_img != NULL)
			mlx_destroy_image(fdf->mlx, fdf->menu->mlx_img);
		free(fdf->menu);
	}
	if (fdf->win != NULL)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx != NULL)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
}

static void	kill_colorsets(int **colorsets, int has_color)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (colorsets[i + 2 * has_color + 1] != NULL)
			free(colorsets[i + 2 * has_color + 1]);
		i++;
	}
	if (colorsets[0] != NULL)
		free(colorsets[0]);
}

static void	kill_map(t_fdf *fdf)
{
	if (fdf->map != NULL)
	{
		if (fdf->map->colors != NULL)
			free(fdf->map->colors);
		if (fdf->map->z_val != NULL)
			free(fdf->map->z_val);
		free(fdf->map);
	}
}
