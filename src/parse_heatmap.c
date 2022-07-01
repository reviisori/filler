/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heatmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:11:26 by altikka           #+#    #+#             */
/*   Updated: 2022/07/01 14:37:23 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	allocate_heatmap(t_grid *grid, size_t type)
{
	t_pos	*size;
	int		i;

	size = &(grid->size);
	grid->arr = (void **)malloc(sizeof(*grid->arr) * (size->x));
	if (!grid->arr)
		return (panic(NULL, "Error: heatmap's memory allocation failed"));
	i = 0;
	while (i < size->x)
	{
		grid->arr[i] = (void *)malloc(sizeof(type) * size->y);
		if (!grid->arr[i])
		{
			ft_memdelarr(&grid->arr);
			return (panic(NULL, "Error: heatmap's pointer allocation failed"));
		}
		ft_memset(grid->arr[i], 0, (type * size->y));
		i++;
	}
	return (1);
}

int	parse_heatmap(t_filler *f)
{
	if (!f->heatmap.arr)
	{
		f->heatmap.size.x = f->map.size.x;
		f->heatmap.size.y = f->map.size.y;
		if (allocate_heatmap(&(f->heatmap), sizeof(int)) < 0)
			return (panic(NULL, "Error: allocating heatmap failed"));
	}
	return (1);
}
