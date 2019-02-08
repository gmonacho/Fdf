/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_press.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/08 15:39:53 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/08 15:42:24 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_press(int keycode, t_window *window)
{
	window->keyboard[keycode] = 1;
	refresh_window(window);
	return (0);
}
