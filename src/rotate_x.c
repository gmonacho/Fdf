/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rotate_x.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 19:17:07 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 18:46:29 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vec3d		rotate_x(t_vec3d vec, double alpha)
{
	t_vec3d		new_vec;

	new_vec.x = vec.x;
	new_vec.y = vec.y * cos(radian(alpha)) + vec.z * -sin(radian(alpha));
	new_vec.z = vec.y * sin(radian(alpha)) + vec.z * cos(radian(alpha));
	return (new_vec);
}
