/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:25:29 by altikka           #+#    #+#             */
/*   Updated: 2022/07/11 10:38:03 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

//move to place_utils
/*int	calc_heat(t_filler *f, t_pos index)
{
	int	total_heat;

	(void ) f;
	(void ) index;
	total_heat = 10000;
	return (total_heat);
}*/

//move to place_utils
int	is_legit_cell(t_filler *f, t_pos index, t_pos index_p, int *overlap)
{
	//dprintf(2, "is_legit_cell checking piece[%d][%d]", index_p.x, index_p.y);
	//dprintf(2, " at map[%d][%d]", index.x + index_p.x, index.y + index_p.y);
	//dprintf(2, " = '%c'\n",
	//	f->map.arr[index.x + index_p.x][index.y + index_p.y]);
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

	//dprintf(2, "checking legality of x[%d]y[%d]\n", index.x, index.y);
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
//	int	best_heat;
//	int	heat;
	int	ofs_y;
	int	res;
	int	own_spots_checked;

//	best_heat = 9000;
	ofs_y = index.y;
	res = -1;
	own_spots_checked = 0;
	while (index.x <= max.x)
	{
		index.y = ofs_y;
		while (index.y <= max.y)
		{
			//dprintf(2, "scanning x[%d]y[%d]\n", index.x, index.y);
			if (is_legit_spot(f, index) == 1)
			{
				res = 1;
				*answer = index;
//				heat = calc_heat(f, index);
//				if (heat < best_heat)
//				{
//					best_heat = heat;
//					*answer = index;
//				}
			}
			own_spots_checked++;
			index.y++;
		}
		index.x++;
	}
	//dprintf(2, "checked %d cells\n", own_spots_checked);
	return (res);
}

//move to place_utils
t_pos	calc_max(t_filler *f)
{
	t_pos	max;

	if (f->map.max.x <= f->map.size.x - (f->piece.size.x - f->piece.min.x))
		max.x = f->map.max.x - f->piece.min.x;
	else
		max.x = f->map.max.x - f->piece.max.x;
	if (f->map.max.y <= f->map.size.y - (f->piece.size.y - f->piece.min.y))
		max.y = f->map.max.y - f->piece.min.y;
	else
		max.y = f->map.max.y - f->piece.max.y;
	return (max);
}

//move to place_utils
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

//change RETURN to 1 later
int	place_piece(t_filler *f, t_pos *answer)
{
	t_pos	index;
	t_pos	max;

	index = calc_min(f);
	max = calc_max(f);
	//dprintf(2, "index[%d][%d] max[%d][%d]\n", index.x, index.y, max.x, max.y);
	if (scan_map(f, answer, index, max) < 0)
		return (-1);
	//dprintf(2, "tried[%d][%d]\n", answer->x, answer->y);
	return (1);
}
