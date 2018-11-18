/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   axes_put.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 15:43:10 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/18 16:03:33 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_map		set_vectors(t_map map)
{
	map.vec[0].x = map.axes.x.x;
	map.vec[0].y = map.axes.x.y;
	map.vec[1].x = map.axes.z.x;
	map.vec[1].y = map.axes.z.y;
	map.vec[2].x = 0;
	map.vec[2].y = map.axes.y.a;
	return (map);
}

static t_map	ax_put(t_map map, void *mlx_ptr, void *win_ptr)
{
	map.axes.x.x = x_elipse(map.axes.x.a, map.axes.x.b, map.axes.y.alpha);
	map.axes.x.y = y_elipse(map.axes.x.a, map.axes.x.b, map.axes.x.x);
	if ((int)map.axes.y.alpha % 360 > 90 && (int)map.axes.y.alpha % 360 < 270)
		map.axes.x.x = -map.axes.x.x;
	if ((int)map.axes.y.alpha > 180 % 360
			&& (int)map.axes.y.alpha % 360 < 360)
		map.axes.x.y = -map.axes.x.y;
	line_put(create_point(WX / 2.0, WY / 2.0),
			create_point(WX / 2.0 + map.axes.x.x,
				WY / 2.0 + map.axes.x.y),
			mlx_ptr, win_ptr); // x_axe
	return (map);
}

static t_map	ay_put(t_map map, void *mlx_ptr, void *win_ptr)
{
	line_put(create_point(WX / 2.0, WY / 2.0),
			create_point(WX / 2.0, WY / 2.0 - map.axes.y.a),
			mlx_ptr, win_ptr);
	return (map);
}

static t_map	az_put(t_map map, void *mlx_ptr, void *win_ptr)
{
	
	map.axes.z.x = x_elipse(map.axes.x.a, map.axes.x.b, map.axes.y.alpha + 90);
	map.axes.z.y = y_elipse(map.axes.x.a, map.axes.x.b, map.axes.z.x);
	if ((int)(map.axes.y.alpha + 90) % 360 > 90
			&& (int)(map.axes.y.alpha + 90) % 360 < 270)
		map.axes.z.x = -map.axes.z.x;
	if ((int)(map.axes.y.alpha + 90) % 360 > 180
			&& (int)(map.axes.y.alpha + 90) % 360 < 360)
		map.axes.z.y = -map.axes.z.y;
	line_put(create_point(WX / 2.0, WY / 2.0),
			create_point(WX / 2.0 + map.axes.z.x,
				WY / 2.0 + map.axes.z.y),
			mlx_ptr, win_ptr); // z_axe
	return (map);
}

t_map		axes_put(t_map map, void *mlx_ptr, void *win_ptr)
{
	map = ax_put(map, mlx_ptr, win_ptr);
	map = az_put(map, mlx_ptr, win_ptr);
	map = ay_put(map, mlx_ptr, win_ptr);
	return (set_vectors(map));
}
