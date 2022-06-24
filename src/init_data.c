/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:37:02 by altikka           #+#    #+#             */
/*   Updated: 2022/06/24 11:58:57 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	init_players(t_filler *f)
{
	char	*line;
	char	*p;

	if (f->player)
		return (1);
	if (get_next_line(0, &line) <= 0)
		return (panic(NULL, "Error: couldn't get player info"));
	p = ft_strchr(line, 'p');
	p++;
	if (*p == '1' || *p == '2')
	{
		f->player = 'O' + (*p == '2') * 9;
		f->opponent = 'X' - (*p == '2') * 9;
	}
	else
	{
		ft_strdel(&line);
		return (panic(NULL, "Error: invalid player number(s)"));
	}
	ft_strdel(&line);
	return (1);
}

int	init_data(t_filler *f)
{
	ft_bzero(f, sizeof(*f));
	init_players(f);
	f->turn = 1 + (f-player == 'X');
	return (1);
}
