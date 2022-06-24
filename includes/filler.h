/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:35:27 by altikka           #+#    #+#             */
/*   Updated: 2022/06/24 11:26:00 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# include "libft.h"

typedef struct s_pos
{
	int		x;
	int		y;
}		t_pos;

typedef struct s_grid
{
	void	**arr;
	t_pos	size;			//raw size
	t_pos	start;			//highest point
	t_pos	end;			//lowest point
}		t_grid;

typedef struct s_filler
{
	t_grid	map;
	t_grid	heatmap;
	t_grid	piece;
	char	player;
	char	opponent;
	int		turn;			//for debugging
}		t_filler;

int		init_data(t_filler *f);
int		panic(t_filler *f, const char *msg);
int		parse_data(t_filler *f);
//		more parsing functions...
void	free_data(t_filler *f);
int		place_piece(t_filler *f, t_pos *answer);

#endif
