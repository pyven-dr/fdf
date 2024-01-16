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

void	height_size(t_data	*data)
{
	t_point	*point;

	point = get_elem_vector(data->vector, data->vector->size - 1);
	data->size_y = (size_t) point->y + 1;
}

static void	average(t_data *data, int *lines)
{
	double	moy;
	size_t	i;

	i = 0;
	moy = 0;
	while (i < data->size_y)
		moy += lines[i++];
	data->size_x = moy / (double)data->size_y;
}

int	width_size(t_data *data)
{
	int		*lines;
	size_t	i;
	size_t	j;
	t_point	*point;

	i = 0;
	j = 0;
	lines = malloc(sizeof(double) * (int)data->size_y);
	if (!lines)
		return (1);
	point = get_elem_vector(data->vector, i);
	lines[j] = 0;
	while (i < data->vector->size)
	{
		if (point->x == 0 && point->y != 0)
		{
			j++;
			lines[j] = 0;
		}
		lines[j]++;
		point = get_elem_vector(data->vector, i++);
	}
	average(data, lines);
	free(lines);
	return (0);
}

int	init_window(t_data *data)
{
	data->zoom = 2;
	data->trans_x = 0;
	data->trans_y = 0;
	data->rot_x = 3.1;
	data->rot_y = 0;
	data->rot_z = 0;
	data->z_scale = 1;
	data->ptr = mlx_init();
	height_size(data);
	if (width_size(data) == 1)
		return (1);
	if (data->ptr == NULL)
		return (1);
	data->win = mlx_new_window(data->ptr, WIDTH, HEIGHT, "fdf");
	if (data->win == NULL)
		return (1);
	return (0);
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
