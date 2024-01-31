/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:58:10 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/01/29 21:58:10 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	height_size(t_data	*data)
{
	t_point	*point;

	point = get_elem_vector(data->vector, data->vector->size - 1);
	data->size_y = point->y + 1;
}

static void	average(t_data *data, int *lines)
{
	double	moy;
	size_t	i;

	i = 0;
	moy = 0;
	while ((double)i < data->size_y)
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
	if (lines == NULL)
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
