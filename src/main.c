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
		if (data == NULL)
			return (1);
		data->img = malloc(sizeof(t_image));
		if (data->img == NULL)
			return (free(data), 1);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (free(data->img), free(data), 1);
		data->vector = parsing(fd, data);
		close(fd);
		if (data->vector == NULL)
			return (free(data->img), free(data), 1);
		if (init_window(data) == 1)
			close_window(data, 1);
		controls(data);
		mlx_loop(data->ptr);
		return (0);
	}
	return (1);
}
