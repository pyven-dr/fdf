/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 01:10:26 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/01/12 01:10:26 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_rx(t_data *data, double *y, double *z)
{
	double	previous_y;

	previous_y = *y;
	*y = previous_y * data->rot->cosx + *z * data->rot->sinx;
	*z = -previous_y * data->rot->sinx + *z * data->rot->cosx;
}

void	apply_ry(t_data *data, double *x, double *z)
{
	double	previous_x;

	previous_x = *x;
	*x = previous_x * data->rot->cosy + *z * data->rot->siny;
	*z = -previous_x * data->rot->siny + *z * data->rot->cosy;
}

void	apply_rz(t_data *data, double *x, double *y)
{
	double	previous_x;
	double	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x -(data->size_x * 0.5)) * data->rot->cosz \
		- (previous_y -(data->size_y * 0.5)) * data->rot->sinz;
	*y = (previous_x -(data->size_x * 0.5)) * data->rot->sinz \
		+ (previous_y -(data->size_y * 0.5)) * data->rot->cosz;
}
