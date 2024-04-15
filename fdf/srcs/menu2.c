/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:20:59 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/04/10 08:23:02 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

static void	print_menu_content_2(void *mlx, void *win);

void	print_menu_content(void *mlx, void *win)
{
	mlx_string_put(mlx, win, IMG_WIDTH + MENU_WIDTH / 2 - 122, 75, 0xffffff,
		"______________________________________");
	mlx_string_put(mlx, win, IMG_WIDTH + MENU_WIDTH / 2 - 125, 85, 0xffffff,
		"|                                     |");
	mlx_string_put(mlx, win, IMG_WIDTH + MENU_WIDTH / 2 - 125, 95, 0xffffff,
		"|                 FDF                 |");
	mlx_string_put(mlx, win, IMG_WIDTH + MENU_WIDTH / 2 - 125, 105, 0xffffff,
		"|                                     |");
	mlx_string_put(mlx, win, IMG_WIDTH + MENU_WIDTH / 2 - 122, 105, 0xffffff,
		"______________________________________");
	mlx_string_put(mlx, win, IMG_WIDTH + MENU_WIDTH / 2 - 122, 150, 0xffffff,
		"Mouse");
	mlx_string_put(mlx, win, IMG_WIDTH + MENU_WIDTH / 2 - 122, 152, 0xffffff,
		"_____");
	mlx_string_put(mlx, win, IMG_WIDTH + MENU_WIDTH / 2 - 107, 170, 0xffffff,
		"Left Click => Translation");
	mlx_string_put(mlx, win, IMG_WIDTH + MENU_WIDTH / 2 - 107, 185, 0xffffff,
		"Right Click => Rotation x/y");
	mlx_string_put(mlx, win, IMG_WIDTH + MENU_WIDTH / 2 - 107, 200, 0xffffff,
		"Middle Click => Rotation z");
	print_menu_content_2(mlx, win);
}

static void	print_menu_content_2(void *mlx, void *win)
{
	mlx_string_put(mlx, win, IMG_WIDTH + MENU_WIDTH / 2 - 107, 215, 0xffffff,
		"Wheel up => Zoom in");
	mlx_string_put(mlx, win, IMG_WIDTH + MENU_WIDTH / 2 - 107, 230, 0xffffff,
		"Wheel down => Zoom out");
	mlx_string_put(mlx, win, IMG_WIDTH + MENU_WIDTH / 2 - 122, 255, 0xffffff,
		"Keyboard");
	mlx_string_put(mlx, win, IMG_WIDTH + MENU_WIDTH / 2 - 122, 257, 0xffffff,
		"________");
	mlx_string_put(mlx, win, IMG_WIDTH + MENU_WIDTH / 2 - 107, 275, 0xffffff,
		"ESC => Close window");
	mlx_string_put(mlx, win, IMG_WIDTH + MENU_WIDTH / 2 - 107, 290, 0xffffff,
		"C => Change color palette");
	mlx_string_put(mlx, win, IMG_WIDTH + MENU_WIDTH / 2 - 107, 305, 0xffffff,
		"I => Isometric projection");
	mlx_string_put(mlx, win, IMG_WIDTH + MENU_WIDTH / 2 - 107, 320, 0xffffff,
		"T => Top view");
	mlx_string_put(mlx, win, IMG_WIDTH + MENU_WIDTH / 2 - 107, 335, 0xffffff,
		"S => Side view");
	mlx_string_put(mlx, win, IMG_WIDTH + MENU_WIDTH / 2 - 107, 350, 0xffffff,
		"+/- => Changes elevation (goes back to iso)");
}
