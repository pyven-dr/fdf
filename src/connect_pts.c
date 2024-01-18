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

static void	draw_line(t_point *pt1, t_point *pt2, t_data *data)
{
	t_line	line;

	line.x0 = pt1->xp;
	line.y0 = pt1->yp;
	line.x1 = pt2->xp;
	line.y1 = pt2->yp;
	bresenham(line, data, pt1->color);
}

static void	connect_vpts(t_vector *vector, t_data *data)
{
	size_t	i;
	t_point	*pt1;
	t_point	*pt2;

	i = 1;
	pt2 = get_elem_vector(vector, 0);
	while (i < vector->size)
	{
		pt1 = pt2;
		pt2 = get_elem_vector(vector, i);
		if (pt1->y == pt2->y)
			draw_line(pt1, pt2, data);
		i++;
	}
}

static void	connect_hpts(t_vector *vector, t_data *data)
{
	size_t	i;
	size_t	j;
	t_point	*pt1;
	t_point	*pt2;

	i = 1;
	j = 0;
	pt1 = get_elem_vector(vector, 0);
	pt2 = get_elem_vector(vector, 1);
	while (i < vector->size + 1)
	{
		if ((pt2->y == pt1->y + 1) && (pt2->x == pt1->x))
		{
			draw_line(pt1, pt2, data);
			pt1 = get_elem_vector(vector, j++);
			pt2 = get_elem_vector(vector, i++);
		}
		else if ((pt2->y > pt1->y))
			pt1 = get_elem_vector(vector, j++);
		else
			pt2 = get_elem_vector(vector, i++);
	}
}

void	connect_pts(t_vector *vector, t_data *data)
{
	connect_vpts(vector, data);
	connect_hpts(vector, data);
	mlx_put_image_to_window(data->ptr, data->win, data->img->img, 0, 0);
}
