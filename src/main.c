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

	if (argc == 2 && check_file(argv[1]) != -1)
	{
		data = malloc(sizeof(t_data));
		data->img = malloc(sizeof(t_image));
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (free(data), free(data->img), 1);
		data->vector = parsing(fd);
		close(fd);
		if (data->vector == NULL)
			return (free(data), free(data->img), 1);
		if (init_window(data) == 1)
			return (close_window(data), 1);
		if (controls(data) == -1)
			return (close_window(data), 1);
		display_hook(data);
		mlx_loop(data->ptr);
	}
	return (0);
}
