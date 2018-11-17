/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   3Delipse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/10 17:49:17 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 18:37:33 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

double			y_elipse(double a, double b, double x)
{
	if (b != 0)
		return ((a/b) * (double)sqrt(b * b - x * x));
	else
		return (0);
}
