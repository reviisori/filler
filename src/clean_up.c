/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:30:33 by altikka           #+#    #+#             */
/*   Updated: 2022/06/28 11:44:40 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_data(t_filler *f)
{
	if (f->map.arr)
		ft_memdelarr(&(f->map.arr));
	if (f->heatmap.arr)
		ft_memdelarr(&(f->heatmap.arr));
	if (f->piece.arr)
		ft_memdelarr(&(f->piece.arr));
}

int	panic(t_filler *f, const char *msg)
{
	ft_putendl_fd(msg, 2);
	if (f)
		free_data(f);
	return (-1);
}
