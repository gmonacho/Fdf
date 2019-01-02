/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 18:37:24 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 18:07:10 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_vec3d		init_vector(double x, double y, double z)
{
	t_vec3d		new_vec;

	new_vec.x = x;
	new_vec.y = y;
	new_vec.z = z;
	return (new_vec);
}

int		main(int ac, char **av)
{
	t_map	map;
	int		fd;

	fd = 0;
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0 || !(parser(fd, &map)))
			return (write(1, "error opening/parsing failed\n", 29));
		map.vec[0] = init_vector(1, 0, 0);
		map.vec[1] = init_vector(0, 1, 0);
		map.vec[2] = init_vector(0, 0, 1);
		map.alpha.x = 0;
		map.alpha.y = 0;
		map.alpha.z = 0;
		map.unit = 10.0;
		map.size.height_ratio = 1;
		map.size.scroll_x = 0;
		map.size.scroll_x = 0;
		open_window(map);
	}
	else
		return(write(1, "./fdf source_file\n", 18));
}
