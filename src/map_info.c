/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_info.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 22:18:46 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 17:38:03 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_info(t_window window)
{
	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 30, 0xFFFFFF, ft_strjoin("Unit = ", ft_itoa(window.map.unit)));
	/*mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 50, 0xFFFFFF, ft_strjoin("3D X.x = ", ft_itoa(window.map.vec_tmp[0].x)));
	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 70, 0xFFFFFF, ft_strjoin("3D X.y = ", ft_itoa(window.map.vec_tmp[0].y)));
	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 90, 0xFFFFFF, ft_strjoin("3D X.z = ", ft_itoa(window.map.vec_tmp[0].z)));
	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 110, 0xFFFFFF, ft_strjoin("3D Y.x = ", ft_itoa(window.map.vec_tmp[1].x)));
	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 130, 0xFFFFFF, ft_strjoin("3D Y.y = ", ft_itoa(window.map.vec_tmp[1].y)));
	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 150, 0xFFFFFF, ft_strjoin("3D Y.z = ", ft_itoa(window.map.vec_tmp[1].z)));
	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 170, 0xFFFFFF, ft_strjoin("3D Z.x = ", ft_itoa(window.map.vec_tmp[2].x)));
	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 190, 0xFFFFFF, ft_strjoin("3D Z.y = ", ft_itoa(window.map.vec_tmp[2].y)));
	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 210, 0xFFFFFF, ft_strjoin("3D Z.s = ", ft_itoa(window.map.vec_tmp[2].z)));*/
	/*	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 70, 0xFFFFFF, ft_strjoin("vx.x = ", ft_itoa(window.map.vec[0].x)));
		mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 90, 0xFFFFFF, ft_strjoin("vx.y = ", ft_itoa(window.map.vec[0].y)));
		mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 110, 0xFFFFFF, ft_strjoin("vy.x = ", ft_itoa(window.map.vec[1].x)));
		mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 130, 0xFFFFFF, ft_strjoin("vy.y = ", ft_itoa(window.map.vec[1].y)));
		mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 150, 0xFFFFFF, ft_strjoin("vz.x = ", ft_itoa(window.map.vec[2].x)));
		mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 170, 0xFFFFFF, ft_strjoin("vz.y = ", ft_itoa(window.map.vec[2].y)));*/
	/*	mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 70, 0xFFFFFF, ft_strjoin("vx.x = ", ft_itoa(window.map.vec[0].x * window.map.unit)));
		mlx_string_put(window.mlx_ptr, window.win_ptr, 130, 70, 0xFFFFFF, ft_strjoin("vx.y = ", ft_itoa(window.map.vec[0].y * window.map.unit)));
		mlx_string_put(window.mlx_ptr, window.win_ptr, 230, 70, 0xFFFFFF, ft_strjoin("vx.z = ", ft_itoa(window.map.vec[0].z * window.map.unit)));

		mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 90, 0xFFFFFF, ft_strjoin("vy.x = ", ft_itoa(window.map.vec[1].x * window.map.unit)));
		mlx_string_put(window.mlx_ptr, window.win_ptr, 130, 90, 0xFFFFFF, ft_strjoin("vy.y = ", ft_itoa(window.map.vec[1].y * window.map.unit)));
		mlx_string_put(window.mlx_ptr, window.win_ptr, 230, 90, 0xFFFFFF, ft_strjoin("vy.z = ", ft_itoa(window.map.vec[1].z * window.map.unit)));

		mlx_string_put(window.mlx_ptr, window.win_ptr, 30, 110, 0xFFFFFF, ft_strjoin("vz.x = ", ft_itoa(window.map.vec[2].x * window.map.unit)));
		mlx_string_put(window.mlx_ptr, window.win_ptr, 130, 110, 0xFFFFFF, ft_strjoin("vz.y = ", ft_itoa(window.map.vec[2].y * window.map.unit)));
		mlx_string_put(window.mlx_ptr, window.win_ptr, 230, 110, 0xFFFFFF, ft_strjoin("vz.z = ", ft_itoa(window.map.vec[2].z * window.map.unit)));*/
}
