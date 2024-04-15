/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:21:53 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/04/10 10:36:13 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	main(int ac, char **av)
{
	t_fdf		*fdf;
	t_points	*calc_map;
	t_mouse		mouse;

	if (ac != 2)
		return (kill_program(0, INVALID_ARGS, "Invalid number of arguments"));
	fdf = init_fdf();
	if (fdf == NULL)
		return (kill_program(fdf, EXIT_FAILURE,
				"Unable to init program (fdf level)"));
	if (init_program(fdf, &calc_map, av) == EXIT_FAILURE)
		return (kill_program(fdf, EXIT_FAILURE,
				"Unable to init program (file or mlx level)"));
	if (init_colorset(fdf) == EXIT_FAILURE)
		return (kill_program(fdf, EXIT_FAILURE,
				"Unable to init program (colorset level)"));
	if (get_window(fdf, calc_map, av[1]) == EXIT_FAILURE)
		return (kill_program(fdf, EXIT_FAILURE, "Unable to create window"));
	set_hooks(&(t_hooks){&mouse, fdf, calc_map});
	mlx_loop(fdf->mlx);
	return (kill_program(fdf, EXIT_SUCCESS, NULL));
}

int	init_program(t_fdf *fdf, t_points **calc_map, char **av)
{
	if (get_grid(av, fdf) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	*calc_map = NULL;
	*calc_map = init_array(fdf->map, *calc_map);
	if (*calc_map == NULL)
		return (EXIT_FAILURE);
	fdf->calc_map = *calc_map;
	init_graph(*calc_map, fdf->map->height * fdf->map->width, M_PI / 3, -M_PI
		/ 4);
	get_first_img(fdf);
	if (fdf->mlx == NULL || fdf->img == NULL)
		return (EXIT_FAILURE);
	if (fdf->img->mlx_img == NULL)
		return (EXIT_FAILURE);
	fdf->current_colorset = 0;
	return (EXIT_SUCCESS);
}

t_fdf	*init_fdf(void)
{
	t_fdf	*fdf;
	int		i;

	i = 0;
	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
		return (NULL);
	while (i < 7)
		fdf->alternate_colorset[i++] = NULL;
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->img = NULL;
	fdf->menu = NULL;
	fdf->calc_map = NULL;
	fdf->title = NULL;
	fdf->map = malloc(sizeof(t_map));
	if (fdf->map == NULL)
		return (NULL);
	fdf->map->has_color = 0;
	fdf->map->colors = NULL;
	fdf->map->z_val = NULL;
	fdf->map->z_alt = 1.0;
	return (fdf);
}
