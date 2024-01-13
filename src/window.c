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

void	init_window(t_data *data)
{
	data->zoom = 2;
	data->trans_x = 450;
	data->trans_y = 90;
	data->rot_x = 3.1;
	data->rot_y = 0;
	data->rot_z = 0;
	data->ptr = mlx_init();
	data->win = mlx_new_window(data->ptr, 1920, 1080, "fdf");
}

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_window(data->ptr, data->win);
	mlx_destroy_display(data->ptr);
	del_vector(data->vector);
	free(data->img);
	free(data->ptr);
	free(data);
	exit(0);
}