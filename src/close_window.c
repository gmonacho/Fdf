/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   close_window.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/09 16:01:05 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/31 21:00:10 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		close_window(t_window *window)
{
	if (window->mlx_ptr && window->win_ptr)
	{
		mlx_clear_window(window->mlx_ptr, window->win_ptr);
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
		free_fdf(window);
		return (1);
	}
	else
		return (0);
}
