/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:23:25 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/28 22:03:18 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_v3.h"

void	get_file(t_readbuf **first, int fd)
{
	int			read_bytes;
	t_readbuf	*current;

	*first = create_rbuf_elem();
	current = *first;
	if (!current)
		return ;
	read_bytes = read(fd, current->buf, BUFFER);
	if (read_bytes <= 0)
		return (destroy_file_list(first));
	while (read_bytes == BUFFER)
	{
		current->next = create_rbuf_elem();
		if (current->next == NULL)
			return (destroy_file_list(first));
		current = current->next;
		read_bytes = read(fd, current->buf, BUFFER);
	}
}

int	process_file(t_readbuf *first, t_fdf *fdf)
{
	char	*file;

	if (first == NULL)
		return (EXIT_FAILURE);
	fdf->map.width = 0;
	fdf->map.height = 0;
	file = readbuf_to_char(first);
	if (file == NULL)
		return (EXIT_FAILURE);
	if (validate_map(file, fdf) == EXIT_FAILURE)
	{
		free(file);
		return (EXIT_FAILURE);
	}
	if (allocate_zval_and_colors(&fdf->map) == EXIT_FAILURE)
	{
		free(file);
		return (EXIT_FAILURE);
	}
	return (get_zval_and_colors(file, &fdf->map));
}

char	*readbuf_to_char(t_readbuf *first)
{
	t_readbuf	*current;
	char		*output;
	int			size;
	int			i;

	current = first;
	size = 0;
	i = 0;
	while (current->next)
	{
		size += BUFFER;
		current = current->next;
	}
	while (current->buf[i] && i < BUFFER)
	{
		size++;
		i++;
	}
	output = malloc(sizeof(char) * (size + 1));
	return (fill_output(output, first));
}

char	*fill_output(char *output, t_readbuf *first)
{
	int			i;
	int			index;
	t_readbuf	*current;

	if (output == NULL)
	{
		destroy_file_list(&first);
		return (NULL);
	}
	index = 0;
	current = first;
	while (current)
	{
		i = 0;
		while (i < BUFFER && current->buf[i])
			output[index++] = current->buf[i++];
		current = current->next;
	}
	output[index] = 0;
	destroy_file_list(&first);
	return (output);
}
