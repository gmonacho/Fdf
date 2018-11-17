/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_info.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 22:18:46 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 17:34:55 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_info(t_window window)
{
	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 30, 0xFFFFFF, ft_strjoin("Unit = ", ft_itoa(window.map.unit)));
	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 50, 0xFFFFFF, ft_strjoin("Vert_Unit = ", ft_itoa(window.map.axes.y.a)));
	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 70, 0xFFFFFF, ft_strjoin("xVX = ", ft_itoa(window.map.axes.x.vector.vx)));
	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 90, 0xFFFFFF, ft_strjoin("xVY = ", ft_itoa(window.map.axes.x.vector.vy)));
}
