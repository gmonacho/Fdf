/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   project_vectors.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/25 14:37:52 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/08 15:54:25 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_vec2d	dddtodd(t_vec3d vec, double unit)
{
	t_vec2d		new_vec;
	double		a1;
	double		a2;
	double		b1;
	double		b2;

	a1 = cos(radian(90));
	a2 = sin(radian(90));
	b1 = cos(radian(90));
	b2 = sin(radian(90));
	new_vec.x = unit * (a1 * vec.y + a2 * vec.y);
	new_vec.y = unit * (b2 * (b2 * vec.x - b1 * vec.y) + b1 * vec.z);
	return (new_vec);
}

void			project_vectors(t_window *window)
{
	int			i;

	i = 0;
	while (i < 3)
	{
		window->map.vec2d[i] = dddtodd(window->map.vec[i], window->map.unit);
		i++;
	}
}
