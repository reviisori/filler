/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:06:36 by altikka           #+#    #+#             */
/*   Updated: 2022/06/30 13:51:33 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	parse_map(t_filler *f)
{
	// (f->turn < 3)
	if (!f->map.arr)
	{
		if (set_grid_size(&(f->map.size), "Plateau") < 0)
			return (panic(NULL, "Error: invalid map size"));
		if (allocate_grid(&(f->map), sizeof(char)) < 0)
			return (panic(NULL, "Error: allocating map failed"));
	}
	else
		skip_next_line(); 						//skip 'Plateau: X Y'
	skip_next_line(); 							//skip line with '    01234...'
	if (populate_grid(&(f->map), ".ox", 4) < 0) //offset = 4 to skip '000 '
		return (panic(f, "Error: couldn't populate map"));
	set_grid_psoi(&(f->map), f->player);		//points of interest
	return (1);
}
