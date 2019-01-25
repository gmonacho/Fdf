/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_put.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 18:05:06 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 16:08:28 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			line_put(t_point p1, t_point p2, void *mlx_ptr, void *win_ptr, int color)
{
	int			i;
	int			nb_point = 0;
	double		dx;
	double		dy;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (ft_abs(dx) > ft_abs(dy))
	{
		nb_point = ft_abs(dx);
		dy /= ft_abs(dx);
		dx /= ft_abs(dx);
	}
	else
	{
		nb_point = ft_abs(dy);
		dx /= ft_abs(dy);
		dy /= ft_abs(dy);
	}
	i = -1;
	while (i++ < nb_point)
		mlx_pixel_put(mlx_ptr, win_ptr, p1.x + dx * i, p1.y + dy * i, color);
}
