/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 19:02:51 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/08 15:23:42 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int			mouse_press(int button, int x, int y, t_window *window)
{
	x = 0;
	y = 0;
	window->mouse.button[button - 1] = 1;
	if (button == 4)
		window->map.unit -= window->map.unit / 10;
	else if (button == 5)
		window->map.unit += window->map.unit / 10;
	refresh_window(window);
	return (0);
}

static int			mouse_release(int button, int x, int y, t_window *window)
{
	x = 0;
	y = 0;
	window->mouse.button[button - 1] = 0;
	if (button == 1)
		mouse_rotation(0, 0, 1);
	return (0);
}

static int			mouse_move(int x, int y, t_window *window)
{
	window->mouse.x = x;
	window->mouse.y = y;
	if (window->mouse.button[0] == 1)
	{
		rotate(window);
		refresh_window(window);
	}
	return (0);
}

int					window_loop(t_window *window)
{
	window->img.ptr = mlx_new_image(window->mlx_ptr, WX, WY);
	mlx_hook(window->win_ptr, 6, 0, mouse_move, window);
	mlx_hook(window->win_ptr, 4, 0, mouse_press, window);
	mlx_hook(window->win_ptr, 5, 0, mouse_release, window);
	mlx_hook(window->win_ptr, 2, 0, key_press, window);
	mlx_hook(window->win_ptr, 3, 0, key_release, window);
	mlx_loop(window->mlx_ptr);
	return (1);
}
