/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines_fdf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:25:52 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/24 20:14:15 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_FDF_H
# define DEFINES_FDF_H
/*********************************************/
/****************    ERRCODES   **************/
/*********************************************/
# define SUCCESS 0
# define MALLOC_ERROR 1
# define GNL_ERROR 2
# define OPEN_ERROR 3
# define EMPTY_GRID 4
# define GRID_ERROR 5
# define MLX_ERROR 42
# define MLX_IMG_ERROR 43
# define INVALID_ARGS 4242
/*********************************************/
/****************     KEYS    ****************/
/*********************************************/
# define FDF_LEFT_CLICK 1
# define FDF_RIGHT_CLICK 3
# define FDF_MIDDLE_CLICK 2
# define FDF_WHEEL_UP 4
# define FDF_WHEEL_DOWN 5
# define FDF_PLUS 65451
# define FDF_MINUS 65453
# define FDF_SPACE 32
# define FDF_ESC 65307
/*********************************************/
/****************     IMG     ****************/
/*********************************************/
# define WIN_WIDTH 1920
# define WIN_HEIGHT 900
# define IMG_WIDTH 1920
# define IMG_HEIGHT 900
# define IMG_TOP_LEFT_X 0
# define IMG_TOP_LEFT_Y 0
# define BIG_ENDIAN 1
# define LITTLE_ENDIAN 0

# define M_PI 3.14159265358979323846

#endif