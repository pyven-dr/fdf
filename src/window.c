/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 07:58:54 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/01/11 07:58:54 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_values(t_data *data)
{
	data->trans_x = 0;
	data->trans_y = 0;
	data->rot_x = 3.16;
	data->rot_y = 0.02;
	data->rot_z = 0.02;
	data->z_scale = 0.1;
	data->left_press = 0;
	data->right_press = 0;
	data->project = 0;
	data->pt_only = 0;
}

int	init_window(t_data *data)
{
	init_values(data);
	data->ptr = mlx_init();
	if (data->ptr == NULL)
	{
		del_vector(data->vector);
		free(data->img);
		free(data);
		exit(1);
	}
	height_size(data);
	if (width_size(data) == 1)
		return (1);
	data->zoom = (HEIGHT / (double)data->size_y) / 1.5;
	data->win = mlx_new_window(data->ptr, WIDTH, HEIGHT, "fdf");
	if (data->win == NULL)
		return (1);
	data->rot = malloc(sizeof(t_rot));
	if (data->rot == NULL)
		return (1);
	data->img->img = NULL;
	display_hook(data);
	return (0);
}

int	close_window(void *param, int value)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_image(data->ptr, data->img->img);
	mlx_destroy_window(data->ptr, data->win);
	mlx_destroy_display(data->ptr);
	del_vector(data->vector);
	free(data->img);
	free(data->ptr);
	free(data->rot);
	free(data);
	exit(value);
}
