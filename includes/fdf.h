/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 19:18:33 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/08 15:41:22 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WX 1024.0
# define WY 1024.0

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct		s_vec3d
{
	double			x;
	double			y;
	double			z;
}					t_vec3d;

typedef struct		s_vec2d
{
	double			x;
	double			y;
}					t_vec2d;

typedef struct		s_alpha
{
	double			x;
	double			y;
	double			z;
}					t_alpha;

typedef struct		s_size
{
	double			i;
	double			j;
	double			scroll_x;
	double			scroll_y;
	double			height_ratio;
}					m_size;

typedef struct		s_point
{
	double			x;
	double			y;
	int				color;
}					t_point;

typedef struct		s_cursor
{
	double			x;
	double			y;
}					t_cursor;

typedef struct		s_img
{
	void			*ptr;
	int				*tab;
	int				bpp;
	int				s_l;
	int				endian;
}					t_img;

typedef struct		s_color_var
{
	double			incre;
}					t_color_var;

typedef struct		s_map
{
	m_size			size;
	double			unit;
	double			h_ratio;
	int				**tab;
	t_alpha			alpha;
	t_vec3d			vec[3];
	t_vec2d			vec2d[3];
	t_cursor		cursor;
	t_color_var		color;
}					t_map;

typedef struct		s_mouse
{
	int				button[7];
	double			x;
	double			y;
}					t_mouse;


typedef struct		s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_mouse			mouse;
	t_map			map;
	int				keyboard[279];
	t_img			img;
}					t_window;

int			window_loop(t_window *window);
void		open_window(t_window *window);
int			parser(int const fd, t_map *amap);
int			is_in_screen(t_point p);
int			close_window(t_window *window);
double		radian(double angle);
void		map_info(t_window window);
void		line_put(t_point p1, t_point p2, t_window *window);
void		map_put(t_map map, t_window *window);
void		axes_put(t_map map, t_window *window);
int			event(int key, t_window *window);
void		ico_put(t_map map, void *mlx_ptr, void *win_ptr);
t_point		create_point(double x, double y);
t_point		create_vpoint(int j, int i, int k, t_map map);
t_point		create_rpoint(double x, double y);
void		create_3DPoint(double *tab[3], double x, double y, double z);
t_vec3d		rotate_x(t_vec3d vec, double alpha);
t_vec3d		rotate_y(t_vec3d vec, double alpha);
t_vec3d		rotate_z(t_vec3d vec, double alpha);
t_vec2d		mouse_rotation(int x, int y, int reset);
void		project_vectors(t_window *window);
int			get_decre_color(t_map map);
double		get_incre_color(t_map map);
void		free_fdf(t_window *window);
void		corner1(t_map map, t_window *window);
void		corner2(t_map map, t_window *window);
void		corner3(t_map map, t_window *window);
void		corner4(t_map map, t_window *window);
void		refresh_window(t_window *window);
void		rotate(t_window *window);
int			key_press(int keycode, t_window *window);
int			key_release(int keycode, t_window *window);

#endif
