/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:26:18 by altikka           #+#    #+#             */
/*   Updated: 2022/07/07 11:04:12 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

static void	print_grid(t_filler *f, FILE *file)
{
	char	**m;
	char	**h;
	char	**p;

	m = f->map.arr;
	h = f->heatmap.arr;
	p = f->piece.arr;
	while (*m)
	{
		fprintf(file, "\t %s    ", *m);
		fprintf(file, "%s    ", *h);
		if (*p)
		{
			fprintf(file, "%s\n", *p);
			p++;
		}
		else
			fprintf(file, "\n");
		m++;
		h++;
	}
	fprintf(file, "\n");
}

//player info:
//map & piece size:
//points of interest:
//map, heatmap & piece:

int	debug(t_filler *f)
{
	FILE	*file;

	file = fopen("debug.txt", "w+");
	if (!file)
		return (-1);
	fprintf(file, " Our hero: '%c' \t\t\tOpponent: %c \t Turn: *%d\n",
		f->player, f->opponent, f->turn);
	fprintf(file, " Plateau [%d,%d] \t\tHeatmap\t\t Piece [%d,%d]\n",
		f->map.size.x, f->map.size.y, f->piece.size.x, f->piece.size.y);
	fprintf(file, " min/max [%d,%d] [%d,%d]\t[%d,%d] [%d,%d]\t", f->map.start.x,
		f->map.start.y, f->map.end.x, f->map.end.y, f->heatmap.start.x,
		f->heatmap.start.y, f->heatmap.end.x, f->heatmap.end.y);
	fprintf(file, " [%d,%d] [%d,%d]\n\n", f->piece.start.x, f->piece.start.y,
		f->piece.end.x, f->piece.end.y);
	print_grid(f, file);
	if (fclose(file) == -1)
		return (-1);
	return (1);
}
