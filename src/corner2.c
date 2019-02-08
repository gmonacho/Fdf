/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   corner2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/08 14:54:53 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/08 16:03:49 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		disp_hor(t_map map, t_window *window)
{
	int			i;
	int			j;
	t_point		p1;
	t_point		p2;

	i = ft_round(map.cursor.y);
	while (i < map.size.i)
	{
		j = ft_round(map.cursor.x);
		while (j >= 0)
		{
			p1 = create_vpoint(j - ft_round(map.cursor.x), i -
					ft_round(map.cursor.y), map.tab[i][j], map);
			if (j - 1 >= 0)
			{
				p2 = create_vpoint(j - 1 - ft_round(map.cursor.x), i -
						ft_round(map.cursor.y), map.tab[i][j - 1], map);
				if (is_in_screen(p1) || is_in_screen(p2))
					line_put(p1, p2, window);
			}
			j--;
		}
		i++;
	}
}

static void		disp_horo(t_map map, t_window *window)
{
	int			i;
	int			j;
	t_point		p1;
	t_point		p2;

	i = ft_round(map.cursor.y);
	while (i >= 0)
	{
		j = ft_round(map.cursor.x);
		while (j < map.size.j)
		{
			p1 = create_vpoint(j - ft_round(map.cursor.x), i -
					ft_round(map.cursor.y), map.tab[i][j], map);
			if (j + 1 < map.size.j)
			{
				p2 = create_vpoint(j + 1 - ft_round(map.cursor.x), i -
						ft_round(map.cursor.y), map.tab[i][j + 1], map);
				if (is_in_screen(p1) || is_in_screen(p2))
					line_put(p1, p2, window);
			}
			j++;
		}
		i--;
	}
}

void			corner2(t_map map, t_window *window)
{
	disp_hor(map, window);
	disp_horo(map, window);
}
