/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_put.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 15:31:42 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 14:50:24 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		swap_point(t_point *p1, t_point *p2)
{
	t_point		tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void			line_put(t_point p1, t_point p2, void *mlx_ptr, void *win_ptr)
{
	double		dx;
	double		dy;
	double		x;
	double		y;
	double		e;

	if (p1.x > p2.x)
		swap_point(&p1, &p2);
	dx = ft_abs(p2.x - p1.x);
	dy = ft_abs(p2.y - p1.y);
	x = p1.x;
	y = p1.y;
	e = (p1.x - p2.x == 0) ? 0 : dy / dx;
	if (p1.x - p2.x)
	{
		while (x <= p2.x)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00FF00);
			x++;
			y += e;
		}
	}
	else
	{
		if (p1.y > p2.y)
			swap_point(&p1, &p2);
		y = p1.y;
		while (y <= p2.y)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00FF00);
			y++;
		}
	}
}
