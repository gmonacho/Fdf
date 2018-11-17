/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_put.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 18:22:19 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 21:29:02 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_map		set_vectors(t_map map)
{
	map.axes.x.vector.vx = map.axes.x.x;
	map.axes.x.vector.vy = map.axes.x.y;
	map.axes.z.vector.vx = map.axes.z.x;
	map.axes.z.vector.vy =  map.axes.z.y;
	return (map);
}

static t_map		axes(t_map map, void *mlx_ptr, void *win_ptr)
{
	line_put(create_point(WX / 2.0, WY / 2.0),
			create_point(WX / 2.0, WY / 2.0 - map.axes.y.a),
			mlx_ptr, win_ptr); // y_axe
	map.axes.x.x = x_elipse(map.axes.x.a, map.axes.x.b, map.axes.y.alpha);
	map.axes.x.y = y_elipse(map.axes.x.a, map.axes.x.b, map.axes.x.x);
	if ((int)map.axes.y.alpha % 360 > 90 && (int)map.axes.y.alpha % 360 < 270)
		map.axes.x.x = -map.axes.x.x;
	if ((int)map.axes.y.alpha > 180 % 360 && (int)map.axes.y.alpha % 360 < 360)
		map.axes.x.y = -map.axes.x.y;
	line_put(create_point(WX / 2.0, WY / 2.0),
			create_point(WX / 2.0 + map.axes.x.x,
				WY / 2.0 + map.axes.x.y),
			mlx_ptr, win_ptr); // x_axe
	map.axes.z.x = x_elipse(map.axes.x.a, map.axes.x.b, map.axes.y.alpha + 90);
	map.axes.z.y = y_elipse(map.axes.x.a, map.axes.x.b, map.axes.z.x);
	if ((int)(map.axes.y.alpha + 90) % 360 > 90 && (int)(map.axes.y.alpha + 90) % 360 < 270)
		map.axes.z.x = -map.axes.z.x;
	if ((int)(map.axes.y.alpha + 90) % 360 > 180 && (int)(map.axes.y.alpha + 90) % 360 < 360)
		map.axes.z.y = -map.axes.z.y;
	line_put(create_point(WX / 2.0, WY / 2.0),
			create_point(WX / 2.0 + map.axes.z.x,
				WY / 2.0 + map.axes.z.y),
			mlx_ptr, win_ptr); // z_axe
	return (set_vectors(map));
}

void static		quadrix(t_map map, void *mlx_ptr, void *win_ptr)
{
	t_point		p1;
	t_point		p2;
	t_point		p3;
	t_point		p4;

	/*
	 * Carre Horizontal
	*/
	printf("a = %f b = %f\n", map.axes.x.a, map.axes.x.b);
	p1.x = WX / 2 + map.unit * (map.axes.z.vector.vx * 0 + map.axes.x.vector.vx * 0);
	p1.y = WY / 2 + map.unit * (map.axes.z.vector.vy * 0 + map.axes.x.vector.vy * 0);
	p2.x = WX / 2 + map.unit * (map.axes.z.vector.vx * 1 + map.axes.x.vector.vx * 0);
	p2.y = WY / 2 + map.unit * (map.axes.z.vector.vy * 1 + map.axes.x.vector.vy * 0);
	p3.x = WX / 2 + map.unit * (map.axes.z.vector.vx * 1 + map.axes.x.vector.vx * 1);
	p3.y = WY / 2 + map.unit * (map.axes.z.vector.vy * 1 + map.axes.x.vector.vy * 1);
	p4.x = WX / 2 + map.unit * (map.axes.z.vector.vx * 1 + map.axes.x.vector.vx * 0);
	p4.y = WY / 2 + map.unit * (map.axes.z.vector.vy * 1 + map.axes.x.vector.vy * 0);
	line_put(p1, p2, mlx_ptr, win_ptr);
	line_put(p2, p3, mlx_ptr, win_ptr);
	line_put(p3, p4, mlx_ptr, win_ptr);
	line_put(p4, p1, mlx_ptr, win_ptr);
}


t_map	map_put(t_map map, void *mlx_ptr, void *win_ptr)
{
	t_map new_map;

	print_elipse(map.axes.x.a, map.axes.x.b, mlx_ptr, win_ptr);
	new_map = axes(map, mlx_ptr, win_ptr);
	quadrix(new_map, mlx_ptr, win_ptr);
	return (new_map);
}
