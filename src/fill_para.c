/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_para.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/24 06:13:32 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/26 17:33:59 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fill_para(t_point p1, t_point p2, t_point p3, void *mlx_ptr, void *win_ptr)
{
	int			i;
	int			nb_point;
	double		dx;
	double		dy;

	dx = p3.x - p1.x;
	dy = p3.y - p1.y;
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
		line_put(create_rpoint(p1.x + dx * i, p1.y + dy * i), create_rpoint(p2.x + dx * i, p2.y + dy * i), mlx_ptr, win_ptr, 0xAAAAAA);
}
