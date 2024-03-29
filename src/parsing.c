/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:50:41 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/12/16 18:50:41 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_free(char **res, char *line)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	free(line);
}

static void	get_color(t_point *point, char *splitted)
{
	size_t	i;

	i = 0;
	while (splitted[i] != ',' && splitted[i])
		i++;
	if (splitted[i] != ',')
	{
		point->color = 4257279;
		return ;
	}
	else
		point->color = ft_atoi_base(ft_strminiminize(splitted + (i + 3)), \
			"0123456789abcdef");
}

static t_point	*get_point(char *splitted, size_t i, size_t j)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (point == NULL)
		return (NULL);
	point->x = i;
	point->y = j;
	point->z = ft_atoi(splitted);
	point->xp = 0;
	point->yp = 0;
	get_color(point, splitted);
	return (point);
}

static char	*read_line(t_vector *vector, t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (errno != 0)
	{
		del_vector(vector);
		free(data->img);
		free(data);
		exit(1);
	}
	return (line);
}

t_vector	*parsing(int fd, t_data *data)
{
	t_vector	*vector;
	char		*line;
	char		**splitted;
	size_t		i[2];

	i[1] = 0;
	vector = new_vector(10, sizeof(t_point));
	line = read_line(vector, data, fd);
	while (line && vector)
	{
		splitted = ft_split(line, ' ');
		if (!splitted)
			return (del_vector(vector), free(line), NULL);
		i[0] = 0;
		while (splitted[i[0]] && splitted[i[0]][0] != '\n')
		{
			if (add_vector(vector, get_point(splitted[i[0]], i[0], i[1])) == -1)
				return (del_vector(vector), ft_free(splitted, line), NULL);
			i[0]++;
		}
		ft_free(splitted, line);
		line = read_line(vector, data, fd);
		i[1]++;
	}
	return (free(line), vector);
}
