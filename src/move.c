/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:34:03 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/01/10 23:34:03 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int key, t_data *data)
{
	if (key == MOUSE_SCROLL_UP)
		data->zoom /= 0.9;
	else if (key == MOUSE_SCROLL_DOWN)
		data->zoom *= 0.9;
	if (data->zoom < 1)
		data->zoom = 1;
}

void	translate(int key, t_data *data)
{
	if (key == LEFT_ARROW)
		data->trans_x += 7;
	else if (key == RIGHT_ARROW)
		data->trans_x -= 7;
	else if (key == UP_ARROW)
		data->trans_y += 7;
	else if (key == DOWN_ARROW)
		data->trans_y -= 7;
}

void	rotate(int key, t_data *data)
{
	if (key == W)
		data->rot_x += 0.02;
	else if (key == S)
		data->rot_x -= 0.02;
	else if (key == A)
		data->rot_y += 0.02;
	else if (key == D)
		data->rot_y -= 0.02;
	else if (key == Q)
		data->rot_z += 0.02;
	else if (key == E)
		data->rot_z -= 0.02;
}

void	rescale_z(int key, t_data *data)
{
	if (key == R)
		data->z_scale += 0.01;
	else if (key == F)
		data->z_scale -= 0.01;
}
