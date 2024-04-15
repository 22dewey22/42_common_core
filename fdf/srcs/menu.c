/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:30:54 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/04/10 09:11:41 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

static void	print_menu(t_img *menu);
static void	print_squares(t_img *menu);
static void	print_squares_bis(t_img *menu);

int	get_menu(t_fdf *fdf)
{
	fdf->menu = malloc(sizeof(t_img));
	if (fdf->menu == NULL)
		exit(kill_program(fdf, EXIT_FAILURE, "Unable to create menu image"));
	fdf->menu->mlx_img = mlx_new_image(fdf->mlx, MENU_WIDTH, MENU_HEIGHT);
	if (fdf->menu->mlx_img == NULL)
		exit(kill_program(fdf, EXIT_FAILURE, "Unable to create menu image"));
	fdf->menu->addr = mlx_get_data_addr(fdf->menu->mlx_img, &fdf->menu->bpp,
			&fdf->menu->line_len, &fdf->menu->endian);
	print_menu(fdf->menu);
	return (0);
}

static void	print_menu(t_img *menu)
{
	int	i;

	i = 0;
	while (i < MENU_WIDTH * MENU_HEIGHT * menu->bpp / 8)
	{
		*(unsigned int *)(menu->addr + i) = 0x3c6478;
		i += menu->bpp / 8;
	}
	print_squares(menu);
}

static void	print_squares(t_img *menu)
{
	void			*pxl;
	unsigned int	x;

	x = 0;
	while (x < MENU_WIDTH)
	{
		pxl = (unsigned char *)menu->addr + x * menu->bpp / 8;
		*(unsigned int *)pxl = 0xffffff;
		pxl = (unsigned char *)menu->addr + (MENU_HEIGHT - 1) * menu->line_len
			+ x * menu->bpp / 8;
		*(unsigned int *)pxl = 0xffffff;
		pxl = (unsigned char *)menu->addr + menu->line_len + x * menu->bpp / 8;
		*(unsigned int *)pxl = 0xffffff;
		pxl = (unsigned char *)menu->addr + (MENU_HEIGHT - 2) * menu->line_len
			+ x * menu->bpp / 8;
		*(unsigned int *)pxl = 0xffffff;
		x++;
	}
	print_squares_bis(menu);
}

static void	print_squares_bis(t_img *menu)
{
	unsigned int	x;
	void			*pxl;

	x = 0;
	while (x < MENU_HEIGHT)
	{
		pxl = (unsigned char *)menu->addr + x * menu->line_len + menu->bpp / 8;
		*(unsigned int *)pxl = 0xffffff;
		pxl = (unsigned char *)menu->addr + x * menu->line_len;
		*(unsigned int *)pxl = 0xffffff;
		pxl = (unsigned char *)menu->addr + x * menu->line_len + (MENU_WIDTH
				- 1) * menu->bpp / 8;
		*(unsigned int *)pxl = 0xffffff;
		pxl = (unsigned char *)menu->addr + x * menu->line_len + (MENU_WIDTH
				- 2) * menu->bpp / 8;
		*(unsigned int *)pxl = 0xffffff;
		x++;
	}
}
