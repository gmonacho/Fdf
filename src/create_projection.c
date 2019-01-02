/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_projection.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 18:39:50 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 18:46:12 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_projection	create_projection(int x, int y, int z)
{
	t_projection	new_project;

	new_project.coord[0] = x;
	new_project.coord[1] = y;
	new_project.coord[2] = z;
	return (new_project);
}
