/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heatmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:11:26 by altikka           #+#    #+#             */
/*   Updated: 2022/07/05 17:46:27 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

//		ft_putstr_fd("in heatmap: ", 2);
//		ft_putchar_fd(h, 2);
//		ft_putstr_fd("\n", 2);

static void	set_heatmap(t_grid *grid)
{
	t_pos	i;
	char	h;

	h = '2';
	while (h != ':')//':'
	{
		i.x = 0;
		while (i.x < grid->size.x)
		{
			i.y = 0;
			while (i.y < grid->size.y)
			{
				if (grid->arr[i.x][i.y] == (h - 1) && i.x > 0
						&& grid->arr[i.x - 1][i.y] == '0')//up
					grid->arr[i.x - 1][i.y] = h;
				if (grid->arr[i.x][i.y] == (h - 1) && i.y > 0
						&& grid->arr[i.x][i.y - 1] == '0')//left
					grid->arr[i.x][i.y - 1] = h;
				if (grid->arr[i.x][i.y] == (h - 1) && i.x < grid->size.x - 1
						&& grid->arr[i.x + 1][i.y] == '0')//down
					grid->arr[i.x + 1][i.y] = h;
				if (grid->arr[i.x][i.y] == (h - 1) && i.y < grid->size.y - 1
						&& grid->arr[i.x][i.y + 1] == '0')//right
					grid->arr[i.x][i.y + 1] = h;
				i.y++;
			}
			i.x++;
		}
		h += 1;
	}
}

static void	init_heatmap(t_filler *f)
{
	t_pos	index;
	char	ch;

	index.x = 0;
	while (index.x < f->map.size.x)
	{
		index.y = 0;
		while (index.y < f->map.size.y)
		{
			ch = f->map.arr[index.x][index.y];
			if (ft_toupper(ch) == f->opponent)
				f->heatmap.arr[index.x][index.y] = '1';
			index.y++;
		}
		index.x++;
	}
}

int	parse_heatmap(t_filler *f)
{
	if (!f->heatmap.arr)
	{
		f->heatmap.size.x = f->map.size.x;
		f->heatmap.size.y = f->map.size.y;
		if (allocate_grid(&(f->heatmap)) < 0)
			return (panic(f, "Error: allocating heatmap failed"));
	}
	init_heatmap(f);
	set_heatmap(&(f->heatmap));
	return (1);
}
