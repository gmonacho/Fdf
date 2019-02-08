/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   corner3.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/08 14:56:53 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/08 16:03:30 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		disp_ver_pos(t_map map, t_window *window)
{
	int			i;
	int			j;
	t_point		p1;
	t_point		p2;

	j = ft_round(map.cursor.x);
	while (j < map.size.j)
	{
		i = ft_round(map.cursor.y);
		while (i < map.size.i)
		{
			p1 = create_vpoint(j - ft_round(map.cursor.x), i -
					ft_round(map.cursor.y), map.tab[i][j], map);
			if (i + 1 < map.size.i)
			{
				p2 = create_vpoint(j - ft_round(map.cursor.x), i + 1 -
						ft_round(map.cursor.y), map.tab[i + 1][j], map);
				if (is_in_screen(p1) || is_in_screen(p2))
					line_put(p1, p2, window);
			}
			i++;
		}
		j++;
	}
}

static void		disp_ver_neg(t_map map, t_window *window)
{
	int			i;
	int			j;
	t_point		p1;
	t_point		p2;

	j = ft_round(map.cursor.x);
	while (j >= 0)
	{
		i = ft_round(map.cursor.y);
		while (i >= 0)
		{
			p1 = create_vpoint(j - ft_round(map.cursor.x), i -
					ft_round(map.cursor.y), map.tab[i][j], map);
			if (i - 1 >= 0)
			{
				p2 = create_vpoint(j - ft_round(map.cursor.x), i - 1 -
						ft_round(map.cursor.y), map.tab[i - 1][j], map);
				if (is_in_screen(p1) || is_in_screen(p2))
					line_put(p1, p2, window);
			}
			i--;
		}
		j--;
	}
}

void			corner3(t_map map, t_window *window)
{
	disp_ver_pos(map, window);
	disp_ver_neg(map, window);
}
