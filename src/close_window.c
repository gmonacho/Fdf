/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   close_window.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/09 16:01:05 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/09 16:04:16 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		close_window(void *mlx_ptr, void *win_ptr)
{
	if (mlx_ptr && win_ptr)
	{
		mlx_clear_window(mlx_ptr, win_ptr);
		mlx_destroy_window(mlx_ptr, win_ptr);
		return (1);
	}
	else
		return (0);
}
