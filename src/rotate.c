/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rotate.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/08 15:13:10 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/08 15:24:38 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			rotate(t_window *window)
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
