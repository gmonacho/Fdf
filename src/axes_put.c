/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   axes_put.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 15:43:10 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 17:54:53 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		ax_put(t_map map, t_window *window)
{
	line_put(create_point(WX / 2, WY / 2),
			create_point(WX / 2 + map.vec2d[0].x,
			WY / 2 + map.vec2d[0].y), window);
}

static void		ay_put(t_map map, t_window *window)
{
	line_put(create_point(WX / 2, WY / 2),
			create_point(WX / 2 + map.vec2d[1].x,
			WY / 2 + map.vec2d[1].y), window);
}

static void		az_put(t_map map, t_window *window)
{
	line_put(create_point(WX / 2, WY / 2),
			create_point(WX / 2 + map.vec2d[2].x,
			WY / 2 + map.vec2d[2].y), window);
}

void			axes_put(t_map map, t_window *window)
{
	ax_put(map, window);
	az_put(map, window);
	ay_put(map, window);
}
