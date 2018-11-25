/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   axes_put.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 15:43:10 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/24 09:32:01 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_map	ax_put(t_map map, void *mlx_ptr, void *win_ptr)
{
	line_put(create_point(0, 0), create_point(map.vec[0].x, map.vec[0].y), mlx_ptr, win_ptr, 0xFFFFFF);
	return (map);
}

static t_map	ay_put(t_map map, void *mlx_ptr, void *win_ptr)
{
	line_put(create_point(0, 0), create_point(map.vec[1].x, map.vec[1].y), mlx_ptr, win_ptr, 0xFFFFFF);
	return (map);
}

static t_map	az_put(t_map map, void *mlx_ptr, void *win_ptr)
{
	line_put(create_point(0, 0), create_point(map.vec[2].x, map.vec[2].y), mlx_ptr, win_ptr, 0xFFFFFF);
	return (map);
}

void		axes_put(t_map map, void *mlx_ptr, void *win_ptr)
{
	map = ax_put(map, mlx_ptr, win_ptr);
	map = az_put(map, mlx_ptr, win_ptr);
	map = ay_put(map, mlx_ptr, win_ptr);
}
