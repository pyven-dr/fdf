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

	data = (t_data *)param;
	if (key == MOUSE_SCROLL_UP || key == MOUSE_SCROLL_DOWN)
		zoom(key, data);
	else if (key == LEFT_BUTTON)
	{
		data->mouse_x = x;
		data->mouse_y = y;
		data->left_press = 1;
	}
	else
	{
		data->mouse_x = x;
		data->mouse_y = y;
		data->right_press = 1;
	}
	return (0);
}

int	mouse_release(int key, int x, int y, void *param)
{
	t_data	*data;

	(void)x;
	(void)y;
	data = (t_data *)param;
	if (key == LEFT_BUTTON)
		data->left_press = 0;
	else
		data->right_press = 0;
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->left_press == 1 && (x + y) % 2)
	{
		data->rot_y += (x - data->mouse_x) * 0.005;
		data->rot_x += (y - data->mouse_y) * 0.005;
		data->mouse_x = x;
		data->mouse_y = y;
		display_hook(data);
	}
	else if (data->right_press == 1 && (x + y) % 2)
	{
		data->trans_x += (x - data->mouse_x);
		data->trans_y += (y - data->mouse_y);
		data->mouse_x = x;
		data->mouse_y = y;
		display_hook(data);
	}
	return (0);
}
