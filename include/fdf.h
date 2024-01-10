/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 03:50:41 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/12/16 03:50:41 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		xp;
	int		yp;
}	t_point;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;


typedef struct s_win_data
{
	void	*ptr;
	void	*win;
	t_data	*image;
}	t_win_data;

typedef struct s_line
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
}	t_line;

# define WIDTH 1920
# define HEIGHT 1080

t_vector	*parsing(int fd);
void		bresenham(t_line line, t_win_data *data);
t_vector	*apply_isometric(t_vector *vector);
t_vector	*adjust_neg(t_vector *vector);
t_vector	*revert_values(t_vector *vector, int x_min, int y_min);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		connect_vpts(t_vector *vector, t_win_data *data);
void		connect_hpts(t_vector *vector, t_win_data *data);

#endif