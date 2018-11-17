/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_put.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 15:31:42 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 20:33:47 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			print_v_line(t_point p1, t_point p2, void *mlx_ptr, void *win_ptr)
{
	int		x;
	int		y;

	x = p1.x;
	if (p1.y < p2.y)
	{
		y = p1.y;
		while (y <= p2.y)
			mlx_pixel_put(mlx_ptr, win_ptr, x, y++, 0x00FF00);
	}
	else
	{	
		y = p1.y;
		while (y >= p2.y)
			mlx_pixel_put(mlx_ptr, win_ptr, x, y--, 0x00FF00);
	}
}

void			line_put(t_point p1, t_point p2, void *mlx_ptr, void *win_ptr)
{
	double		x;
	double		y;
	double		e;

	x = p1.x;
	y = p1.y;
	e = ft_abs(p2.y - p1.y) / ft_abs(p2.x - p1.x);
	if (p1.y > p2.y)
		e = -e;
	if (p1.x < p2.x)
	{
		while (x <= p2.x)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00FF00);
			x += 1;
			y += e;
		}
	}
	else if (p1.x > p2.x)
	{	
		while (x >= p2.x)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00FF00);
			x -= 1;
			y += e;
		}
	}
	else
		print_v_line(p1, p2, mlx_ptr, win_ptr);
}
