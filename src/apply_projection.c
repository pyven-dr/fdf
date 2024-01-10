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

t_vector	*apply_isometric(t_vector *vector)
{
	size_t	i;
	t_point	*point;
	double	xp;
	double	yp;

	i = 0;
	while (i < vector->size)
	{
		point = (t_point *)get_elem_vector(vector, i);
		xp = ((sqrt(2.0) * point->x - sqrt(2.0) * point->y) / 2.0);
		yp = ((sqrt(2.0 / 3.0) * point->z) - \
			(1.0 / sqrt(6.0)) * (point->x + point->y));
		xp *= (double)WIDTH / (point->x + 100) + 0.5;
		yp *= (double)HEIGHT / (point->y + 100) + 0.5;
		point->xp = (int)xp;
		point->yp = (int)yp;
		i++;
	}
	return (adjust_neg(vector));
}

t_vector	*adjust_neg(t_vector *vector)
{
	int		x_min;
	int		y_min;
	t_point	*point;
	size_t	i;

	i = 1;
	point = get_elem_vector(vector, 0);
	x_min = point->xp;
	y_min = point->yp;
	while (i < vector->size)
	{
		point = get_elem_vector(vector, i);
		if (x_min > point->xp)
			x_min = point->xp;
		if (y_min > point->yp)
			y_min = point->yp;
		i++;
	}
	return (revert_values(vector, x_min, y_min));
}

t_vector	*revert_values(t_vector *vector, int x_min, int y_min)
{
	size_t	i;
	t_point	*point;

	i = 0;
	while (i < vector->size)
	{
		point = get_elem_vector(vector, i);
		point->xp += -(x_min+y_min);
		point->yp += -(y_min+x_min);
		i++;
	}
	return (vector);
}
