/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   open_window.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/24 17:30:34 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/24 17:52:31 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	open_window(t_window *window)
{
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, WX, WY, "Fdf");
}
