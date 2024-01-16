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

static void	init_temp(t_data *data, t_point *point, t_point *temp)
{
	temp->x = point->x;
	temp->y = point->y;
	temp->z = point->z * data->z_scale;
	apply_rz(data, data->rot_z, &temp->x, &temp->y);
	apply_ry(data->rot_y, &temp->x, &temp->z);
	apply_rx(data->rot_x, &temp->y, &temp->z);
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
		init_temp(data, point, temp);
		xp = (sqrt(2.0) * temp->x - sqrt(2.0) * temp->y) / 2.0;
		yp = (sqrt(2.0 / 3.0) * temp->z) - \
			(1.0 / sqrt(6.0)) * (temp->x + temp->y);
		xp *= data->zoom;
		yp *= data->zoom;
		point->xp = (int)xp;
		point->yp = (int)yp;
		point->xp += (int)(data->trans_x + HEIGHT / 2.0);
		point->yp += (int)(data->trans_y + WIDTH / 2.0);
		i++;
	}
	free(temp);
	return (data);
}
