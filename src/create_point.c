/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_point.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 20:16:36 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/24 00:42:38 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point		create_point(double x, double y)
{
	t_point		point;

	point.x = WX / 2 + x;
	point.y = WY / 2 + y;
	return (point);
}
