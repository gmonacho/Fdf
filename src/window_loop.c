/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 19:02:51 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 17:30:43 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void			scroll(t_window *window)
{
	if (window->keyboard[13] && !(window->mouse.button[1]))
		window->map.cursor.y -= 1;
	else if (window->keyboard[1] && !(window->mouse.button[1]))
		window->map.cursor.y += 1;
	else if (window->keyboard[0])
		window->map.cursor.x -= 1;
	else if (window->keyboard[2])
		window->map.cursor.x += 1;
	if (window->map.cursor.x < 0)
		window->map.cursor.x = 0;
	else if (window->map.cursor.x >= window->map.size.j)
		window->map.cursor.x = window->map.size.j - 1;
	if (window->map.cursor.y < 0)
		window->map.cursor.y = 0;
	else if (window->map.cursor.y >= window->map.size.i)
		window->map.cursor.y = window->map.size.i - 1;
}

static void			key_event(t_window *window)
{
	if (window->keyboard[13] && window->mouse.button[1])
		window->map.h_ratio += window->map.h_ratio / 10;
	else if (window->keyboard[1] && window->mouse.button[1])
		window->map.h_ratio -= window->map.h_ratio / 10;
}

static void			refresh_window(t_window *window)
{
	mlx_destroy_image(window->mlx_ptr, window->img.ptr);
	window->img.ptr = mlx_new_image(window->mlx_ptr, WX, WY);
	window->img.tab = (int*)mlx_get_data_addr(window->img.ptr, &(window->img.bpp), &(window->img.s_l), &(window->img.endian));
	//mlx_clear_window((*window).mlx_ptr, (*window).win_ptr);
	key_event(window);
	scroll(window);
	project_vectors(window);
	axes_put(window->map, window);
	map_put(window->map, window);
	//map_info(*window);
	mlx_put_image_to_window(window->img.tab, window->win_ptr, window->img.ptr, 0, 0);
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

	rotation = mouse_rotation(window->mouse.x, window->mouse.y, 0);
	i = 0;
	while (i < 3)
	{
		window->map.vec[i] = rotate_x(window->map.vec[i], rotation.x);
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
	refresh_window(window);
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
		rotate(window);
	refresh_window(window);
	return (0);
}

int			window_loop(t_window *window)
{
	window->img.ptr = mlx_new_image(window->mlx_ptr, WX, WY);
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
