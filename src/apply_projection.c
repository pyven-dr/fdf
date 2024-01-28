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

static void	init_rot(t_data *data)
{
	data->rot->cosx = cos(data->rot_x);
	data->rot->sinx = sin(data->rot_x);
	data->rot->cosy = cos(data->rot_y);
	data->rot->siny = sin(data->rot_y);
	data->rot->cosz = cos(data->rot_z);
	data->rot->sinz = sin(data->rot_z);
}

static void	init_temp(t_data *data, t_point *point, t_point *temp)
{
	temp->x = point->x;
	temp->y = point->y;
	temp->z = point->z * data->z_scale;
	apply_rz(data, &temp->x, &temp->y);
	apply_ry(data, &temp->x, &temp->z);
	apply_rx(data, &temp->y, &temp->z);
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
	if (temp == NULL)
		close_window(data, 1);
	init_rot(data);
	while (i < data->vector->size)
	{
		point = (t_point *)get_elem_vector(data->vector, i);
		init_temp(data, point, temp);
		xp = (SQRT2 * temp->x - SQRT2 * temp->y) * 0.5;
		yp = (0.816497 * temp->z) - 0.408248 * (temp->x + temp->y);
		xp *= data->zoom;
		yp *= data->zoom;
		point->xp = (int)(xp + (data->trans_x + WIDTH * 0.5));
		point->yp = (int)(yp + (data->trans_y + HEIGHT * 0.5));
		i++;
	}
	free(temp);
	return (data);
}

t_data	*apply_cavalier(t_data *data)
{
	size_t	i;
	t_point	*point;
	t_point	*temp;
	double	xp;
	double	yp;

	i = 0;
	temp = malloc(sizeof(t_point));
	if (temp == NULL)
		close_window(data, 1);
	init_rot(data);
	while (i < data->vector->size)
	{
		point = (t_point *)get_elem_vector(data->vector, i);
		init_temp(data, point, temp);
		xp = temp->x + temp->z * 0.7071068;
		yp = temp->y + temp->z * 0.7071066;
		xp *= data->zoom;
		yp *= data->zoom;
		point->xp = (int)(xp + (data->trans_x + WIDTH * 0.5));
		point->yp = (int)(yp + (data->trans_y + HEIGHT * 0.5));
		i++;
	}
	free(temp);
	return (data);
}
