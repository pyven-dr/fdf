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
	display_hook(data);
	return (0);
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
	display_hook(data);
	return (0);
}

int	display_hook(t_data *data)
{
	data->img->img = mlx_new_image(data->ptr, 1920, 1080);
	data->img->addr = mlx_get_data_addr(data->img->img, \
		&data->img->bits_per_pixel, &data->img->length, &data->img->endian);
	apply_isometric(data);
	connect_pts(data->vector, data);
	mlx_destroy_image(data->ptr, data->img->img);
	return (0);
}

void	controls(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 4, 1L << 2, mouse_press, data);
	mlx_hook(data->win, 17, 0, close_window, data);
}
