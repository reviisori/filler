/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:06:36 by altikka           #+#    #+#             */
/*   Updated: 2022/07/06 14:18:33 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

//31: skip 'Plateau: X Y'
//32: skip '    01234...'
//33: skip '000 ' w/ offset 4 in the beginning of the line
//35: points of interest

int	parse_map(t_filler *f)
{
	// (f->turn < 3)
	if (!f->map.arr)
	{
		if (set_grid_size(&(f->map.size), "Plateau") < 0)
			return (panic(NULL, "Error: invalid map size"));
		if (allocate_grid(&(f->map)) < 0)
			return (panic(NULL, "Error: allocating map failed"));
	}
	else
		skip_next_line();
	skip_next_line();
	if (populate_grid(&(f->map), ".ox", 4) < 0)
		return (panic(f, "Error: couldn't populate map"));
	set_grid_psoi(&(f->map), f->player);
	return (1);
}
