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
#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>

int	key_event(int key, t_win_data data)
{
	if (key == XK_Escape)
	{
		mlx_destroy_display(data.ptr);
		free(data.ptr);
	}
	return (0);
}

int main(void)
{
	t_win_data data;
	t_line line;

	line.x0 = 100;
	line.y0 = 100;
	line.x1 = 200;
	line.y1 = 101;
	data.ptr = mlx_init();
	data.win = mlx_new_window(data.ptr, 1920, 1080, "fdf");
	bresenham(line, data);
	mlx_key_hook(data.win, &key_event, &data);
	mlx_loop(data.ptr);
}

/*int main(int argc, char **argv)
{
	argc = 1;
	int fd = open(argv[1], O_RDONLY);
    t_vector *vector = parsing(fd);

	if (vector == NULL)
		return (1);
	for (size_t i = 0; i < vector->size; ++i)
    {
        t_point *point = (t_point *)get_elem_vector(vector, i);

        if (point != NULL)
        {
            printf("Point %zu: x = %d, y = %d, z = %d\n", i, point->x, point->y, point->z);
        }
    }
	del_vector(vector);
	close(fd);
    return 0;
}*/