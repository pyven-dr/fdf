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

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_win_data
{
	void	*ptr;
	void	*win;
}	t_win_data;

typedef struct s_line
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
}	t_line;

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

t_vector	*parsing(int fd);
void		bresenham(t_line line, t_win_data data);

#endif