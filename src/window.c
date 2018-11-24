/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 19:02:51 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/24 04:40:32 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_vector		set_vector(t_vector vec, double alpha)
{
	t_vector	new_vec;
	double		calpha;
	double		salpha;

	calpha = cos(radian(alpha));
	salpha = sin(radian(alpha));
	new_vec.x = vec.x * calpha - vec.y * salpha;
	new_vec.y = vec.y * calpha + vec.x * salpha;
	return (new_vec);
}

static int	deal_key(int key, t_window *window)
{

	if (key == 124)
	{
		(*window).map.vec[1].alpha = -3;
		(*window).map.vec[0] = set_vector((*window).map.vec[0], (*window).map.vec[1].alpha);
		(*window).map.vec[2] = set_vector((*window).map.vec[2], (*window).map.vec[1].alpha);
		(*window).map.vec[1].alpha = 0;
	}
	else if (key == 123)
	{
		(*window).map.vec[1].alpha = 3;
		(*window).map.vec[0] = set_vector((*window).map.vec[0], (*window).map.vec[1].alpha);
		(*window).map.vec[2] = set_vector((*window).map.vec[2], (*window).map.vec[1].alpha);
		(*window).map.vec[1].alpha = 0;
	}
	else if (key == 126)
	{
		(*window).map.vec[0].alpha = 3;
		(*window).map.vec[1] = set_vector((*window).map.vec[1], (*window).map.vec[0].alpha);
		(*window).map.vec[2] = set_vector((*window).map.vec[2], (*window).map.vec[0].alpha);
		(*window).map.vec[0].alpha = 0;
	}
	else if (key == 125)
	{
		(*window).map.vec[0].alpha = -3;
		(*window).map.vec[1] = set_vector((*window).map.vec[1], (*window).map.vec[0].alpha);
		(*window).map.vec[2] = set_vector((*window).map.vec[2], (*window).map.vec[0].alpha);
		(*window).map.vec[0].alpha = 0;
	}
	mlx_clear_window((*window).mlx_ptr, (*window).win_ptr);
	map_put((*window).map, (*window).mlx_ptr, (*window).win_ptr);
	map_info(*window);
	return (0);
}

static int	deal_mkey(int button, int x, int y, t_window *window)
{
	if (button == 4)
		(*window).map.unit -= 0.50;
	else if (button == 5)
		(*window).map.unit += 0.50;
	printf("%d %d %d\n", button, x, y);
	mlx_clear_window((*window).mlx_ptr, (*window).win_ptr);
	map_put((*window).map, (*window).mlx_ptr, (*window).win_ptr);
	map_info(*window);
	return (0);
}

int			open_window(t_map map)
{
	t_window	window;

	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, WX, WY, "Fdf");
	window.map = map;
	map_put(map, window.mlx_ptr, window.win_ptr);
	map_info(window);
	mlx_key_hook(window.win_ptr, deal_key, &window);
	mlx_mouse_hook(window.win_ptr, deal_mkey, &window);
	mlx_loop(window.mlx_ptr);
	return (1);
}
