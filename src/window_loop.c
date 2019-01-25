/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 19:02:51 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 16:53:33 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void			scroll(t_window *window)
{
	if (window->keyboard[13])
		window->map.cursor.y -= 0.1;
	else if (window->keyboard[1])
		window->map.cursor.y += 0.1;
	else if (window->keyboard[0])
		window->map.cursor.x -= 0.1;
	else if (window->keyboard[2])
		window->map.cursor.x += 0.1;
}

static void			refresh_window(t_window *window)
{
	mlx_clear_window((*window).mlx_ptr, (*window).win_ptr);
	scroll(window);
	project_vectors(window);
	axes_put((*window).map, (*window).mlx_ptr, (*window).win_ptr);
	map_put(window->map, window->mlx_ptr, window->win_ptr);
	map_info(*window);
}

/*static int	deal_key(int key, t_window *window)
{
	event(key, window);
	refresh_window(window);
	return (0);
}*/

static void	rotate(t_window *window)
{
	int			i;
	t_vec2d		rotation;

	rotation = mouse_rotation(window->mouse.x, window->mouse.y);
	i = 0;
	while (i < 3)
	{
		window->map.vec[i] = rotate_z(window->map.vec[i], -rotation.x);
		window->map.vec[i] = rotate_y(window->map.vec[i], -rotation.y);
		i++;
	}
}

/*static int	deal_mkey(int button, int x, int y, t_window *window)
{
	x = 0;
	y = 0;
	if (button == 4)
		window->map.unit -= 1;
	else if (button == 5)
		window->map.unit += 1;
	event(0, window);
	refresh_window(window);
	return (0);
}*/

static int		key_press(int keycode, t_window *window)
{
	window->keyboard[keycode] = 1;
	return (0);
}

static int		key_release(int keycode, t_window *window)
{
	window->keyboard[keycode] = 0;
	return (0);
}

static int			mouse_press(int button, int x, int y, t_window *window)
{
	x = 0;
	y = 0;
	window->mouse.button[button - 1] = 1;
	if (button == 4)
		window->map.unit -= 1;
	else if (button == 5)
		window->map.unit += 1;
	refresh_window(window);
	return (0);
}

static int			mouse_release(int button, int x, int y, t_window *window)
{
	x = 0;
	y = 0;
	window->mouse.button[button - 1] = 0;
	return (0);
}

static int			mouse_move(int x, int y, t_window *window)
{
	window->mouse.x = x;
	window->mouse.y = y;
	if (window->mouse.button[0] == 1)
		rotate(window);
	refresh_window(window);
	return (0);
}

int			window_loop(t_window *window)
{
	map_put(window->map, window->mlx_ptr, window->win_ptr);
	map_info(*window);
	mlx_hook(window->win_ptr, 6, 0, mouse_move, window); // mlx_move deplacement de la souris
	mlx_hook(window->win_ptr, 4, 0, mouse_press, window); // test mouse_press
	mlx_hook(window->win_ptr, 5, 0, mouse_release, window); // test mouse_release
	mlx_hook(window->win_ptr, 2, 0, key_press, window); // test key_press;
	mlx_hook(window->win_ptr, 3, 0, key_release, window); // test key_release;
	//mlx_mouse_hook(window->win_ptr, deal_mkey, &window);
	//mlx_key_hook(window->win_ptr, deal_key, window);
	mlx_loop(window->mlx_ptr);
	return (1);
}
