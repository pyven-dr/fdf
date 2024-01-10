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
#include <X11/keysym.h>

/*static int	close_win(int key, t_win_data data)
{
	if (key == XK_Escape)
	{
		mlx_destroy_image(data.ptr, data.image.img);
		mlx_destroy_display(data.ptr);
		mlx_destroy_window(data.ptr, data.win);
		mlx_loop_end(data.ptr);
		free(data.ptr);
	}
	return (0);
}

int	close_test(t_win_data data)
{
	mlx_destroy_window(data.ptr, data.win);
	free(data.ptr);
	exit(0);
}*/

/*int main(void)
{
	t_win_data data;
	t_line line;

	line.x0 = 50;
	line.y0 = 65;
	line.x1 = 84;
	line.y1 = 154;

	data.ptr = mlx_init();
	data.win = mlx_new_window(data.ptr, 1920, 1080, "fdf");
	data.image.img = mlx_new_image(data.ptr, 1920, 1080);
	data.image.addr = mlx_get_data_addr(data.image.img, &data.image.bits_per_pixel, &data.image.line_length, &data.image.endian);

	bresenham(line, data.image);

	mlx_put_image_to_window(data.ptr,data.win , data.image.img, 0, 0);
	mlx_hook(data.win, 2, 1L<<0, close_win, &data);
	mlx_hook(data.win, 17, 0, close_test, &data);
	mlx_loop(data.ptr);
}*/

#include <stdio.h>
int main(int argc, char **argv)
{
	t_win_data *data;
	data = malloc(sizeof(t_win_data));
	data->image = malloc(sizeof(t_data));
	argc = 1;

	int fd = open(argv[1], O_RDONLY);
	t_vector *vector = parsing(fd);
	close(fd);
	if (vector == NULL)
		return (1);
	vector = apply_isometric(vector);

	for (size_t i = 0; i < vector->size; ++i)
	{
		t_point *point = (t_point *)get_elem_vector(vector, i);

		if (point != NULL)
		{
			printf("Point %zu: x = %d, y = %d, z = %d, xp = %d, yp = %d\n", i, point->x, point->y, point->z, point->xp, point->yp);
		}
	}

	data->ptr = mlx_init();
	data->win = mlx_new_window(data->ptr, 1920, 1080, "fdf");
	data->image->img = mlx_new_image(data->ptr, 1920, 1080);
	data->image->addr = mlx_get_data_addr(data->image->img, &data->image->bits_per_pixel, \
		&data->image->line_length, &data->image->endian);

	/*t_line line;

	line.x0 = 211;
	line.y0 = 447;
	line.x1 = 148;
	line.y1 = 447;
	bresenham(line, data);*/
	connect_vpts(vector, data);
	connect_hpts(vector, data);

	mlx_put_image_to_window(data->ptr,data->win , data->image->img, 0, 0);
	//mlx_hook(data.win, 2, 1L<<0, close_win, &data);
	//mlx_hook(data.win, 17, 0, close_test, &data);
	mlx_loop(data->ptr);
	del_vector(vector);
	free(data->image);
	free(data);
    return 0;
}
