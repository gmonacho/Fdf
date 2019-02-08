/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_incre_color.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/30 19:35:49 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 17:48:41 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

double		get_incre_color(t_map map)
{
	double	max;
	double	incre;
	int		i;
	int		j;

	i = 0;
	max = 0;
	while (i < map.size.i)
	{
		j = 0;
		while (j < map.size.j)
		{
			if (map.tab[i][j] > max)
				max = (double)map.tab[i][j];
			j++;
		}
		i++;
	}
	incre = 255.0 / max;
	return (incre);
}
