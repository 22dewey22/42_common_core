/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_fdf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 07:47:50 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/04/10 07:49:33 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_FDF_H
# define STRUCTS_FDF_H

typedef struct s_readbuf
{
	char				buf[BUFFER];
	struct s_readbuf	*next;
}						t_readbuf;

typedef struct s_bres
{
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	int					x0;
	int					y0;
	int					x1;
	int					y1;
	int					error;
	int					d_error;
	int					color0;
	int					color1;
	float				r0;
	float				g0;
	float				b0;
	float				dr;
	float				dg;
	float				db;
	double				dist;
}						t_bres;

typedef struct s_mouse
{
	int					buffer;
	int					buffer_size;
	int					button;
	int					x_prev;
	int					y_prev;
	int					x_pressed;
	int					y_pressed;
}						t_mouse;

typedef struct s_img
{
	void				*mlx_img;
	char				*addr;
	int					bpp;
	int					line_len;
	int					endian;

}						t_img;

typedef struct s_map
{
	int					width;
	int					height;
	int					*z_val;
	int					*colors;
	float				z_alt;
	char				has_color;
}						t_map;

typedef struct s_points
{
	float				x;
	float				y;
	float				z;
}						t_points;

typedef struct s_fdf
{
	char				*title;
	void				*mlx;
	void				*win;
	t_img				*img;
	t_img				*menu;
	t_map				*map;
	t_points			*calc_map;
	int					current_colorset;
	int					*alternate_colorset[7];
}						t_fdf;

typedef struct s_line
{
	int					x0;
	int					y0;
	int					color0;
	int					x1;
	int					y1;
	int					color1;
}						t_line;

typedef struct s_dcolor
{
	int					r0;
	int					g0;
	int					b0;
	int					dr;
	int					dg;
	int					db;
}						t_dcolor;

typedef struct s_hooks
{
	t_mouse				*mouse;
	t_fdf				*fdf;
	t_points			*map_calc;
}						t_hooks;

#endif