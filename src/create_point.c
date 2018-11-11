/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_point.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 20:16:36 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 14:50:41 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point		create_point(double x, double y)
{
	t_point		point;

	point.x = x;
	point.y = y;
	return (point);
}
