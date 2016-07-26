/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledieu <jledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 14:38:53 by jledieu           #+#    #+#             */
/*   Updated: 2016/04/23 17:14:02 by jledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void	ft_get_numplayer(t_info *info)
{
	char	*line;

	get_next_line(0, &line);
	info->numplayer = ft_atoi(&line[10]);
}

void	ft_get_letter(t_info *info)
{
	if (info->numplayer == 1)
		info->letter = 'O';
	else
		info->letter = 'X';
}

void	ft_get_h_and_w(t_info *info)
{
	char *line;

	get_next_line(0, &line);
	info->heightmap = ft_atoi(&line[8]);
	info->weightmap = ft_atoi(&line[11]);
}

void	ft_get_info(t_info *info)
{
	ft_get_numplayer(info);
	ft_get_letter(info);
	ft_get_h_and_w(info);
}
