/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_put.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 18:22:19 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 18:43:07 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*static void		disp_ver(t_map map, void *mlx_ptr, void *win_ptr)
{
	int			i;
	int			j;
	t_point		p1;
	t_point		p2;

	j = 0;
	while (j < map.size.j)
	{
		i = 0;
		while (i < map.size.i)
		{
			p1 = create_vpoint(j, i, map.tab[i][j], map);
			if (i + 1 < map.size.i)
			{
				p2 = create_vpoint(j, i + 1, map.tab[i + 1][j], map);
				line_put(p1, p2, mlx_ptr, win_ptr, 0xFFFFFF);
			}
			i++;
		}
		j++;
	}
}

static void		disp_hor(t_map map, void *mlx_ptr, void *win_ptr)
{
	int			i;
	int			j;
	t_point		p1;
	t_point		p2;

	i = 0;
	while (i < map.size.i)
	{
		j = 0;
		while (j < map.size.j)
		{
			p1 = create_vpoint(j, i, map.tab[i][j], map);
			if (j + 1 < map.size.j)
			{
				p2 = create_vpoint(j + 1, i, map.tab[i][j + 1], map);
				line_put(p1, p2, mlx_ptr, win_ptr, 0xFFFFFF);
			}
			j++;
		}
		i++;
	}
}*/

static void		disp_hor_neg(t_map map, void *mlx_ptr, void *win_ptr)
{
	int			i;
	int			j;
	t_point		p1;
	t_point		p2;

	i = ft_round(map.cursor.y);
	while (i >= 0)
	{
		j = ft_round(map.cursor.x);
		while (j >= 0)
		{
			p1 = create_vpoint(j - ft_round(map.cursor.x), i - ft_round(map.cursor.y), map.tab[i][j], map);
			if (j - 1 >= 0)
			{
				p2 = create_vpoint(j - 1 - ft_round(map.cursor.x), i - ft_round(map.cursor.y), map.tab[i][j - 1], map);
				line_put(p1, p2, mlx_ptr, win_ptr, 0xFFFFFF);
			}
			j--;
		}
		i--;
	}
}

static void		disp_hor_pos(t_map map, void *mlx_ptr, void *win_ptr)
{
	int			i;
	int			j;
	t_point		p1;
	t_point		p2;

	i = ft_round(map.cursor.y);
	while (i < map.size.i)
	{
		j = ft_round(map.cursor.x);
		while (j < map.size.j)
		{
			p1 = create_vpoint(j - ft_round(map.cursor.x), i - ft_round(map.cursor.y), map.tab[i][j], map);
			if (j + 1 < map.size.j)
			{
				p2 = create_vpoint(j + 1 - ft_round(map.cursor.x), i - ft_round(map.cursor.y), map.tab[i][j + 1], map);
				line_put(p1, p2, mlx_ptr, win_ptr, 0xFFFFFF);
			}
			j++;
		}
		i++;
	}
}

static void		disp_hor(t_map map, void *mlx_ptr, void *win_ptr)
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
			p1 = create_vpoint(j - ft_round(map.cursor.x), i - ft_round(map.cursor.y), map.tab[i][j], map);
			if (j - 1 >= 0)
			{
				p2 = create_vpoint(j - 1 - ft_round(map.cursor.x), i - ft_round(map.cursor.y), map.tab[i][j - 1], map);
				line_put(p1, p2, mlx_ptr, win_ptr, 0xFFFFFF);
			}
			j--;
		}
		i++;
	}
}

static void		disp_horo(t_map map, void *mlx_ptr, void *win_ptr)
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
			p1 = create_vpoint(j - ft_round(map.cursor.x), i - ft_round(map.cursor.y), map.tab[i][j], map);
			if (j + 1 < map.size.j)
			{
				p2 = create_vpoint(j + 1 - ft_round(map.cursor.x), i - ft_round(map.cursor.y), map.tab[i][j + 1], map);
				line_put(p1, p2, mlx_ptr, win_ptr, 0xFFFFFF);
			}
			j++;
		}
		i--;
	}
}


static void		disp_ver_pos(t_map map, void *mlx_ptr, void *win_ptr)
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
			p1 = create_vpoint(j - ft_round(map.cursor.x), i - ft_round(map.cursor.y), map.tab[i][j], map);
			if (i + 1 < map.size.i)
			{
				p2 = create_vpoint(j - ft_round(map.cursor.x), i + 1 - ft_round(map.cursor.y), map.tab[i + 1][j], map);
				line_put(p1, p2, mlx_ptr, win_ptr, 0xFFFFFF);
			}
			i++;
		}
		j++;
	}
}

static void		disp_ver_neg(t_map map, void *mlx_ptr, void *win_ptr)
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
			p1 = create_vpoint(j - ft_round(map.cursor.x), i - ft_round(map.cursor.y), map.tab[i][j], map);
			if (i - 1 >= 0)
			{
				p2 = create_vpoint(j - ft_round(map.cursor.x), i - 1 - ft_round(map.cursor.y), map.tab[i - 1][j], map);
				line_put(p1, p2, mlx_ptr, win_ptr, 0xFFFFFF);
			}
			i--;
		}
		j--;
	}
}

static void		disp_ver(t_map map, void *mlx_ptr, void *win_ptr)
{
	int			i;
	int			j;
	t_point		p1;
	t_point		p2;

	j = ft_round(map.cursor.x);
	while (j < map.size.j)
	{
		i = ft_round(map.cursor.y);
		while (i >= 0)
		{
			p1 = create_vpoint(j - ft_round(map.cursor.x), i - ft_round(map.cursor.y), map.tab[i][j], map);
			if (i - 1 >= 0)
			{
				p2 = create_vpoint(j - ft_round(map.cursor.x), i - 1 - ft_round(map.cursor.y), map.tab[i - 1][j], map);
				line_put(p1, p2, mlx_ptr, win_ptr, 0xFFFFFF);
			}
			i--;
		}
		j++;
	}
}

static void		disp_vero(t_map map, void *mlx_ptr, void *win_ptr)
{
	int			i;
	int			j;
	t_point		p1;
	t_point		p2;

	j = ft_round(map.cursor.x);
	while (j >= 0)
	{
		i = ft_round(map.cursor.y);
		while (i < map.size.i)
		{
			p1 = create_vpoint(j - ft_round(map.cursor.x), i - ft_round(map.cursor.y), map.tab[i][j], map);
			if (i + 1 < map.size.i)
			{
				p2 = create_vpoint(j - ft_round(map.cursor.x), i + 1 - ft_round(map.cursor.y), map.tab[i + 1][j], map);
				line_put(p1, p2, mlx_ptr, win_ptr, 0xFFFFFF);
			}
			i++;
		}
		j--;
	}
}



static void		disp_map(t_map map, void *mlx_ptr, void *win_ptr)
{
	disp_hor_pos(map, mlx_ptr, win_ptr);
	disp_hor_neg(map, mlx_ptr, win_ptr);
	disp_hor(map, mlx_ptr, win_ptr);
	disp_horo(map, mlx_ptr, win_ptr);
	disp_ver_pos(map, mlx_ptr, win_ptr);
	disp_ver_neg(map, mlx_ptr, win_ptr);
	disp_ver(map, mlx_ptr, win_ptr);
	disp_vero(map, mlx_ptr, win_ptr);
}

void	map_put(t_map map, void *mlx_ptr, void *win_ptr)
{
	disp_map(map, mlx_ptr, win_ptr);
}
