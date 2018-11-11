/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_put.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 13:05:55 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/10 19:02:42 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "../includes/fdf.h"

static void		base_0x0(t_map map, void *mlx_ptr, void *win_ptr)
{
	if (map.size.i)
	{
		line_put(create_point(WX / 2.0, WY / 2.0),
				create_point(WX / 2.0, WY / 2.0 - map.axes.y.a),
				mlx_ptr, win_ptr); // y_axe
		line_put(create_point(WX / 2.0, WY / 2.0),
				create_point(WX / 2.0 + map.axes.x.b, WY / 2.0 + map.axes.x.a),
				mlx_ptr, win_ptr); // x_axe
	}
}

void		map_put(t_map map, void *mlx_ptr, void *win_ptr)
{
	base_0x0(map, mlx_ptr, win_ptr);
}
