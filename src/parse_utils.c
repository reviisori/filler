/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:21:02 by altikka           #+#    #+#             */
/*   Updated: 2022/06/30 13:51:31 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	validate_line(char *line, char *marks, int len)
{
	if (ft_strlen(line) != (size_t)len)
		return (panic(NULL, "Error: invalid grid width"));
	while (*line)
	{
		if (!ft_strcasechr(marks, *line))
			return (panic(NULL, "Error: invalid marking detected"));
		line++;
	}
	return (1);
}

int	populate_grid(t_grid *grid, char *marks, int ofs)
{
	char	*line;
	int		i;

	i = 0;
	while (i < grid->size.x)
	{
		if (get_next_line(0, &line) <= 0)
			return (panic(NULL, "Error: couldn't get data to populate grid"));
		ft_memcpy(grid->arr[i], line + ofs, (size_t)(grid->size.y));
		ft_strdel(&line);
		if (validate_line(grid->arr[i], marks, grid->size.y) < 0)
			return (panic(NULL, "Error: couldn't populate grid"));
		i++;
	}
	grid->arr[i] = (void *) '\0';
	return (1);
}

int	allocate_grid(t_grid *grid, size_t type)
{
	t_pos	*size;
	int		i;

	size = &(grid->size);
	grid->arr = (void **)malloc(sizeof(*grid->arr) * (size->x + 1));
	if (!grid->arr)
		return (panic(NULL, "Error: grid's memory allocation failed"));
	i = 0;
	while (i < size->x)
	{
		grid->arr[i] = (void *)ft_strnew(type * size->y);
		if (!grid->arr[i])
		{
			ft_memdelarr(&grid->arr);
			return (panic(NULL, "Error: grid's pointer allocation failed"));
		}
		i++;
	}
	return (1);
}

int	set_grid_size(t_pos *size, char *needle)
{
	char	*line;

	if (get_next_line(0, &line) <= 0)
		return (panic(NULL, "Error: failed to get grid size"));
	if (!ft_strstr(line, needle))
	{
		ft_strdel(&line);
		return (panic(NULL, "Error: couldn't read grid size"));
	}
	size->x = ft_atoi(ft_strchr(line, ' '));
	size->y = ft_atoi(ft_strrchr(line, ' '));
	ft_strdel(&line);
	if (!size->x || !size->y)
		return (panic(NULL, "Error: invalid grid size"));
	return (1);
}

int	skip_next_line(void)
{
	char	*line;
	int		ret;

	ret = get_next_line(0, &line);
	if (ret < 0)
		return (panic(NULL, "Error: skipping next line failed"));
	if (ret == 0)
		return (0);
	ft_strdel(&line);
	return (1);
}
