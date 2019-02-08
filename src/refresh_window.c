/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   refresh_window.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/08 15:07:40 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/08 15:39:24 by gmonacho    ###    #+. /#+    ###.fr     */
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

static void			key_events(t_window *window)
{
	if (window->keyboard[13] && window->mouse.button[1])
		window->map.h_ratio += window->map.h_ratio / 10;
	else if (window->keyboard[1] && window->mouse.button[1])
		window->map.h_ratio -= window->map.h_ratio / 10;
	if (window->keyboard[53])
	{
		close_window(window);
		exit(0);
	}
}

void				refresh_window(t_window *window)
{
	mlx_destroy_image(window->mlx_ptr, window->img.ptr);
	window->img.ptr = mlx_new_image(window->mlx_ptr, WX, WY);
	window->img.tab = (int*)mlx_get_data_addr(window->img.ptr,
			&(window->img.bpp), &(window->img.s_l), &(window->img.endian));
	key_events(window);
	scroll(window);
	project_vectors(window);
	map_put(window->map, window);
	axes_put(window->map, window);
	mlx_put_image_to_window(window->img.tab,
			window->win_ptr, window->img.ptr, 0, 0);
}
