/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 17:36:04 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 18:31:36 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	*convert_int(const char *line)
{
	int		*tab;
	int		i;
	int		len;

	len = ft_countnumbers((char*)line);
	if (!(tab = (int*)ft_memalloc(sizeof(int) * len)))
		return (0);
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
				return (0);
		}
	}
	return (tab);
}

int			parser(int const fd, t_map *amap)
{
	char	*line;
	int		nbchar;

	if (!((*amap).tab = (int**)ft_memalloc(sizeof(int*))))
		return (0);
	(*amap).size.i = 0.0;
	(*amap).size.j = 0.0;
	while ((nbchar = get_next_line(fd, &line)) > 0)
	{
		if ((*amap).size.i == 0)
			(*amap).size.j = (double)ft_countnumbers(line);
		(*amap).tab = ft_2dintpushback((*amap).tab, (*amap).size.i, convert_int(line));
		(*amap).size.i++;
	}
	return (1);
}
