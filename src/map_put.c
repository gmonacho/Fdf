/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_put.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 18:22:19 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/08 16:00:43 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		disp_map(t_map map, t_window *window)
{
	corner1(map, window);
	corner2(map, window);
	corner3(map, window);
	corner4(map, window);
}

void			map_put(t_map map, t_window *window)
{
	disp_map(map, window);
}
