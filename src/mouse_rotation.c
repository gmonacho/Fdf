/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_rotation.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/23 18:12:16 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/08 15:58:20 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void			set_reset(int *oldx, int *oldy, t_vec2d *rotation)
{
	*oldx = 0;
	*oldy = 0;
	rotation->x = 0;
	rotation->y = 0;
}

t_vec2d				mouse_rotation(int x, int y, int reset)
{
	t_vec2d		new_vec;
	t_vec2d		rotation;
	static int	oldx = 0;
	static int	oldy = 0;

	if (reset)
		set_reset(&oldx, &oldy, &rotation);
	else
	{
		if (!oldx && !oldy)
		{
			oldx = x;
			oldy = y;
		}
		else
		{
			new_vec.x = ft_abs(oldx) - ft_abs(x);
			new_vec.y = ft_abs(oldy) - ft_abs(y);
		}
		oldx = x;
		oldy = y;
		rotation.x = new_vec.x / 4;
		rotation.y = new_vec.y / 4;
	}
	return (rotation);
}
