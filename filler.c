/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledieu <jledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 22:01:22 by jledieu           #+#    #+#             */
/*   Updated: 2016/04/23 17:13:51 by jledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

static void		init_struct(t_info *info, t_piece *piece)
{
	info->numplayer = 0;
	info->midmap = 0;
	info->stopaggresive = 0;
	info->cantplace = 0;
	info->cantplacerl = 0;
	info->finish = 0;
	piece->heightpiece = 0;
	piece->weightpiece = 0;
}

int				main(void)
{
	t_info	info;
	t_piece	piece;

	init_struct(&info, &piece);
	ft_get_info(&info);
	while (1)
	{
		if (info.numplayer == 1)
			if (player_1(&info, &piece) == 0)
				break ;
		if (info.numplayer == 2)
			if (player_2(&info, &piece) == 0)
				break ;
	}
}
