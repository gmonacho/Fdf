/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_elipse.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 19:48:26 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 18:49:13 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_elipse(double a, double b, void *mlx_ptr, void *win_ptr)
{
	double		x;
	double		y;

	x = -b;
	while (x <= b)
	{
		y = y_elipse(a, b, x);
		mlx_pixel_put(mlx_ptr, win_ptr, WX / 2 - x, WY / 2 - y, 0x0000FF);
		x++;
	}
	x = -b;
	while (x <= b)
	{
		y = -y_elipse(a, b, x);
		mlx_pixel_put(mlx_ptr, win_ptr, WX / 2 - x, WY / 2 - y, 0x0000FF);
		x++;
	}
}
