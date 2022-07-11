/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heatmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:11:26 by altikka           #+#    #+#             */
/*   Updated: 2022/07/11 10:49:04 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	set_neighbouring(t_grid *grid, t_pos index, char heat)
{
	if (grid->arr[index.x][index.y] == (heat - 1) && index.x > 0
			&& grid->arr[index.x - 1][index.y] == '.')
		grid->arr[index.x - 1][index.y] = heat;
	if (grid->arr[index.x][index.y] == (heat - 1) && index.y > 0
			&& grid->arr[index.x][index.y - 1] == '.')
		grid->arr[index.x][index.y - 1] = heat;
	if (grid->arr[index.x][index.y] == (heat - 1) && index.x < grid->size.x - 1
			&& grid->arr[index.x + 1][index.y] == '.')
		grid->arr[index.x + 1][index.y] = heat;
	if (grid->arr[index.x][index.y] == (heat - 1) && index.y < grid->size.y - 1
			&& grid->arr[index.x][index.y + 1] == '.')
		grid->arr[index.x][index.y + 1] = heat;
}

static void	set_heatmap(t_grid *grid)
{
	t_pos	index;
	char	heat;

	heat = '1';
	while (heat <= '~')
	{
		index.x = 0;
		while (index.x < grid->size.x)
		{
			index.y = 0;
			while (index.y < grid->size.y)
			{
				set_neighbouring(grid, index, heat);
				index.y++;
			}
			index.x++;
		}
		heat += 1;
	}
}

static void	init_heatmap(t_filler *f)
{
	t_pos	index;
	char	ch;

	index.x = 0;
	while (index.x < f->map.size.x)
	{
		ft_memset(f->heatmap.arr[index.x], '.', f->heatmap.size.y);
		index.y = 0;
		while (index.y < f->map.size.y)
		{
			ch = f->map.arr[index.x][index.y];
			if (ft_toupper(ch) == f->opponent)
				f->heatmap.arr[index.x][index.y] = '0';
			index.y++;
		}
		index.x++;
	}
}

int	parse_heatmap(t_filler *f)
{
	// (f->turn < 3)
	if (!f->heatmap.arr)
	{
		f->heatmap.size.x = f->map.size.x;
		f->heatmap.size.y = f->map.size.y;
		if (allocate_grid(&(f->heatmap)) < 0)
			return (panic(f, "Error: allocating heatmap failed"));
	}
	init_heatmap(f);
	set_grid_psoi(&(f->heatmap), '0');
	set_heatmap(&(f->heatmap));
	return (1);
}
