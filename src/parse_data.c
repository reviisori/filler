/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:23:26 by altikka           #+#    #+#             */
/*   Updated: 2022/06/30 14:49:54 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	parse_data(t_filler *f)
{
	ft_bzero(&(f->map.start), sizeof(f->map.start));
	ft_bzero(&(f->map.end), sizeof(f->map.end));
	if (parse_map(f) < 0)
		return (panic(NULL, "Error: unable to parse map"));
	ft_bzero(&(f->piece.start), sizeof(f->piece.start));
	ft_bzero(&(f->piece.end), sizeof(f->piece.end));
	if (parse_piece(f) < 0)
		return (panic(f, "Error: unable to parse piece"));
//	if (parse_heatmap(f) < 0)
//		return (panic(f, "Error: unable to parse heatmap"));
	return (1);
}
