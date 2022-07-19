/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:25:29 by altikka           #+#    #+#             */
/*   Updated: 2022/07/19 16:29:29 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	is_legit_cell(t_filler *f, t_pos index, t_pos index_p, int *overlap)
{
	if (ft_toupper(f->map.arr[index.x + index_p.x]
			[index.y + index_p.y]) == f->opponent)
		return (-1);
	if (ft_toupper(f->map.arr[index.x + index_p.x]
			[index.y + index_p.y]) == f->player)
		(*overlap)++;
	if (*overlap > 1)
		return (-1);
	return (1);
}

static int	is_legit_spot(t_filler *f, t_pos index)
{
	t_pos	index_p;
	int		overlap;
	int		ofs_y;

	index_p = f->piece.min;
	overlap = 0;
	ofs_y = index_p.y;
	while (index_p.x <= f->piece.max.x)
	{
		index_p.y = ofs_y;
		while (index_p.y <= f->piece.max.y)
		{
			if (f->piece.arr[index_p.x][index_p.y] == '*')
			{
				if (is_legit_cell(f, index, index_p, &overlap) == -1)
					return (-1);
			}
			index_p.y++;
		}
		index_p.x++;
	}
	return (overlap);
}

static int	scan_map(t_filler *f, t_pos *answer, t_pos index, t_pos max)
{
	int	ofs_y;
	int	res;

	ofs_y = index.y;
	res = -1;
	while (index.x <= max.x)
	{
		index.y = ofs_y;
		while (index.y <= max.y)
		{
			if (is_legit_spot(f, index) == 1)
			{
				res = 1;
				f->heat = calc_heat(f, index);
				if (f->heat < f->best_heat)
				{
					f->best_heat = f->heat;
					*answer = index;
				}
			}
			index.y++;
		}
		index.x++;
	}
	return (res);
}

int	place_piece(t_filler *f, t_pos *answer)
{
	t_pos	index;
	t_pos	max;

	f->best_heat = DEFAULT_HEAT;//
	index = calc_min(f);
	max = calc_max(f);
	if (scan_map(f, answer, index, max) < 0)
		return (-1);
	return (-1);// change to 1
}
