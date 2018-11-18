/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 19:02:51 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/18 15:41:32 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	deal_key(int key, t_window *window)
{
	if (key == 126)
	{
		(*window).map.axes.y.a -= 3.0;
		(*window).map.axes.x.a += 3.0;
	}
	else if (key == 125)
	{
		(*window).map.axes.y.a += 3.0;
		(*window).map.axes.x.a -= 3.0;
	}
	else if (key == 124)
		(*window).map.axes.y.alpha += 5.0;
	else if (key == 123)
		(*window).map.axes.y.alpha -= 5.0;
	else if (key == 13)
		(*window).map.unit += 2.0;
	else if (key == 1)
		(*window).map.unit -= 2.0;
	mlx_clear_window((*window).mlx_ptr, (*window).win_ptr);
	(*window).map = map_put((*window).map, (*window).mlx_ptr, (*window).win_ptr);
	map_info(*window);
	return (0);
}

int			open_window(t_map map)
{
	t_window	window;

	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, WX, WY, "Fdf");
	window.map = map;
	window.map = map_put(map, window.mlx_ptr, window.win_ptr);
	map_info(window);
	mlx_key_hook(window.win_ptr, deal_key, &window);
	mlx_loop(window.mlx_ptr);
	return (1);
}
