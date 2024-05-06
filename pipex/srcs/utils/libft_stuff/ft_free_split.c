/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:10:08 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/12/02 22:10:18 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_stuff.h>

int	ft_free_split(char **split, int error)
{
	int	i;

	i = 0;
	if (!split)
		return (error);
	while (split[i])
		free(split[i++]);
	free(split);
	return (error);
}

int	ft_get_split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}
