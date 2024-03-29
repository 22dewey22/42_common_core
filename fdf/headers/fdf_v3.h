/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_v3.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:43:09 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/29 09:49:12 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_V3_H
# define FDF_V3_H
# include "defines_fdf.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <ft_printf.h>
# include <unistd.h>
// # include <get_next_line.h>
# include <libft_stuff.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define BUFFER 10000

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
	int					button;
	int					x_prev;
	int					y_prev;
	int					offset_x;
	int					offset_y;
	int					x_pressed;
	int					y_pressed;
}						t_mouse;

typedef struct s_grid
{
	int					z;
	int					color;
	struct s_grid		*right;
	struct s_grid		*down;
}						t_grid;

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
	char				has_color;
}						t_map;

typedef struct s_fdf
{
	void				*mlx;
	void				*win;
	t_img				*img;
	t_map				map;
	char				colored;
}						t_fdf;

typedef struct s_points
{
	float				x;
	float				y;
	float				z;
}						t_points;

typedef struct s_line
{
	int					x0;
	int					y0;
	int					color0;
	int					x1;
	int					y1;
	int					color1;
}						t_line;
/************************v2_MANDATORY*********************************/
// /*arg_parser_utils.c*/
// void				connect_right_down(t_grid *down_line, t_grid *current);
// int					is_valid_line(char *line);
// t_grid				*create_grid_elem(int x, int y, int z);
// /*arg_parser.c*/
// int					get_grid(t_prog *state);
// int					process_line(char *line, t_prog *state);
// int					add_split_to_grid(char **split, t_prog *state);
// t_grid				*create_line(char **split, int y, t_prog *state);
// int					connect_grid(t_prog *state);
// /*colors.c*/
// int					get_color(int t, int r, int g, int b);
// int					get_trgb(int trgb, char c);
// int					get_mid_color(int color0, int color1, double dist,
// 						int step);
// void				get_elem_colors(t_grid *elem, t_prog *state, char *split);
// void				apply_colorset_one(t_prog *state, t_grid *elem);
// /*draw.c*/
// void				draw(t_prog *state, t_grid *elem0, t_grid *elem1);
// void				bresenham(t_bres bres, t_prog *state);
// void				put_pxl_to_img(t_img img, int x, int y, int color);
// int					is_in_img(int x, int y, t_img img);
// /*hooks.c*/
// void				add_hooks(t_prog *state);
// int					close_prog(t_prog *state);
// int					key_press(int key, t_prog *state);
// /*init_graph_utils.c*/
// void				get_max(t_prog *state);
// double				calc_zoom(double x_max, double y_max);
// void				apply_zoom(t_prog *state, int x, int y, double zoom);
// void				get_z_min_max(t_prog *state);
// void				get_min(t_prog *state);
// void				get_center(t_prog *state);
// /*init_graph.c*/
// void				apply_colorset_all(t_prog *state);
// void				reboot_graph(t_prog *state);
// void				init_graph(t_prog *state);
// void				init_grid(t_prog *state);
// void				init_offset(t_prog *state);
// void				init_zoom(t_prog *state);
// /*init_prog.c*/
// int					init_prog(t_prog *state, char **av);
// int					init_mlx(t_prog *state);
// void				init_settings(t_prog *state);
// void				init_rot(t_prog *state);
// void				init_mouse(t_prog *state);
// /*main.c*/
// int					kill_program(t_prog *state, int return_value,
// 						char *err_msg);
// void				destroy_grid(t_grid *top_left);
// /*mouse.c*/
// int					mouseclick(int button, int x, int y, t_prog *state);
// int					mouserelease(int button, int x, int y, t_prog *state);
// int					mousemove(int x, int y, t_prog *state);
// void				process_mouse_zoom(int button, int x, int y, t_prog *state);
// void				process_mouse_move(int button, int x, int y, t_prog *state);
// /*rendu.c*/
// int					rendu(t_prog *state);
// void				draw_one(t_prog *state, t_grid *current_elem);
// int					buff_new_img(t_prog *state);
// /*rotations.c*/
// void				rotate(t_prog *state, double alpha_x, double beta_y,
// 						double gamma_z);
// void				rotate_x(double *x, double *y, double *z, double angle);
// void				rotate_y(double *x, double *y, double *z, double angle);
// void				rotate_z(double *x, double *y, double *z, double angle);
// /*translations.c*/
// void				translate_one(t_grid *current_elem, double x, double y);
// void				translate_all(t_prog *state, double x, double y);
// /*utils.c*/
// void				destroy_grid(t_grid *top_left);
// /*********************************************************************/
// void				print_points(t_prog *state);
/**********************v3***********************/
// int						*get_grid(char **av);
// int						process_line(char *line, t_grid **first);
// int						add_split_to_grid(char **split, t_grid **first);
// t_grid					*destroy_line(t_grid *first);
// t_grid					*create_line(char **split);
// t_grid					*create_grid_elem(int z);
// void					get_elem_colors(t_grid *elem, char *split);
// int						parse_color_from_str(char *str, int normal);
// int						*process_grid(t_grid *first, int error);
// int						check_validity(t_grid *first, char xy);
// int						*destroy_grid(t_grid *first, int x, int y);
// void					free_grid(t_grid *first);
// void					get_grid_into_array(t_grid *first, int *array,
// 							int grid_size);
/**********************v4*********************/
int						get_grid(char **av, t_fdf *fdf);
void					get_file(t_readbuf **first, int fd);
void					destroy_file_list(t_readbuf **first);
t_readbuf				*create_rbuf_elem(void);
int						process_file(t_readbuf *first, t_fdf *fdf);
int						validate_map(char *file, t_fdf *fdf);
int						count_elem_line(char *file, int *i, char *has_color);
char					*readbuf_to_char(t_readbuf *first);
char					*fill_output(char *output, t_readbuf *first);
int						allocate_zval_and_colors(t_map *map);

int						get_zval_and_colors(char *file, t_map *map);
int						atoi_fdf(char *file, int *i);
int						atoi_and_colors(char *file, int *zval, int *colors,
							char has_color);
int						ft_ischarset(char c, char *set);
int						atoi_hex_fdf(char *file, char *base);
int						kill_program(t_fdf *fdf, int return_value);
t_fdf					*init_fdf(void);
t_points				*init_array(int *z_val, t_points *calc_map, int width,
							int height);
void					zoom(t_points *elem, float zoom, float x, float y);
void					translate(t_points *elem, float x, float y);
void					rotate(t_points *elem, double angle, char axis);
void					init_graph(t_points *elem, int size, float angle_x,
							float angle_z);
void					resize_translate(t_points *elems, int size);
void					resize_zoom(t_points *elems, int size);
void					draw_line(t_img *img, t_line line);
void					bresenham(t_bres bres, t_img *img);
void					put_pxl_to_img(t_img img, int x, int y, int color);
int						is_in_img(int x, int y);
void					buff_img(t_fdf *fdf, t_points *calc_map);
void					draw_right(t_fdf *fdf, int x, int y,
							t_points *calc_map);
void					draw_down(t_fdf *fdf, int x, int y, t_points *calc_map);
void					get_first_img(t_fdf *fdf);
int						get_color(int t, int r, int g, int b);
int						get_trgb(int trgb, char c);
#endif