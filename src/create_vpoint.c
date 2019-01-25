/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_vpoint.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 18:59:19 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 14:57:40 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point		create_vpoint(int x, int y, int z, t_map map)
{
	t_point		point;

	point.x = WX / 2 + x * (map.vec2d[0].x) + y * (map.vec2d[1].x) + z * (map.vec2d[2].x);
	point.y = WY / 2 + x * (map.vec2d[0].y) + y * (map.vec2d[1].y) + z * (map.vec2d[2].y);
	return (point);
}
