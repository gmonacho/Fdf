/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 18:37:24 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/08 15:36:46 by gmonacho    ###    #+. /#+    ###.fr     */
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

static int			parsing_error(int error, int fd)
{
	if (error == -1)
		return (write(1, "memory error\n", 13));
	else if (error == -2)
		return (write(1, "invalid line size\n", 18));
	else if (error == -3)
		return (write(1, "invalid char\n", 13));
	else if (error == -4)
		return (write(1, "read failed (get_next_line)\n", 27));
	else if (fd < 0)
		return (write(1, "oppening failed\n", 16));
	else
		return (write(1, "unidentify error\n", 17));
}

static void			init_window(t_window *window)
{
	window->map.vec[0] = init_vector(1, 0, 0);
	window->map.vec[1] = init_vector(0, 1, 0);
	window->map.vec[2] = init_vector(0, 0, 1);
	window->map.alpha.x = 0;
	window->map.alpha.y = 0;
	window->map.alpha.z = 0;
	window->map.unit = 10.0;
	window->map.h_ratio = 1;
	window->map.size.height_ratio = 1;
	window->map.cursor.x = window->map.size.j / 2;
	window->map.cursor.y = window->map.size.i / 2;
	window->map.color.incre = get_incre_color(window->map);
}

int					main(int ac, char **av)
{
	t_window	window;
	int			fd;
	int			i;
	int			error;

	error = 0;
	fd = 0;
	if (ac == 2)
	{
		open_window(&window);
		if ((fd = open(av[1], O_RDONLY)) < 0
				|| (error = (parser(fd, &(window.map)))) <= 0)
			return (parsing_error(error, fd));
		init_window(&window);
		i = 0;
		while (i < 8)
			window.mouse.button[i++] = 0;
		window.mouse.x = 0;
		window.mouse.y = 0;
		window_loop(&window);
	}
	else
		return (write(1, "./fdf source_file\n", 18));
	return (0);
}
