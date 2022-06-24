/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:26:52 by altikka           #+#    #+#             */
/*   Updated: 2022/06/15 19:49:46 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"

int	ft_vecpush(t_vec *dest, const void *src)
{
	if (!dest || !src)
		return (-1);
	if (!dest->data)
		if (ft_vecnew(dest, 1, dest->type) < 0)
			return (-1);
	if (dest->type * dest->len >= dest->alloc_size)
		if (ft_vecresize(dest, dest->alloc_size * 2) < 0)
			return (-1);
	ft_memcpy(&dest->data[dest->type * dest->len], src, dest->type);
	dest->len++;
	return (1);
}
