/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_info.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 22:18:46 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/24 01:45:18 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_info(t_window window)
{
	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 30, 0xFFFFFF, ft_strjoin("Unit = ", ft_itoa(window.map.unit)));
	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 70, 0xFFFFFF, ft_strjoin("vx.x = ", ft_itoa(window.map.vec[0].x)));
	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 90, 0xFFFFFF, ft_strjoin("vx.y = ", ft_itoa(window.map.vec[0].y)));
	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 110, 0xFFFFFF, ft_strjoin("vy.x = ", ft_itoa(window.map.vec[1].x)));
	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 130, 0xFFFFFF, ft_strjoin("vy.y = ", ft_itoa(window.map.vec[1].y)));
	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 150, 0xFFFFFF, ft_strjoin("vz.x = ", ft_itoa(window.map.vec[2].x)));
	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 170, 0xFFFFFF, ft_strjoin("vz.y = ", ft_itoa(window.map.vec[2].y)));
}
