/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 04:25:35 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/01/20 04:25:35 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_press(int key, int x, int y, void *param)
{
	t_data	*data;

	(void)x;
	(void)y;
	data = (t_data *)param;
	if (key == MOUSE_SCROLL_UP || key == MOUSE_SCROLL_DOWN)
		zoom(key, data);
	if (key == LEFT_BUTTON)
	{
		data->mouse_x = x;
		data->mouse_y = y;
		data->left_press = 1;
	}
	if (key == RIGHT_BUTTON)
	{
		data->mouse_x = x;
		data->mouse_y = y;
		data->right_press = 1;
	}
	return (display_hook(data));
}

int	mouse_release(int key, int x, int y, void *param)
{
	t_data	*data;

	(void)x;
	(void)y;
	data = (t_data *)param;
	if (key == LEFT_BUTTON)
		data->left_press = 0;
	if (key == RIGHT_BUTTON)
		data->right_press = 0;
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->left_press == 1)
	{
		data->rot_y += (x - data->mouse_x) * 0.002;
		data->rot_x += (y - data->mouse_y) * 0.002;
		data->mouse_x = x;
		data->mouse_y = y;
	}
	else if (data->right_press == 1)
	{
		data->trans_x += (x - data->mouse_x);
		data->trans_y += (y - data->mouse_y);
		data->mouse_x = x;
		data->mouse_y = y;
	}
	return (display_hook(data));
}
