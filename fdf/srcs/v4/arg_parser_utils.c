/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:24:46 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/28 12:32:27 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_v3.h"

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

	k = 0;
	if (ft_strncmp("0x", file, 2) == 0)
		k += 2;
	output = 0;
	while (file[k] && ft_ischarset(file[k], base))
	{
		j = 0;
		while (file[k] != base[j])
			j++;
		output = output * 16 + j;
		k++;
	}
	return (output);
}
