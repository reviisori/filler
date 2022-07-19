/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:30:33 by altikka           #+#    #+#             */
/*   Updated: 2022/07/19 16:22:02 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_data(t_filler *f)
{
	if (f->map.arr)
		ft_strdelarr(&(f->map.arr));
	if (f->heatmap.arr)
		ft_strdelarr(&(f->heatmap.arr));
	if (f->piece.arr)
		ft_strdelarr(&(f->piece.arr));
}

int	panic(t_filler *f, const char *msg)
{
	ft_putendl_fd(msg, 2);
	if (f)
		free_data(f);
	//
	system("leaks altikka.filler > leaks.txt");
	return (-1);
}
