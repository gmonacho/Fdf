/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/09 16:12:07 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 18:58:46 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "../includes/fdf.h"

/*static t_vector		set_vector(t_vector vec, double alpha)
{
	t_vector	new_vec;
	double		calpha;
	double		salpha;

	calpha = cos(radian(alpha));
	salpha = sin(radian(alpha));
	new_vec.x = vec.x * calpha - vec.y * salpha;
	new_vec.y = vec.y * calpha + vec.x * salpha;
	return (new_vec);
}*/

static void		vector_put(t_vec2d vec, void *mlx_ptr, void *win_ptr)
{
	line_put(create_point(WX / 2, WY / 2), create_point(vec.x, vec.y), mlx_ptr, win_ptr, 0x00FF00);
}

static t_vec2d	dddtodd(t_vec3d vec, int unit)
{
	t_vec2d		new_vec;
	double		A1;
	double		A2;
	double		B1;
	double		B2;

	A1 = cos(radian(25));
	A2 = sin(radian(25));
	B1 = cos(radian(15));
	B2 = sin(radian(15));
	new_vec.x = WX / 2 + unit * (A1 * vec.y + A2 * vec.y);
	new_vec.y = WX / 2 + unit * (B2 * (A2 * vec.x - A1 * vec.y) + B1 * vec.z);
	return (new_vec);
}

static void		project_vectors(t_window *window)
{
	int			i;
	t_vec3d		vec_tmp[3];
	t_vec2d		vec2d[3];

	i = 0;
	while (i < 3)
	{
		vec_tmp[i] = rotate_x((*window).map.vec[i], (*window).map.alpha.x);
		vec_tmp[i] = rotate_y(vec_tmp[i], (*window).map.alpha.y);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		vec2d[i] = dddtodd(vec_tmp[i], (*window).map.unit);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		vector_put(vec2d[i], (*window).mlx_ptr, (*window).win_ptr);
		i++;
	}
}

int		event(int key, t_window *window)
{
	if (key == 124)
		(*window).map.alpha.x += 3;
	else if (key == 123)
		(*window).map.alpha.x -= 3;
	else if (key == 126)
		(*window).map.alpha.y += 3;
	else if (key == 125)
		(*window).map.alpha.y -= 3;
	else if (key == 13)
		(*window).map.size.scroll_y += 15;
	else if (key == 1)
		(*window).map.size.scroll_y -= 15;
	else if (key == 2)
		(*window).map.size.scroll_x -= 15;
	else if (key == 0)
		(*window).map.size.scroll_x += 15;
	else if (key == 53)
	{
		close_window((*window).mlx_ptr, (*window).win_ptr);
		exit(0);
	}
	project_vectors(window);
	return (1);
 }
