/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/09 16:12:07 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/09 16:41:12 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 16:44:49 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/09 16:05:56 by gmonacho    ###    #+. /#+    ###.fr     */
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

static void	change_vectors(t_window *window, int alpha)
{
	(*window).map.vec[1].alpha = alpha;
	(*window).map.vec[0] = set_vector((*window).map.vec[0], (*window).map.vec[1].alpha);
	(*window).map.vec[2] = set_vector((*window).map.vec[2], (*window).map.vec[1].alpha);
	(*window).map.vec[1].alpha = 0;
}

int		event(int key, t_window *window)
{
	if (key == 124)
		change_vectors(window, -3);
	else if (key == 123)
		change_vectors(window, 3);
	else if (key == 126)
		(*window).map.size.height_ratio += 0.05;
	else if (key == 125)
		(*window).map.size.height_ratio -= 0.05;
	else if (key == 13)
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
