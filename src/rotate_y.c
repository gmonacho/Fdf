/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rotate_y.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 19:17:10 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 17:28:25 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "../includes/fdf.h"

t_vec3d		rotate_y(t_vec3d vec, double alpha)
{
	t_vec3d		new_vec;

	new_vec.x = vec.x * cos(radian(alpha)) + vec.z * sin(radian(alpha));
	new_vec.y = vec.y;
	new_vec.z = vec.x * -sin(radian(alpha)) + vec.z * cos(radian(alpha));
	return (new_vec);
}
