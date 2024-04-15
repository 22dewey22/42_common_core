/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:40:53 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/04/10 09:10:18 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	get_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_trgb(int trgb, char c)
{
	if (c == 't')
		return ((trgb >> 24) & 0xff);
	if (c == 'r')
		return ((trgb >> 16) & 0xff);
	if (c == 'g')
		return ((trgb >> 8) & 0xff);
	if (c == 'b')
		return (trgb & 0xff);
	return (0);
}

int	init_colorset(t_fdf *fdf)
{
	int	i;

	i = 0;
	fdf->alternate_colorset[i] = get_full_white(fdf);
	if (fdf->alternate_colorset[i++] == NULL)
		return (EXIT_FAILURE);
	if (fdf->map->has_color)
	{
		fdf->alternate_colorset[i++] = fdf->map->colors;
		fdf->alternate_colorset[i++] = &fdf->map->colors[fdf->map->width
			* fdf->map->height];
	}
	fdf->alternate_colorset[i] = get_colorset(0xff00ff, 0x00ff00, fdf);
	if (fdf->alternate_colorset[i++] == NULL)
		return (EXIT_FAILURE);
	fdf->alternate_colorset[i] = get_colorset(0xff00ff, 0xffffff, fdf);
	if (fdf->alternate_colorset[i++] == NULL)
		return (EXIT_FAILURE);
	fdf->alternate_colorset[i] = get_colorset(0xffff00, 0xffff, fdf);
	if (fdf->alternate_colorset[i++] == NULL)
		return (EXIT_FAILURE);
	fdf->alternate_colorset[i] = get_earth_colorset(fdf);
	if (fdf->alternate_colorset[i++] == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	*get_colorset(int color1, int color2, t_fdf *fdf)
{
	int			zmin;
	int			zmax;
	int			i;
	t_dcolor	dcolor;

	i = 1;
	zmin = fdf->map->z_val[0];
	zmax = fdf->map->z_val[0];
	while (i < fdf->map->height * fdf->map->width)
	{
		if (fdf->map->z_val[i] > zmax)
			zmax = fdf->map->z_val[i];
		if (fdf->map->z_val[i] < zmin)
			zmin = fdf->map->z_val[i];
		i++;
	}
	dcolor.r0 = (color1 >> 16) & 0xff;
	dcolor.g0 = (color1 >> 8) & 0xff;
	dcolor.b0 = color1 & 0xff;
	dcolor.dr = ((color2 >> 16) & 0xff) - ((color1 >> 16) & 0xff);
	dcolor.dg = ((color2 >> 8) & 0xff) - ((color1 >> 8) & 0xff);
	dcolor.db = (color2 & 0xff) - (color1 & 0xff);
	return (fill_color_grid(fdf, zmax, zmin, dcolor));
}

int	*fill_color_grid(t_fdf *fdf, int zmax, int zmin, t_dcolor dcolor)
{
	int		*output;
	int		i;
	float	tmp;

	output = malloc(sizeof(int) * fdf->map->height * fdf->map->width);
	if (output == NULL)
		return (NULL);
	i = 0;
	while (i < fdf->map->height * fdf->map->width)
	{
		tmp = (fdf->map->z_val[i] - zmin) / (float)(zmax - zmin);
		output[i++] = ((int)(dcolor.r0 + dcolor.dr
					* tmp) << 16) | ((int)(dcolor.g0 + dcolor.dg
					* tmp) << 8) | (int)(dcolor.b0 + dcolor.db * tmp);
	}
	return (output);
}
