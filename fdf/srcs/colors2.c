/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:10:43 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/04/10 09:10:35 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

static void	fill_earth_colorset(int *colors, int size, int z_max, int *output);

int	*get_full_white(t_fdf *fdf)
{
	int	*output;
	int	i;

	output = malloc(sizeof(int) * fdf->map->height * fdf->map->width);
	if (output == NULL)
		return (NULL);
	i = 0;
	while (i < fdf->map->height * fdf->map->width)
	{
		output[i++] = 0xffffff;
	}
	return (output);
}

int	*get_earth_colorset(t_fdf *fdf)
{
	int		*output;
	int		i;
	float	z_max;

	output = malloc(sizeof(int) * fdf->map->height * fdf->map->width);
	if (output == NULL)
		return (NULL);
	i = 0;
	z_max = 0;
	while (i < fdf->map->height * fdf->map->width)
	{
		if (z_max < fdf->map->z_val[i])
			z_max = fdf->map->z_val[i];
		i++;
	}
	fill_earth_colorset(fdf->map->z_val, fdf->map->height * fdf->map->width,
		z_max, output);
	return (output);
}

static void	fill_earth_colorset(int *z_val, int size, int z_max, int *output)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (z_val[i] <= -100)
			output[i] = 0x008dda;
		else if (z_val[i] <= 0)
			output[i] = 0x41c9e2;
		else if (z_val[i] <= z_max / 6)
			output[i] = 0x90D26D;
		else if (z_val[i] <= z_max / 2)
			output[i] = 0xdc6b19;
		else if (z_val[i] <= 5 * z_max / 6)
			output[i] = 0xe5c287;
		else if (z_val[i] <= z_max)
			output[i] = 0xffffff;
		i++;
	}
}
