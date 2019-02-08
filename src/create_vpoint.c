/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_vpoint.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 18:59:19 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 17:55:33 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		get_color(int z, t_map map)
{
	int		i;
	double	r;
	double	g;
	double	b;

	r = 0.0;
	g = 0.0;
	b = 255.0;
	i = 0;
	while (i < z)
	{
		r += map.color.incre;
		b -= map.color.incre;
		i++;
	}
	return (((int)r << 16) | ((int)g << 8) | ((int)b << 0));
}

t_point			create_vpoint(int x, int y, int z, t_map map)
{
	t_point		point;

	point.x = WX / 2 + x * (map.vec2d[0].x) +
		y * (map.vec2d[1].x) + z * map.h_ratio * (map.vec2d[2].x);
	point.y = WY / 2 + x * (map.vec2d[0].y) +
		y * (map.vec2d[1].y) + z * map.h_ratio * (map.vec2d[2].y);
	point.color = get_color(z, map);
	return (point);
}
