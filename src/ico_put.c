/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ico_put.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 17:13:30 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 17:44:54 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_point		set_coord(t_map map, t_point point, double alpha)
{
	double		calpha;
	double		salpha;
	t_point		npoint;

	calpha = cos(radian(alpha));
	salpha = sin(radian(alpha));
	npoint.x = point.x * calpha - point.y * salpha;
	npoint.y = point.y * calpha + point.x * salpha;
	npoint = create_point(npoint.x + map.size.scroll_x, npoint.y + map.size.scroll_y);
	return (npoint);
}

static void		curr_line_put(int i, t_map map, void *mlx_ptr, void *win_ptr)
{
	int		j;
	double	r;
	t_point		p1;
	t_point		p2;
	double		alpha;

	alpha = 360 / map.size.j;
	r = map.unit * i;
	p1 = create_point(0 + map.size.scroll_x, -r + map.size.scroll_y);
	j = 0;
	while (j < map.size.j / 2)
	{
		p2 = set_coord(map, p1, alpha);
		line_put(p1, p2, mlx_ptr, win_ptr, 0xFFFFFF);
		p1 = set_coord(map, p2, alpha);
		line_put(p2, p1, mlx_ptr, win_ptr, 0xFFFFFF);
		j++;
	}
}

void		ico_put(t_map map, void *mlx_ptr, void *win_ptr)
{
	int			i;

	i = map.size.i;
	while (i)
	{
		curr_line_put(i, map, mlx_ptr, win_ptr);
		i--;
	}
}
