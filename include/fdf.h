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
	double		x;
	double		y;
	double		z;
	int			xp;
	int			yp;
	int			color;
}	t_point;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		length;
	int		endian;
}			t_image;

typedef struct s_data
{
	void		*ptr;
	void		*win;
	t_image		*img;
	double		size_x;
	size_t		size_y;
	double		zoom;
	double		trans_x;
	double		trans_y;
	double		rot_x;
	double		rot_y;
	double		rot_z;
	double		z_scale;
	int 		left_press;
	int 		right_press;
	int 		mouse_x;
	int 		mouse_y;
	t_vector	*vector;
}	t_data;

typedef struct s_line
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
}	t_line;

# define WIDTH 				1920
# define HEIGHT 			1080
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN 	5
# define LEFT_ARROW			65361
# define RIGHT_ARROW		65363
# define DOWN_ARROW			65364
# define UP_ARROW			65362
# define ESCAPE				65307
# define W					119
# define A					97
# define S					115
# define D					100
# define Q					113
# define E					101
# define R					114
# define F					102
# define LEFT_BUTTON		1
# define RIGHT_BUTTON		3

t_vector	*parsing(int fd);
void		bresenham(t_line line, t_data *data, int color);
t_data		*apply_isometric(t_data *data);
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);
void		connect_pts(t_vector *vector, t_data *data);
void		zoom(int key, t_data *data);
int			controls(t_data *data);
int			display_hook(t_data *data);
void		translate(int key, t_data *data);
int			close_window(void *param);
void		apply_rx(double angle, double *y, double *z);
void		apply_ry(double angle, double *x, double *z);
void		apply_rz(t_data *data, double angle, double *x, double *y);
void		rotate(int key, t_data *data);
int			init_window(t_data *data);
int			check_file(char *file);
void		rescale_z(int key, t_data *data);
void		height_size(t_data	*data);
int			width_size(t_data *data);

#endif