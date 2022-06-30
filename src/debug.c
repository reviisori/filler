/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:26:18 by altikka           #+#    #+#             */
/*   Updated: 2022/06/30 15:55:46 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int	debug(t_filler *f)
{
	FILE	*file;
	char	**m;
	char	**p;

	file = fopen("debug.txt", "w+");
	if (!file)
		return (-1);
	//player info:
	fprintf(file, "Our hero: %c | Opponent: %c\n", f->player, f->opponent);
	//map size & turn number:
	fprintf(file, "Plateau [%d] [%d] after turn: %d\n", f->map.size.x,
			f->map.size.y, f->turn);
	//map itself:
	m = (char **) f->map.arr;
	while (*m)
	{
		fprintf(file, "\t %s\n", *m);
		m++;
	}
	//map's points of interest:
	fprintf(file, "    hi: [%d][%d] | low: [%d][%d]\n", f->map.start.x,
			f->map.start.y, f->map.end.x, f->map.end.y);
	//piece size:
	fprintf(file, "Piece [%d] [%d] to place:\n", f->piece.size.x,
		f->piece.size.y);
	//piece itself:
	p = (char **) f->piece.arr;
	while (*p)
	{
		fprintf(file, "\t %s\n", *p);
		p++;
	}
	//piece's points of interest:
	fprintf(file, "    hi: [%d][%d] | low: [%d][%d]\n", f->piece.start.x,
			f->piece.start.y, f->piece.end.x, f->piece.end.y);
	if (fclose(file) == -1)
		return (-1);
	return (1);
}
