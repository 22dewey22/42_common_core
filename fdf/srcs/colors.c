/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 05:08:58 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/25 14:29:21 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

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

int	get_mid_color(int color0, int color1, double dist, int step)
{
	double	dr;
	double	dg;
	double	db;

	dr = (get_trgb(color1, 'r') - get_trgb(color0, 'r')) / dist;
	dg = (get_trgb(color1, 'g') - get_trgb(color0, 'g')) / dist;
	db = (get_trgb(color1, 'b') - get_trgb(color0, 'b')) / dist;
	return (get_color(get_trgb(color1, 't'), get_trgb(color0, 'r') + dr * step,
			get_trgb(color0, 'g') + dg * step, get_trgb(color0, 'b') + db
			* step));
}

static int	parse_color_from_str(char *str, int normal)
{
	int	i;
	int	output;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	if (str[i])
		i++;
	if (str[i] == 0)
		return (0);
	if (ft_strncmp(&str[i], "0x", 2) == 0 || ft_strncmp(&str[i], "0X", 2) == 0)
		i += 2;
	if (normal == 1)
		output = ft_atoi_base(&str[i], "0123465789abcdef");
	else 
		output = ft_atoi_base(&str[i], "0123465798abcdefP");
	if (output == 0)
		return (ft_atoi_base(&str[i], "0123465789ABCDEF"));
	return (output);
}

void	get_elem_colors(t_grid *elem, t_prog *state, char *split)
{
	if (ft_ischarset(',', split))
	{
		state->settings.colors_in_file = 1;
		elem->color[3] = parse_color_from_str(split, 1);
	}
	else
		elem->color[3] = 0xffffff;
	elem->color[4] = parse_color_from_str(split, 0);
}

void	apply_colorset_one(t_prog *state, t_grid *elem)
{
	double	dist;
	int		i;

	dist = state->settings.z_max - state->settings.z_min;
	i = 0;
	while (i < 3)
	{
		elem->color[i] = get_mid_color(state->settings.colors[i][0],
				state->settings.colors[i][1], dist, elem->coords.z_init
				- state->settings.z_min);
		i++;
	}
}
