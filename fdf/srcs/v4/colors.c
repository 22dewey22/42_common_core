/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:40:53 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/29 09:41:36 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf_v3.h"

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