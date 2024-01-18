/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:27:07 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/01/09 09:27:07 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x <= 0 || y <= 0)
		return ;
	dst = data->addr + (y * data->length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

static int	mouse_press(int key, int x, int y, void *param)
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

static int	key_press(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key >= LEFT_ARROW && key <= DOWN_ARROW)
		translate(key, data);
	else if (key == ESCAPE)
		close_window(data);
	else if (key == W || key == A || key == S || key == D \
		|| key == Q || key == E)
		rotate(key, data);
	else if (key == R || key == F)
		rescale_z(key, data);
	return (display_hook(data));
}

static int	mouse_release(int key, int x, int y, void *param)
{
	t_data *data;

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

int	display_hook(t_data *data)
{
	data->img->img = mlx_new_image(data->ptr, 1920, 1080);
	if (data->img->img == NULL)
		return (1);
	data->img->addr = mlx_get_data_addr(data->img->img, \
		&data->img->bits_per_pixel, &data->img->length, &data->img->endian);
	apply_isometric(data);
	connect_pts(data->vector, data);
	mlx_destroy_image(data->ptr, data->img->img);
	return (0);
}

int	controls(t_data *data)
{
	if (mlx_hook(data->win, 2, 1L << 0, key_press, data) == -1)
		return (-1);
	if (mlx_hook(data->win, 4, 1L << 2, mouse_press, data) == -1)
		return (-1);
	mlx_hook(data->win, 5, 1L << 3, mouse_release, data);
	if (mlx_hook(data->win, 6, 1L << 6, mouse_move, data) == -1)
		return (-1);
	mlx_hook(data->win, 17, 0, close_window, data);
	return (0);
}
