/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:51:35 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/01/13 04:51:35 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_file(char *file)
{
	char	*end;
	char	*start;

	end = ft_strrchr(file, '.');
	start = ft_strrchr(file, '/');
	if (end && ft_strlen(file) > 4)
	{
		if (start)
		{
			if (ft_strlen(end) < ft_strlen(start) && \
				ft_strcmp(end, ".fdf") == 0)
				return (0);
		}
		else
		{
			if (ft_strlen(end) < ft_strlen(file) && ft_strcmp(end, ".fdf") == 0)
				return (0);
		}
	}
	return (-1);
}
