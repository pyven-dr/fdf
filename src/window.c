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

int	close_window(void *param)
{
	t_data *data;

	data = (t_data *)param;
	mlx_destroy_window(data->ptr, data->win);
	mlx_destroy_display(data->ptr);
	del_vector(data->vector);
	free(data->img);
	free(data->ptr);
	free(data);
	exit(0);
}
