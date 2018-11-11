/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 19:02:51 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/10 19:26:07 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	deal_key(int key, t_window *window)
{
	if (key == 126)
	{
		(*window).map.axes.y.a -= 1.0;
		(*window).map.axes.x.a += 1.0;
	}
	else if (key == 125)
	{
		(*window).map.axes.y.a += 1.0;
		(*window).map.axes.x.a -= 1.0;
	}
/*	if (key == 124)
		(*window).map.rotate.x_ratio += 0.1;
	else if (key == 123)
		(*window).map.rotate.x_ratio -= 0.1;*/
	mlx_clear_window((*window).mlx_ptr, (*window).win_ptr);
	map_put((*window).map, (*window).mlx_ptr, (*window).win_ptr);
	return (0);
}

int		open_window(t_map map)
{
	t_window	window;

	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, WX, WY, "Fdf");
	window.map = map;
	map_put(map, window.mlx_ptr, window.win_ptr);
	mlx_key_hook(window.win_ptr, deal_key, &window);
	mlx_loop(window.mlx_ptr);
	return (1);
}
