/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:50:10 by altikka           #+#    #+#             */
/*   Updated: 2022/07/05 14:39:14 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	parse_piece(t_filler *f)
{
	if (set_grid_size(&(f->piece.size), "Piece") < 0)
		return (panic(NULL, "Error: invalid piece size"));
	if (allocate_grid(&(f->piece)) < 0)
		return (panic(NULL, "Error: allocating piece failed"));
	if (populate_grid(&(f->piece), ".*", 0) < 0)
		return (panic(f, "Error: couldn't populate piece"));
	set_grid_psoi(&(f->piece), '*');
	return (1);
}
