/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_pts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 03:09:45 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/01/10 03:09:45 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>
void	connect_vpts(t_vector *vector, t_win_data *data)
{
	size_t 	i;
	t_point *pt1;
	t_point *pt2;
	t_line 	line;

	i = 1;
	pt2 = get_elem_vector(vector, 0);
	while (i < vector->size)
	{
		pt1 = pt2;
		pt2 = get_elem_vector(vector, i);
		if (pt1->y == pt2->y)
		{
			line.x0 = pt1->xp;
			line.y0 = pt1->yp;
			line.x1 = pt2->xp;
			line.y1 = pt2->yp;
			//printf("%d %d %d %d\n",line.x0, line.y0, line.x1, line.y1);
			bresenham(line, data);
			printf("V points\n");
		}
		i++;
	}
}

void	connect_hpts(t_vector *vector, t_win_data *data)
{
	size_t i;
	size_t j;
	t_point *pt1;
	t_point	*pt2;
	t_line	line;

	i = 1;
	j = 0;
	pt1 = get_elem_vector(vector, 0);
	while(i < vector->size)
	{
		pt2 = get_elem_vector(vector, i);
		if ((pt2->y == pt1->y + 1) && (pt2->x == pt1->x))
		{
			line.x0 = pt1->xp;
			line.y0 = pt1->yp;
			line.x1 = pt2->xp;
			line.y1 = pt2->yp;
			bresenham(line, data);
			j++;
			pt1 = get_elem_vector(vector, j);
			printf("H points\n");
		}
		else if ((pt2->y == pt1->y + 1) && (pt2->x == pt1->x + 1))
		{
			j++;
			pt1 = get_elem_vector(vector, j);
		}
		i++;
	}
}