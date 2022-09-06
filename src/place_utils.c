/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:30:44 by altikka           #+#    #+#             */
/*   Updated: 2022/09/06 17:39:32 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	adjust_placement(t_filler *f, t_pos *answer, t_pos index)
{
	if (f->heat < f->best_heat)
	{
		f->best_heat = f->heat;
		*answer = index;
	}
	if (f->heat == f->best_heat)
	{
		if (f->heatmap.max.x < f->map.max.x || f->heatmap.max.y < f->map.max.y)
		{
			if ((f->heatmap.max.x + 1 < f->map.size.x
					|| f->heatmap.max.y + 1 < f->map.size.y)
				&& f->map.size.x - f->heatmap.max.x
				> f->map.size.y - f->heatmap.max.y)
			{
				if (index.x > answer->x || index.y < answer->y)
					*answer = index;
			}
			else
			{
				if (index.x < answer->x || index.y > answer->y)
					*answer = index;
			}
		}
		f->best_heat = f->heat;
	}
}

int	calc_heat(t_filler *f, t_pos index)
{
	t_pos	index_p;
	int		ofs_y;
	int		heat;

	index_p = f->piece.min;
	ofs_y = index_p.y;
	heat = 0;
	while (index_p.x <= f->piece.max.x)
	{
		index_p.y = ofs_y;
		while (index_p.y <= f->piece.max.y)
		{
			if (f->piece.arr[index_p.x][index_p.y] == '*')
				heat += (int ) f->heatmap.arr[index.x + index_p.x]
				[index.y + index_p.y];
			index_p.y++;
		}
		index_p.x++;
	}
	return (heat);
}

t_pos	calc_max(t_filler *f)
{
	t_pos	max;

	if (f->map.max.x <= f->map.size.x - (f->piece.max.x - f->piece.min.x + 1))
		max.x = f->map.max.x - f->piece.min.x;
	else
		max.x = f->map.size.x - (f->piece.max.x + 1);
	if (f->map.max.y <= f->map.size.y - (f->piece.max.y - f->piece.min.y + 1))
		max.y = f->map.max.y - f->piece.min.y;
	else
		max.y = f->map.size.y - (f->piece.max.y + 1);
	return (max);
}

t_pos	calc_min(t_filler *f)
{
	t_pos	min;

	min.x = f->map.min.x - f->piece.max.x;
	if (min.x + f->piece.min.x < 0)
		min.x = 0 - f->piece.min.x;
	min.y = f->map.min.y - f->piece.max.y;
	if (min.y + f->piece.min.y < 0)
		min.y = 0 - f->piece.min.y;
	return (min);
}
