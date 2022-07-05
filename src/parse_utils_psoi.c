/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_psoi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:44:58 by altikka           #+#    #+#             */
/*   Updated: 2022/07/05 14:13:26 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	update_psoi(t_grid *grid, t_pos *index)
{
	if (index->x < grid->start.x)
		grid->start.x = index->x;
	if (index->x > grid->end.x)
		grid->end.x = index->x;
	if (index->y < grid->start.y)
		grid->start.y = index->y;
	if (index->y > grid->end.y)
		grid->end.y = index->y;
}

void	set_grid_psoi(t_grid *grid, char target)
{
	t_pos	index;
	char	ch;

	grid->start.x = grid->size.x;
	grid->start.y = grid->size.y;
	index.x = 0;
	while (index.x < grid->size.x)
	{
		index.y = 0;
		while (index.y < grid->size.y)
		{
			ch = grid->arr[index.x][index.y];
			if (ft_toupper(ch) == target)
				update_psoi(grid, &index);
			index.y++;
		}
		index.x++;
	}
}
