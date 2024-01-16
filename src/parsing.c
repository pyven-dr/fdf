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

static t_point	*get_point(char *splited, size_t i, size_t j)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = i;
	point->y = j;
	point->z = ft_atoi(splited);
	point->xp = 0;
	point->yp = 0;
	return (point);
}

t_vector	*parsing(int fd)
{
	t_vector	*vector;
	char		*line;
	char		**splited;
	size_t		i[2];

	i[1] = 0;
	vector = new_vector(10, sizeof(t_point));
	line = get_next_line(fd);
	while (line && vector)
	{
		splited = ft_split(line, ' ');
		if (!splited)
			return (del_vector(vector), free(line), NULL);
		i[0] = 0;
		while (splited[i[0]] && splited[i[0]][0] != '\n')
		{
			if (add_vector(vector, get_point(splited[i[0]], i[0], i[1])) == -1)
				return (del_vector(vector), ft_free(splited, line), NULL);
			i[0]++;
		}
		ft_free(splited, line);
		line = get_next_line(fd);
		i[1]++;
	}
	return (free(line), vector);
}
