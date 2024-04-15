/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:24:46 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/04/10 10:00:16 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	destroy_file_list(t_readbuf **first)
{
	t_readbuf	*current;
	t_readbuf	*tmp;

	current = *first;
	*first = NULL;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

t_readbuf	*create_rbuf_elem(void)
{
	t_readbuf	*new;
	int			i;

	i = 0;
	new = malloc(sizeof(t_readbuf));
	if (!new)
		return (NULL);
	while (i < BUFFER)
		new->buf[i++] = 0;
	new->next = NULL;
	return (new);
}

int	atoi_fdf(char *file, int *i)
{
	int	output;
	int	isneg;

	isneg = 1;
	output = 0;
	if (file[*i] == '-')
	{
		isneg = -1;
		*i += 1;
	}
	while (file[*i] && file[*i] <= '9' && file[*i] >= '0')
	{
		output = output * 10 + file[*i] - '0';
		*i += 1;
	}
	if (file[*i] == ',')
		*i += 1;
	return (output * isneg);
}

int	atoi_hex_fdf(char *file, char *base)
{
	int	output;
	int	j;
	int	k;
	int	size;

	size = 0;
	while (base[size])
		size++;
	k = 0;
	if (ft_strncmp("0x", file, 2) == 0)
		k += 2;
	output = 0;
	while (file[k] && ft_ischarset(file[k], base))
	{
		j = 0;
		while (file[k] != base[j])
			j++;
		output = output * size + j;
		k++;
	}
	return (output);
}

int	atoi_and_colors(char *file, int *zval, int *colors, t_map *map)
{
	int	i;

	i = 0;
	*zval = atoi_fdf(file, &i);
	if (map->has_color)
	{
		*colors = atoi_hex_fdf(&file[i], "0123456789abcdef");
		if (*colors == 0)
			*colors = atoi_hex_fdf(&file[i], "0123456789ABCDEF");
		if (*colors == 0)
			*colors = 0xffffff;
		*(colors + map->height * map->width) = atoi_hex_fdf(&file[i],
				"0123456798abcdefp");
		if (*(colors + map->height * map->width) == 0)
			*(colors + map->height * map->width) = atoi_hex_fdf(&file[i],
					"0123456798ABCDEFP");
		if (*(colors + map->height * map->width) == 0)
			*(colors + map->height * map->width) = 0xffffff;
	}
	while (file[i] && file[i] != '\n' && file[i] != ' ')
		i++;
	return (i);
}
