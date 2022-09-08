/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:18:34 by altikka           #+#    #+#             */
/*   Updated: 2022/09/08 11:02:08 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
 *30: optional debugging function
 */

int	main(void)
{
	t_filler	f;
	t_pos		answer;
	int			ret;

	if (init_data(&f) < 0)
		return (panic(NULL, "Error: data initialization failed"));
	ret = 1;
	while (ret > 0)
	{
		if (parse_data(&f) < 0)
			return (panic(&f, "Error: data parsing failed"));
		debug(&f);
		if (place_piece(&f, &answer) == 1)
			ft_printf("%d %d\n", answer.x, answer.y);
		else
		{
			ft_printf("0 0\n");
			ret = 0;
		}
		f.turn += 2;
	}
	free_data(&f);
	return (0);
}
