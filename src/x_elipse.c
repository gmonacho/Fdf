/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   x_elipse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/10 18:05:32 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 17:46:22 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "../includes/fdf.h"

double			x_elipse(double a, double b, double alpha)
{
	return (b / sqrt((((tan(radian(alpha)) * b) / a) * (tan(radian(alpha)) * b) / a) + 1));
}
