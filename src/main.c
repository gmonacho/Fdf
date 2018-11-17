/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 18:37:24 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 18:15:34 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"


int		main(int ac, char **av)
{
	t_map	map;
	int		fd;

	fd = 0;
	if (ac == 2)
	{
		if (!(fd = open(av[1], O_RDONLY)) || !(parser(fd, &map)))
			return (write(1, "error opening/parsing failed\n", 27));
		ft_2dputint(map.tab, map.size.i, map.size.j);
		map.unit = 20.0;
		map.axes.y.a = map.unit - 20;
		map.axes.y.b = 0;
		map.axes.x.a = 20;
		map.axes.x.b = map.unit;
		map.axes.y.alpha = 30;
		open_window(map);
	}
	else
		return(write(1, "invalid number files\n", 21));
}
