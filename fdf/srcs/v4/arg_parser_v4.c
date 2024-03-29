/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser_v4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 08:31:43 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/29 09:56:04 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_v3.h"

int	get_grid(char **av, t_fdf *fdf)
{
	int			fd;
	t_readbuf	*first;

	first = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	get_file(&first, fd);
	close(fd);
	if (!first)
		return (EXIT_FAILURE);
	return (process_file(first, fdf));
}

int	get_zval_and_colors(char *file, t_map *map)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (file[i])
	{
		if (file[i] != ' ' && file[i] != '\n')
		{
			i += atoi_and_colors(&file[i], &map->z_val[index],
					&map->colors[index], map->has_color);
			index++;
		}
		else
			i++;
	}
	free(file);
	return (EXIT_SUCCESS);
}

int	atoi_and_colors(char *file, int *zval, int *colors, char has_color)
{
	int	i;

	i = 0;
	*zval = atoi_fdf(file, &i);
	if (has_color)
	{
		*colors = atoi_hex_fdf(&file[i], "0123456789abcdef");
		if (*colors == 0)
			*colors = atoi_hex_fdf(&file[i], "0123456789ABCDEF");
		if (*colors == 0)
			*colors = 0xffffff;
	}
	while (file[i] && file[i] != '\n' && file[i] != ' ')
		i++;
	return (i);
}

int	allocate_zval_and_colors(t_map *map)
{
	map->z_val = malloc(sizeof(int) * map->width * map->height);
	if (map->z_val == NULL)
		return (EXIT_FAILURE);
	if (map->has_color)
	{
		map->colors = malloc(sizeof(int) * map->width * map->height);
		if (map->colors == NULL)
		{
			free(map->z_val);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	validate_map(char *file, t_fdf *fdf)
{
	int	width_tmp;
	int	i;

	i = 0;
	fdf->map.colors = NULL;
	fdf->map.width = count_elem_line(file, &i, &fdf->map.has_color);
	fdf->map.height = 1;
	width_tmp = 0;
	while (file[i])
	{
		width_tmp = count_elem_line(file, &i, &fdf->map.has_color);
		if (width_tmp == 0 || width_tmp != fdf->map.width)
			return (EXIT_FAILURE);
		fdf->map.height++;
	}
	return (EXIT_SUCCESS);
}

int	count_elem_line(char *file, int *i, char *has_colors)
{
	int	inword;
	int	output;

	inword = 0;
	output = 0;
	while (file[*i] && file[*i] != '\n')
	{
		if (inword && file[*i] == ' ')
		{
			output++;
			inword = 0;
		}
		if (file[*i] != ' ')
			inword = 1;
		if (file[*i] == ',')
			*has_colors = 1;
		*i += 1;
	}
	if (inword)
		output++;
	if (file[*i])
		*i += 1;
	return (output);
}
