/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:26:18 by altikka           #+#    #+#             */
/*   Updated: 2022/07/08 16:48:22 by altikka          ###   ########.fr       */
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

	file = fopen("debug.txt", "a+");
	if (!file)
		return (-1);
	fprintf(file, " Our hero: '%c' \t\t\tOpponent: %c \t Turn: *%d\n",
		f->player, f->opponent, f->turn);
	fprintf(file, " Plateau [%d,%d] \t\tHeatmap\t\t Piece [%d,%d]\n",
		f->map.size.x, f->map.size.y, f->piece.size.x, f->piece.size.y);
	fprintf(file, " min/max [%d,%d] [%d,%d]\t\t[%d,%d] [%d,%d]\t", f->map.min.x,
		f->map.min.y, f->map.max.x, f->map.max.y, f->heatmap.min.x,
		f->heatmap.min.y, f->heatmap.max.x, f->heatmap.max.y);
	fprintf(file, " [%d,%d] [%d,%d]\n\n", f->piece.min.x, f->piece.min.y,
		f->piece.max.x, f->piece.max.y);
	print_grid(f, file);
	if (fclose(file) == -1)
		return (-1);
	return (1);
}
