/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:23:26 by altikka           #+#    #+#             */
/*   Updated: 2022/07/21 15:45:25 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	parse_data(t_filler *f)
{
	if (f)
		free_data(f);
	ft_bzero(&(f->map.min), sizeof(f->map.min));
	ft_bzero(&(f->map.max), sizeof(f->map.max));
	if (parse_map(f) < 0)
		return (panic(NULL, "Error: unable to parse map"));
	ft_bzero(&(f->piece.min), sizeof(f->piece.min));
	ft_bzero(&(f->piece.max), sizeof(f->piece.max));
	if (parse_piece(f) < 0)
		return (panic(NULL, "Error: unable to parse piece"));
	ft_bzero(&(f->heatmap.min), sizeof(f->heatmap.min));
	ft_bzero(&(f->heatmap.max), sizeof(f->heatmap.max));
	if (parse_heatmap(f) < 0)
		return (panic(NULL, "Error: unable to parse heatmap"));
	return (1);
}
