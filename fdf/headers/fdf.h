/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:43:09 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/03/25 21:02:38 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <X11/X.h>
# include <X11/keysym.h>
# include <defines_fdf.h>
# include <fcntl.h>
# include <ft_printf.h>
# include <get_next_line.h>
# include <libft_stuff.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_bres
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				error;
	int				d_error;
	int				color0;
	int				color1;
	int				step;
	double			dist;
}					t_bres;

typedef struct s_coords
{
	double			x_init;
	double			y_init;
	double			z_init;
	double			x_calc;
	double			y_calc;
	double			z_calc;

}					t_coords;

typedef struct s_mouse
{
	int				buffer;
	int				button;
	int				x_prev;
	int				y_prev;
	int				offset_x;
	int				offset_y;
	int				x_pressed;
	int				y_pressed;
}					t_mouse;

typedef struct s_grid
{
	t_coords		coords;
	int				color[5];
	struct s_grid	*left;
	struct s_grid	*right;
	struct s_grid	*up;
	struct s_grid	*down;
}					t_grid;

typedef struct s_img
{
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;

}					t_img;
typedef struct s_rot
{
	double			alpha;
	double			beta;
	double			gamma;
}					t_rot;

typedef struct s_sett
{
	double			z_size;
	double			zoom;
	int				view;
	t_rot			rot[3];
	double			alpha;
	double			beta;
	double			gamma;
	int				draw_diag;
	int				colors_in_file;
	int				colorset;
	int				colors[3][2];
	double			x_max;
	double			y_max;
	double			x_min;
	double			y_min;
	double			x_center;
	double			y_center;
	int				z_min;
	int				z_max;
}					t_sett;

typedef struct s_prog
{
	int				ac;
	char			**av;
	char			*title;
	void			*mlx;
	void			*win;
	t_img			img;
	void			*img_tmp;
	t_grid			*top_left;
	t_mouse			mouse;
	t_sett			settings;
	int				loop_on;
}					t_prog;

/************************v2_MANDATORY*********************************/
/*arg_parser_utils.c*/
void				connect_right_down(t_grid *down_line, t_grid *current);
int					is_valid_line(char *line);
t_grid				*create_grid_elem(int x, int y, int z);
/*arg_parser.c*/
int					get_grid(t_prog *state);
int					process_line(char *line, t_prog *state);
int					add_split_to_grid(char **split, t_prog *state);
t_grid				*create_line(char **split, int y, t_prog *state);
int					connect_grid(t_prog *state);
/*colors.c*/
int					get_color(int t, int r, int g, int b);
int					get_trgb(int trgb, char c);
int					get_mid_color(int color0, int color1, double dist,
						int step);
void				get_elem_colors(t_grid *elem, t_prog *state, char *split);
void				apply_colorset_one(t_prog *state, t_grid *elem);
/*draw.c*/
void				draw(t_prog *state, t_grid *elem0, t_grid *elem1);
void				bresenham(t_bres bres, t_prog *state);
void				put_pxl_to_img(t_img img, int x, int y, int color);
int					is_in_img(int x, int y, t_img img);
/*hooks.c*/
void				add_hooks(t_prog *state);
int					close_prog(t_prog *state);
int					key_press(int key, t_prog *state);
/*init_graph_utils.c*/
void				get_max(t_prog *state);
double				calc_zoom(double x_max, double y_max);
void				apply_zoom(t_prog *state, int x, int y, double zoom);
void				get_z_min_max(t_prog *state);
void				get_min(t_prog *state);
void				get_center(t_prog *state);
/*init_graph.c*/
void				apply_colorset_all(t_prog *state);
void				reboot_graph(t_prog *state);
void				init_graph(t_prog *state);
void				init_grid(t_prog *state);
void				init_offset(t_prog *state);
void				init_zoom(t_prog *state);
/*init_prog.c*/
int					init_prog(t_prog *state, char **av);
int					init_mlx(t_prog *state);
void				init_settings(t_prog *state);
void				init_rot(t_prog *state);
void				init_mouse(t_prog *state);
/*main.c*/
int					kill_program(t_prog *state, int return_value,
						char *err_msg);
void				destroy_grid(t_grid *top_left);
/*mouse.c*/
int					mouseclick(int button, int x, int y, t_prog *state);
int					mouserelease(int button, int x, int y, t_prog *state);
int					mousemove(int x, int y, t_prog *state);
void				process_mouse_zoom(int button, int x, int y, t_prog *state);
void				process_mouse_move(int button, int x, int y, t_prog *state);
/*rendu.c*/
int					rendu(t_prog *state);
void				draw_one(t_prog *state, t_grid *current_elem);
int					buff_new_img(t_prog *state);
/*rotations.c*/
void				rotate(t_prog *state, double alpha_x, double beta_y,
						double gamma_z);
void				rotate_x(double *x, double *y, double *z, double angle);
void				rotate_y(double *x, double *y, double *z, double angle);
void				rotate_z(double *x, double *y, double *z, double angle);
/*translations.c*/
void				translate_one(t_grid *current_elem, double x, double y);
void				translate_all(t_prog *state, double x, double y);
/*utils.c*/
void				destroy_grid(t_grid *top_left);
/*********************************************************************/
void				print_points(t_prog *state);
#endif