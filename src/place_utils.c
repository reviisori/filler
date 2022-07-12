/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:30:44 by altikka           #+#    #+#             */
/*   Updated: 2022/07/12 12:34:50 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
