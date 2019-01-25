/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   axes_put.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 15:43:10 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 14:51:36 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		info_put(t_vec2d *vec2d, void *mlx_ptr, void *win_ptr)
{
	mlx_string_put(mlx_ptr, win_ptr, 30, 230, 0xFF0000, ft_strjoin("2D X.x = ", ft_itoa(vec2d[0].x)));
	mlx_string_put(mlx_ptr, win_ptr, 30, 250, 0xFF0000, ft_strjoin("2D X.y = ", ft_itoa(vec2d[0].y)));
	mlx_string_put(mlx_ptr, win_ptr, 30, 270, 0x00FF00, ft_strjoin("2D Y.x = ", ft_itoa(vec2d[1].x)));
	mlx_string_put(mlx_ptr, win_ptr, 30, 290, 0x00FF00, ft_strjoin("2D Y.y = ", ft_itoa(vec2d[1].y)));
	mlx_string_put(mlx_ptr, win_ptr, 30, 310, 0x0000FF, ft_strjoin("2D Z.x = ", ft_itoa(vec2d[2].x)));
	mlx_string_put(mlx_ptr, win_ptr, 30, 330, 0x0000FF, ft_strjoin("2D Z.y = ", ft_itoa(vec2d[2].y)));
}

static void		ax_put(t_map map, void *mlx_ptr, void *win_ptr)
{
	line_put(create_point(WX / 2, WY / 2), create_point(WX / 2 + map.vec2d[0].x, WY / 2 + map.vec2d[0].y), mlx_ptr, win_ptr, 0xFF0000);
}

static void		ay_put(t_map map, void *mlx_ptr, void *win_ptr)
{
	line_put(create_point(WX / 2, WY / 2), create_point(WX / 2 + map.vec2d[1].x, WY / 2 + map.vec2d[1].y), mlx_ptr, win_ptr, 0x00FF00);
}

static void		az_put(t_map map, void *mlx_ptr, void *win_ptr)
{
	line_put(create_point(WX / 2, WY / 2), create_point(WX / 2 + map.vec2d[2].x, WY / 2 + map.vec2d[2].y), mlx_ptr, win_ptr, 0x0000FF);
}

void		axes_put(t_map map, void *mlx_ptr, void *win_ptr)
{
	ax_put(map, mlx_ptr, win_ptr);
	az_put(map, mlx_ptr, win_ptr);
	ay_put(map, mlx_ptr, win_ptr);
	info_put(map.vec2d, mlx_ptr, win_ptr);
}
