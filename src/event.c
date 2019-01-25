/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/09 16:12:07 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 14:48:18 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "../includes/fdf.h"

static void rotate(t_window *window, int key)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (key == 124)
			window->map.vec[i] = rotate_x(window->map.vec[i], 1);
		else if (key == 123)
			window->map.vec[i] = rotate_x(window->map.vec[i], -1);
		else if (key == 126)
			window->map.vec[i] = rotate_y(window->map.vec[i], 1);
		else if (key == 125)
			window->map.vec[i] = rotate_y(window->map.vec[i], -1);
		else if (key == 258)
			window->map.vec[i] = rotate_z(window->map.vec[i], 1);
		else if (key == 269)
			window->map.vec[i] = rotate_z(window->map.vec[i], -1);
		i++;
	}
}

int		event(int key, t_window *window)
{
	rotate(window, key);
	project_vectors(window);
	if (key == 13)
		(*window).map.size.scroll_y += 15;
	else if (key == 1)
		(*window).map.size.scroll_y -= 15;
	else if (key == 2)
		(*window).map.size.scroll_x -= 15;
	else if (key == 0)
		(*window).map.size.scroll_x += 15;
	else if (key == 53)
	{
		close_window((*window).mlx_ptr, (*window).win_ptr);
		exit(0);
	}
	return (1);
}
