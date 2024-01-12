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

void	apply_rx(double angle, double *y, double *z)
{
	double previous_y;

	previous_y = *y;
	*y = previous_y * cos(angle) + *z * sin(angle);
	*z = -previous_y * sin(angle) + *z * cos(angle);
}

void	apply_ry(double angle, double *x, double *z)
{
	double previous_x;

	previous_x = *x;
	*x = previous_x * cos(angle) + *z * sin(angle);
	*z = -previous_x * sin(angle) + *z * cos(angle);
}

void	apply_rz(double angle, double *x, double *y)
{
	double previous_x;
	double previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(angle) - previous_y * sin(angle);
	*y = previous_x * sin(angle) + previous_y * cos(angle);
}