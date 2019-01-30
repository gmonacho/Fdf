/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 17:36:04 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 17:04:58 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	convert_int(const char *line, int **int_line, double size_j)
{
	int		*tab;
	int		i;
	int		len;

	if ((len = ft_countnumbers((char*)line)) != size_j)
		return (-2);
	if (!(tab = (int*)ft_memalloc(sizeof(int) * len)))
		return (-1);
	i = 0;
	while (i < len)
	{
		if (*line == ' ')
			line++;
		else if (ft_isdigit(*line) || *line == '-' || *line == '+')
		{
			tab[i++] = ft_atoi(line);
			if (*line == '-' || *line == '+')
				line++;
			if (ft_isdigit(*line))
				while (ft_isdigit(*line) && *line)
					line++;
			else
				return (-3);
		}
		else
			return (-3);
	}
	*int_line = tab;
	return (1);
}

int			parser(int const fd, t_map *amap)
{
	char	*line;
	int		*int_line;
	int		ret;
	int		error;

	if (!((*amap).tab = (int**)ft_memalloc(sizeof(int*))))
		return (-1);
	(*amap).size.i = 0.0;
	(*amap).size.j = 0.0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if ((*amap).size.i == 0)
			(*amap).size.j = (double)ft_countnumbers(line);
		if ((error = convert_int(line, &int_line, (*amap).size.j)) <= 0)
			return (error);
		(*amap).tab = ft_2dintpushback((*amap).tab, (*amap).size.i, int_line);
		(*amap).size.i++;
	}
	return ((ret < 0) ? -4 : 1);
}
