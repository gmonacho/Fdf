/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 19:18:33 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 18:06:28 by gmonacho    ###    #+. /#+    ###.fr     */
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

typedef struct		s_mat3x3
{
	double			m[3][3];
}					t_mat3x3;

typedef struct		s_size
{
	double			i;
	double			j;
	double			scroll_x;
	double			scroll_y;
	double			height_ratio;
}					m_size;

typedef struct		s_map
{
	m_size			size;
	double			unit;
	int				**tab;
	t_alpha			alpha;
	t_vec3d			vec[3];
}					t_map;

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_map			map;
}					t_window;

int			open_window();
int			parser(int const fd, t_map *amap);
int			is_in_screen(t_point p);
int			close_window(void *mlx_ptr, void *win_ptr);
double		arc_cercle(double x, double r);
double		y_elipse(double a, double b, double x);
double		x_elipse(double a, double b, double alpha);
double		radian(double angle);
void		print_elipse(double a, double b, void *mlx_ptr, void *win_ptr);
void		map_info(t_window window);
void		line_put(t_point p1, t_point p2, void *mlx_ptr, void *win_ptr, int color);
void		map_put(t_map map, void *mlx_ptr, void *win_ptr);
void		axes_put(t_map map, void *mlx_ptr, void *win_ptr);
void		fill_para(t_point p1, t_point p2, t_point p3, void *mlx_ptr, void *win_ptr);
int			event(int key, t_window *window);
void		ico_put(t_map map, void *mlx_ptr, void *win_ptr);
t_point		create_point(double x, double y);
t_point		create_vpoint(double ix, double iz, double iy, t_map map);
t_point		create_rpoint(double x, double y);
t_point		mult_mat(double point[3], double projec[2][3]);
void		create_3DPoint(double *tab[3], double x, double y, double z);
t_vec3d		rotate_x(t_vec3d vec, double alpha);
t_vec3d		rotate_y(t_vec3d vec, double alpha);
t_vec3d		rotate_z(t_vec3d vec, double alpha);

#endif
