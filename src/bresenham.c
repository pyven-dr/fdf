/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:52:59 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/01/06 23:58:22 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

static int	get_sign(int num)
{
	if (num < 0)
		return (-1);
	else if (num > 0)
		return (1);
	return (0);
}

static void	bresenham_smaller(t_line line, t_data *data, int color)
{
	int	y;
	int	slope;
	int	error;
	int	x;

	x = line.x0;
	y = line.y0;
	slope = 2 * ft_abs(line.y1 - line.y0);
	error = -ft_abs(line.x1 - line.x0);
	while (x != line.x1 + get_sign(line.x1 - line.x0))
	{
		my_mlx_pixel_put(data->img, x, y, color);
		error += slope;
		if (error >= 0)
		{
			y += get_sign(line.y1 - line.y0);
			error += -2 * ft_abs(line.x1 - line.x0);
		}
		x += get_sign(line.x1 - line.x0);
	}
}

static void	bresenham_bigger(t_line line, t_data *data, int color)
{
	int	y;
	int	slope;
	int	error;
	int	x;

	x = line.x0;
	y = line.y0;
	slope = 2 * ft_abs(line.x1 - line.x0);
	error = -ft_abs(line.y1 - line.y0);
	while (y != line.y1 + get_sign(line.y1 - line.y0))
	{
		my_mlx_pixel_put(data->img, x, y, color);
		error += slope;
		if (error >= 0)
		{
			x += get_sign(line.x1 - line.x0);
			error += -2 * ft_abs(line.y1 - line.y0);
		}
		y += get_sign(line.y1 - line.y0);
	}
}

void	bresenham(t_line line, t_data *data, int color)
{
	int	dx;
	int	dy;

	dx = ft_abs(line.x1 - line.x0);
	dy = ft_abs(line.y1 - line.y0);
	if (dy == 0)
	{
		while (line.x0 != line.x1 + get_sign(line.x1 - line.x0))
		{
			my_mlx_pixel_put(data->img, line.x0, line.y0, color);
			line.x0 += get_sign(line.x1 - line.x0);
		}
	}
	else if (dx == 0)
	{
		while (line.y0 != line.y1 + get_sign(line.y1 - line.y0))
		{
			my_mlx_pixel_put(data->img, line.x0, line.y0, color);
			line.y0 += get_sign(line.y1 - line.y0);
		}
	}
	else if (dx >= dy)
		bresenham_smaller(line, data, color);
	else
		bresenham_bigger(line, data, color);
}
