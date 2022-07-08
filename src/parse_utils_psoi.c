/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_psoi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:44:58 by altikka           #+#    #+#             */
/*   Updated: 2022/07/08 10:08:08 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	update_psoi(t_grid *grid, t_pos *index)
{
	if (index->x < grid->min.x)
		grid->min.x = index->x;
	if (index->x > grid->max.x)
		grid->max.x = index->x;
	if (index->y < grid->min.y)
		grid->min.y = index->y;
	if (index->y > grid->max.y)
		grid->max.y = index->y;
}

void	set_grid_psoi(t_grid *grid, char target)
{
	t_pos	index;
	char	ch;

	grid->min.x = grid->size.x;
	grid->min.y = grid->size.y;
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
