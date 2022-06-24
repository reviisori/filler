/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:19:35 by altikka           #+#    #+#             */
/*   Updated: 2022/05/02 16:59:37 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H

# define VEC_H

# include "libft.h"

typedef struct s_vec
{
	void	*data;
	size_t	alloc_size;
	size_t	type;
	size_t	len;
}		t_vec;

int		ft_vecnew(t_vec *dest, size_t init_len, size_t type);
void	ft_vecdel(t_vec *src);
int		ft_veccpy(t_vec *dest, t_vec *src);
int		ft_vecresize(t_vec *src, size_t new_size);
int		ft_vecpush(t_vec *dest, const void *src);
int		ft_vecappend(t_vec *dest, t_vec *src);
int		ft_vecncat(t_vec *dest, const void *src, size_t n);

#endif
