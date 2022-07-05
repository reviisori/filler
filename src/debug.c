/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:26:18 by altikka           #+#    #+#             */
/*   Updated: 2022/07/05 17:13:01 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int	debug(t_filler *f)
{
	FILE	*file;
	char	**m, **p, **h;

	file = fopen("debug.txt", "w+");
	if (!file)
		return (-1);
	//player info:
	fprintf(file, "Our hero: %c | Opponent: %c |  Turn:  %d\n", f->player,
			f->opponent, f->turn);
	//map size & turn number:
	fprintf(file, "Plateau: [%d,%d]   -&-   Piece: [%d,%d]\n", f->map.size.x,
			f->map.size.y, f->piece.size.x, f->piece.size.y);
	//map & piece:
	m = (char **) f->map.arr;
	p = (char **) f->piece.arr;
	while (*m)
	{
		fprintf(file, "\t %s    ", *m);
		if (*p)
		{
			fprintf(file, "%s\n", *p);
			p++;
		}
		else
			fprintf(file, "\n");
		m++;
	}
	//map's points of interest:
	fprintf(file, "\t  [%d,%d] [%d,%d]  ", f->map.start.x,
			f->map.start.y, f->map.end.x, f->map.end.y);
	//piece's points of interest:
	fprintf(file, "  [%d,%d] [%d,%d]\n", f->piece.start.x,
			f->piece.start.y, f->piece.end.x, f->piece.end.y);
	//heatmap:
	fprintf(file, "Heatmap:\n");
	h = (char **) f->heatmap.arr;
	while (*h)
	{
		fprintf(file, "\t %s    \n", *h);
		h++;
	}
	if (fclose(file) == -1)
		return (-1);
	return (1);
}
