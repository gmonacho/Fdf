/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_release.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/08 15:40:39 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/08 15:42:21 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_release(int keycode, t_window *window)
{
	window->keyboard[keycode] = 0;
	return (0);
}
