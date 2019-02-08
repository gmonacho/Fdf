/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_decre_color.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/30 19:46:51 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 17:17:44 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		get_decre_color(t_map map)
{
	int		max;
	int		decre;
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
				max = map.tab[i][j];
			j++;
		}
		i++;
	}
	decre = 0x0000FF / max;
	return (decre);
}
