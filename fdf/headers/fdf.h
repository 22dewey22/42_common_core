/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:43:09 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/04/10 08:36:34 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "defines_fdf.h"
# include "structs_fdf.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <ft_printf.h>
# include <libft_stuff.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*arg_parser_utils.c*/
void		destroy_file_list(t_readbuf **first);
t_readbuf	*create_rbuf_elem(void);
int			atoi_fdf(char *file, int *i);
int			atoi_hex_fdf(char *file, char *base);
int			atoi_and_colors(char *file, int *zval, int *colors, t_map *map);
/*arg_parser_v4.c*/
int			get_grid(char **av, t_fdf *fdf);
int			get_zval_and_colors(char *file, t_map *map);
int			allocate_zval_and_colors(t_map *map);
int			validate_map(char *file, t_fdf *fdf);
int			count_elem_line(char *file, int *i, char *has_color);
/*bresenham.c*/
void		bresenham(t_bres bres, t_img *img, int in_img);
void		init_bres_color(t_bres *bres, t_line line);
/*calc_utils.c*/
t_points	*init_array(t_map *map, t_points *calc_map);
void		rotate(t_points *elem, double angle, char axis);
void		translate(t_points *elem, float x, float y);
void		zoom(t_points *elem, float zoom, float x, float y);
/*colors.c*/
int			get_color(int t, int r, int g, int b);
int			get_trgb(int trgb, char c);
int			init_colorset(t_fdf *fdf);
int			*get_colorset(int color1, int color2, t_fdf *fdf);
int			*fill_color_grid(t_fdf *fdf, int zmax, int zmin, t_dcolor dcolor);
/*colors2.c*/
int			*get_full_white(t_fdf *fdf);
int			*get_earth_colorset(t_fdf *fdf);
/*draw_utils.c*/
int			intersect(t_line line1, t_line line2);
int			line_on_screen(t_line line);
int			is_in_img(int x, int y);
/*draw.c*/
void		put_pxl_to_img(t_img img, int x, int y, int color);
void		draw_right(t_fdf *fdf, int x, int y, t_points *calc_map);
void		draw_down(t_fdf *fdf, int x, int y, t_points *calc_map);
void		draw_line(t_img *img, t_line line);
/*file_reader.c*/
void		get_file(t_readbuf **first, int fd);
int			process_file(t_readbuf *first, t_fdf *fdf);
char		*readbuf_to_char(t_readbuf *first);
char		*fill_output(char *output, t_readbuf *first);
/*hooks_utils.c*/
void		rotate_xy(t_points *elems, int size, float angle_x, float angle_y);
void		rotate_z(t_points *elems, int size, float angle_z);
void		process_zoom(int x, int y, int button, t_hooks *utils);
int			close_prog(t_hooks *utils);
/*hooks.c*/
void		set_hooks(t_hooks *utils);
/*img.c*/
int			get_window(t_fdf *fdf, t_points *calc_map, char *title);
void		buff_img(t_fdf *fdf, t_points *calc_map);
void		get_first_img(t_fdf *fdf);
/*main.c*/
int			init_program(t_fdf *fdf, t_points **calc_map, char **av);
t_fdf		*init_fdf(void);
/*map_calc.c*/
void		init_graph(t_points *elem, int size, float angle_x, float angle_z);
void		resize_translate(t_points *elems, int size);
void		resize_zoom(t_points *elems, int size);
/*menu.c*/
int			get_menu(t_fdf *fdf);
/*menu2.c*/
void		print_menu_content(void *mlx, void *win);
/*mouse_utils.c*/
void		left_click(t_hooks *utils, int x, int y);
void		right_click(t_hooks *utils, int x, int y);
void		middle_click(t_hooks *utils, int x);
void		load_next_image(t_hooks *utils);
void		load_next_image_with_zoom(t_hooks *utils, int x, int y, int button);
/*mouse.c*/
void		zoom_in_graph(t_points *elems, int size, int x, int y);
void		zoom_out_graph(t_points *elems, int size, int x, int y);
void		translate_graph(t_points *elems, int size, int x, int y);
int			mouse_click(int button, int x, int y, t_hooks *utils);
int			mouse_release(int button, int x, int y, t_mouse *mouse);
/*war_machine.c*/
int			kill_program(t_fdf *fdf, int return_value, char *err_msg);
#endif