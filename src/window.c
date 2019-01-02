/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 19:02:51 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 18:32:56 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"


static void			refresh_window(t_window *window)
{
	mlx_clear_window((*window).mlx_ptr, (*window).win_ptr);
	//map_put((*window).map, (*window).mlx_ptr, (*window).win_ptr);
	map_info(*window);
}

static int	deal_key(int key, t_window *window)
{
	event(key, window);
	refresh_window(window);
	return (0);
}

static int	deal_mkey(int button, int x, int y, t_window *window)
{
	x = 0;
	y = 0;
	if (button == 4)
		(*window).map.unit -= 1;
	else if (button == 5)
		(*window).map.unit += 1;
	mlx_clear_window((*window).mlx_ptr, (*window).win_ptr);
	refresh_window(window);
	map_info(*window);
	return (0);
}

int			open_window(t_map map)
{
	t_window	window;

	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, WX, WY, "Fdf");
	window.map = map;
	//map_put(map, window.mlx_ptr, window.win_ptr);
	map_info(window);
	mlx_key_hook(window.win_ptr, deal_key, &window);
	mlx_mouse_hook(window.win_ptr, deal_mkey, &window);
	mlx_pixel_put(window.mlx_ptr, window.win_ptr, 100, 50, 0x00FF00);
	mlx_loop(window.mlx_ptr);
	return (1);
}
