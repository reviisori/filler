/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:35:27 by altikka           #+#    #+#             */
/*   Updated: 2022/06/27 14:49:19 by altikka          ###   ########.fr       */
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
	t_pos	size;			//plateau size/raw piece size
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
int		parse_map(t_filler *f);
int		skip_next_line(void);
int		set_grid_size(t_pos *size, char *needle);
int		allocate_grid(t_grid *grid);
int		populate_grid(t_grid *grid, char *marks, int ofs);
int		set_grid_psoi(t_grid *grid);
void	free_data(t_filler *f);
int		place_piece(t_filler *f, t_pos *answer);

#endif
