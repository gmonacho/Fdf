/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_vpoint.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 15:06:02 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 15:39:11 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point		create_vpoint(double ix, double iz, double iy, t_map map)
{
	t_point		new_point;
	t_vector	vx;
	t_vector	vy;
	t_vector	vz;

	vx = map.vec[0];
	vy = map.vec[1];
	vz = map.vec[2];
	ix = ix - map.size.j / 2.0;
	iz = iz + map.size.i / 2.0;
	new_point.x = WX / 2 + map.unit * (ix * vx.x + iy * vy.x * map.size.height_ratio + iz * vz.x) + map.size.scroll_x;
	new_point.y = WY / 2 + map.unit * (ix * vx.y + iy * vy.y * map.size.height_ratio + iz * vz.y) + map.size.scroll_y;
	return (new_point);
}
