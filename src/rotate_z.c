/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rotate_z.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 19:17:09 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/08 15:24:12 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vec3d		rotate_z(t_vec3d vec, double alpha)
{
	t_vec3d		new_vec;

	new_vec.x = vec.x * cos(radian(alpha)) + vec.y * -sin(radian(alpha));
	new_vec.y = vec.x * sin(radian(alpha)) + vec.y * cos(radian(alpha));
	new_vec.z = vec.z;
	return (new_vec);
}
