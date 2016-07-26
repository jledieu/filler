/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledieu <jledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:03:24 by jledieu           #+#    #+#             */
/*   Updated: 2016/04/23 17:14:21 by jledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

static int		ft_check_column(t_info *info, int x)
{
	int		y;

	y = 0;
	while (y < info->heightmap)
	{
		if (info->map[y][x] == info->letter)
			return (1);
		y++;
	}
	return (0);
}

static int		ft_check_line_bot(t_info *info, int y, char c)
{
	int		x;

	x = 0;
	while (x < info->weightmap)
	{
		if (info->map[y][x] == c || info->map[y][x] == ft_toupper(c))
			return (1);
		x++;
	}
	return (0);
}

static int		ft_checkaggresive_bot(t_info *info)
{
	int		y;
	int		x;

	y = 0;
	while (y < info->heightmap)
	{
		x = 0;
		while (x < info->weightmap)
		{
			if (info->map[y][x] == info->letter)
			{
				if (ft_check_line_bot(info, y, 'o') == 1)
					return (1);
				else
					return (0);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static void		ft_checkstopaggresive_bot(t_info *info)
{
	int		x;

	x = 0;
	while (x < info->weightmap)
	{
		if (info->map[info->heightmap - 1][x] == info->letter)
		{
			info->stopaggresive = 1;
			return ;
		}
		x++;
	}
	info->stopaggresive = 0;
}

int				player_2(t_info *info, t_piece *piece)
{
	info->cantplace = 0;
	ft_get_map(info, piece);
	ft_get_midmap(info);
	ft_checkstopaggresive_bot(info);
	if (ft_check_column(info, info->weightmap - 1) == 0 &&
	ft_check_column(info, 0) == 0 &&
	ft_check_line_bot(info, info->midmap, 'x') == 1 &&
	ft_checkaggresive_bot(info) == 0)
		ft_place_right_x(info, piece);
	else if (ft_checkaggresive_bot(info) == 1 && info->stopaggresive == 0)
		ft_place_bot_x(info, piece);
	else
		ft_place_top_x(info, piece);
	if (info->cantplace == 1 || info->cantplacerl == 1)
		ft_place_top_x(info, piece);
	if (info->finish == 1)
	{
		ft_putnbr(0);
		ft_putchar(' ');
		ft_putnbr(0);
		ft_putchar('\n');
		return (0);
	}
	return (1);
}
