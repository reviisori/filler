/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:06:36 by altikka           #+#    #+#             */
/*   Updated: 2022/06/28 17:59:48 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	set_grid_psoi(t_filler *f)
{
	(void ) f;
	return (1);
}

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
		skip_next_line(); //skip 'Plateau: X Y'
	skip_next_line(); //skip line with '    01234...'
	ft_putstr_fd("TURN: ", 2);			//de
	ft_putnbr_fd(f->turn, 2);			//bug
	ft_putstr_fd("\n", 2);				//ging
	if (populate_grid(&(f->map), ".ox", 4) < 0) //offset = 4 to skip '000 '
		return (panic(f, "Error: couldn't populate map"));
	if (set_grid_psoi(f) < 0)
		return (panic(f, "Error: couldn't determine points of interest"));
	return (1);
}
