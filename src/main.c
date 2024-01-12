/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 04:30:14 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/12/18 23:03:30 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		fd;

	data = malloc(sizeof(t_data));
	data->img = malloc(sizeof(t_image));
	argc = 1;
	fd = open(argv[1], O_RDONLY);
	data->vector = parsing(fd);
	close(fd);
	if (data->vector == NULL)
		return (1);
	data->zoom = 2;
	data->trans_x = 450;
	data->trans_y = 90;
	data->rot_x = 3.1;
	data->rot_y = 0;
	data->rot_z = 0;
	data->ptr = mlx_init();
	data->win = mlx_new_window(data->ptr, 1920, 1080, "fdf");
	controls(data);
	display_hook(data);
	mlx_loop(data->ptr);
	del_vector(data->vector);
	return (0);
}
