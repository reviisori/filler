/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:35:27 by altikka           #+#    #+#             */
/*   Updated: 2022/07/21 15:48:58 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# include "libft.h"

# define DEFAULT_HEAT 9000

typedef struct s_pos
{
	int		x;
	int		y;
}		t_pos;

typedef struct s_grid
{
	char	**arr;
	t_pos	size;
	t_pos	min;
	t_pos	max;
}		t_grid;

typedef struct s_filler
{
	t_grid	map;
	t_grid	heatmap;
	t_grid	piece;
	char	player;
	char	opponent;
	int		turn;
	int		best_heat;
	int		heat;
}		t_filler;

int		init_data(t_filler *f);
int		panic(t_filler *f, const char *msg);
int		debug(t_filler *f);
int		parse_data(t_filler *f);
int		parse_map(t_filler *f);
int		parse_piece(t_filler *f);
int		parse_heatmap(t_filler *f);
int		skip_next_line(void);
int		set_grid_size(t_pos *size, char *needle);
int		allocate_grid(t_grid *grid);
int		populate_grid(t_grid *grid, char *marks, int ofs);
void	set_grid_psoi(t_grid *grid, char target);
void	free_data(t_filler *f);
int		place_piece(t_filler *f, t_pos *answer);
t_pos	calc_min(t_filler *f);
t_pos	calc_max(t_filler *f);
int		calc_heat(t_filler *f, t_pos index);

#endif
