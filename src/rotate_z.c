/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rotate_z.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 19:17:09 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 19:38:01 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "../includes/fdf.h"

t_vec3d		rotate_z(t_vec3d vec, double alpha)
{
	t_vec3d		new_vec;

	new_vec.x = vec.x * cos(radian(alpha)) + vec.x * -sin(radian(alpha));
	new_vec.y = vec.y * sin(radian(alpha)) + vec.y * cos(radian(alpha));
	new_vec.z = vec.z;
	return (new_vec);
}
