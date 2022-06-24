/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:18:34 by altikka           #+#    #+#             */
/*   Updated: 2022/06/24 10:55:19 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
			return (panic(NULL, "Error: data parsing failed"));
		if (place_piece(&f, &answer) == 1)
			ft_printf("%d %d\n", answer.x, answer.y);
		else
		{
			ft_printf("0 0\n");
			ret = -1;
		}
	}
	free_data(&f);
	return (0);
}
