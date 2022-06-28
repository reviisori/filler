/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:25:29 by altikka           #+#    #+#             */
/*   Updated: 2022/06/28 16:22:13 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	place_piece(t_filler *f, t_pos *answer)
{
	(void ) f;
	answer->x = 4;
	answer->y = 2;
	return (-1);//change to 1 later
}
