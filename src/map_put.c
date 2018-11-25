/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_put.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 18:22:19 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/25 17:45:11 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		disp_hor(t_map map, void *mlx_ptr, void *win_ptr)
{
	int			i;
	int			j;
	t_point		p1;
	t_point		p2;

	p1 = create_vpoint(0, 0, 0, map);
	i = 0;
	while (i < map.size.i)
	{
		j = 0;
		while (j < map.size.j)
		{
			p2 = create_vpoint(j, i, -map.tab[i][j], map);
			if (j > 0 && (is_in_screen(p1) || is_in_screen(p2)))
				line_put(p1, p2, mlx_ptr, win_ptr, 0xFF0000);
			j++;
			p1 = p2;
		}
		i++;
	}
}

static void		disp_vec(t_map map, void *mlx_ptr, void *win_ptr)
{
	int			i;
	int			j;
	t_point		p1;
	t_point		p2;

	p1 = create_vpoint(0.0, 0.0, 0.0, map);
	j = 0;
	while (j < map.size.j)
	{
		i = 0;
		while (i < map.size.i)
		{
			p2 = create_vpoint((double)j, (double)i, (double)(-map.tab[i][j]), map);
			if (i > 0 && (is_in_screen(p1) || is_in_screen(p2)))
				line_put(p1, p2, mlx_ptr, win_ptr, 0x0000FF);
			i++;
			p1 = p2;
		}
		j++;
	}

}

static void		disp_map(t_map map, void *mlx_ptr, void *win_ptr)
{
	disp_hor(map, mlx_ptr, win_ptr);
	disp_vec(map, mlx_ptr, win_ptr);
}

void	map_put(t_map map, void *mlx_ptr, void *win_ptr)
{
	axes_put(map, mlx_ptr, win_ptr);
	disp_map(map, mlx_ptr, win_ptr);
}
