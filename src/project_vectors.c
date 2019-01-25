/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   project_vectors.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/25 14:37:52 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 14:49:00 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_vec2d	dddtodd(t_vec3d vec, int unit)
{
	t_vec2d		new_vec;
	double		A1;
	double		A2;
	double		B1;
	double		B2;

	A1 = cos(radian(30));
	A2 = sin(radian(30));
	B1 = cos(radian(10));
	B2 = sin(radian(10));
	new_vec.x = unit * (A1 * vec.y + A2 * vec.y);
	new_vec.y = unit * (B2 * (A2 * vec.x - A1 * vec.y) + B1 * vec.z);
	return (new_vec);
}

void			project_vectors(t_window *window)
{
	int			i;

	/*
		mlx_string_put((*window).mlx_ptr, (*window).win_ptr, 30, 50, 0xFF0000, ft_strjoin("3D X.x = ", ft_itoa(vec_tmp[0].x * 100)));
		mlx_string_put((*window).mlx_ptr, (*window).win_ptr, 30, 70, 0xFF0000, ft_strjoin("3D X.y = ", ft_itoa(vec_tmp[0].y * 100)));
		mlx_string_put((*window).mlx_ptr, (*window).win_ptr, 30, 90, 0xFF0000, ft_strjoin("3D X.z = ", ft_itoa(vec_tmp[0].z * 100)));
		mlx_string_put((*window).mlx_ptr, (*window).win_ptr, 30, 110, 0x00FF00, ft_strjoin("3D Y.x = ", ft_itoa(vec_tmp[1].x * 100)));
		mlx_string_put((*window).mlx_ptr, (*window).win_ptr, 30, 130, 0x00FF00, ft_strjoin("3D Y.y = ", ft_itoa(vec_tmp[1].y * 100)));
		mlx_string_put((*window).mlx_ptr, (*window).win_ptr, 30, 150, 0x00FF00, ft_strjoin("3D Y.z = ", ft_itoa(vec_tmp[1].z * 100)));
		mlx_string_put((*window).mlx_ptr, (*window).win_ptr, 30, 170, 0x0000FF, ft_strjoin("3D Z.x = ", ft_itoa(vec_tmp[2].x * 100)));
		mlx_string_put((*window).mlx_ptr, (*window).win_ptr, 30, 190, 0x0000FF, ft_strjoin("3D Z.y = ", ft_itoa(vec_tmp[2].y * 100)));
		mlx_string_put((*window).mlx_ptr, (*window).win_ptr, 30, 210, 0x0000FF, ft_strjoin("3D Z.s = ", ft_itoa(vec_tmp[2].z * 100)));
	*/
	i = 0;
	while (i < 3)
	{
		window->map.vec2d[i] = dddtodd(window->map.vec[i], window->map.unit);
		i++;
	}
}
