/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 02:57:26 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/01/09 02:57:26 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_data	*revert_values(t_data *data, int x_min, int y_min)
{
	size_t	i;
	t_point	*point;

	i = 0;
	while (i < data->vector->size)
	{
		point = get_elem_vector(data->vector, i);
		point->xp += -(x_min) + data->trans_x;
		point->yp += -(y_min) + data->trans_y;
		i++;
	}
	return (data);
}

static t_data	*adjust_neg(t_data *data)
{
	int		x_min;
	int		y_min;
	t_point	*point;
	size_t	i;

	i = 1;
	point = get_elem_vector(data->vector, 0);
	x_min = point->xp;
	y_min = point->yp;
	while (i < data->vector->size)
	{
		point = get_elem_vector(data->vector, i);
		if (x_min > point->xp)
			x_min = point->xp;
		if (y_min > point->yp)
			y_min = point->yp;
		i++;
	}
	return (revert_values(data, x_min, y_min));
}

t_data	*apply_isometric(t_data *data)
{
	size_t	i;
	t_point	*point;
	t_point	*temp;
	double	xp;
	double	yp;

	i = 0;
	temp = malloc(sizeof(t_point));
	while (i < data->vector->size)
	{
		point = (t_point *)get_elem_vector(data->vector, i);
		temp->x = point->x;
		temp->y = point->y;
		temp->z = point->z;
		apply_rx(data->rot_x, &temp->y, &temp->z);
		apply_ry(data->rot_y, &temp->x, &temp->z);
		apply_rz(data->rot_z, &temp->x, &temp->y);
		xp = ((sqrt(2.0) * temp->x - sqrt(2.0) * temp->y) / 2.0);
		yp = ((sqrt(2.0 / 3.0) * temp->z) - \
			(1.0 / sqrt(6.0)) * (temp->x + temp->y));
		xp *= data->zoom;
		yp *= data->zoom;
		point->xp = (int)xp;
		point->yp = (int)yp;
		i++;
	}
	free(temp);
	return (adjust_neg(data));
}
