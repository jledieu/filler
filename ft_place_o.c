/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledieu <jledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 14:15:50 by jledieu           #+#    #+#             */
/*   Updated: 2016/04/23 18:41:37 by jledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

static int	ft_take_piece_right(t_info *info, t_piece *piece, int y, int x)
{
	int		i;
	int		j;

	i = piece->heightpiece - 1;
	while (i >= 0)
	{
		j = piece->weightpiece - 1;
		while (j >= 0)
		{
			if (piece->piece[i][j] == '*')
			{
				if (ft_checkplace_piece(info, piece, x - j, y - i))
				{
					ft_putnbr(y - i);
					ft_putchar(' ');
					ft_putnbr(x - j);
					ft_putchar('\n');
					return (1);
				}
			}
			j--;
		}
		i--;
	}
	return (0);
}

static int	ft_take_piece_left(t_info *info, t_piece *piece, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	while (i < piece->heightpiece)
	{
		j = 0;
		while (j < piece->weightpiece)
		{
			if (piece->piece[i][j] == '*')
			{
				if (ft_checkplace_piece(info, piece, x - j, y - i))
				{
					ft_putnbr(y - i);
					ft_putchar(' ');
					ft_putnbr(x - j);
					ft_putchar('\n');
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

void		ft_place_top_o(t_info *info, t_piece *piece)
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
				if (ft_take_piece_right(info, piece, y, x) == 1)
					return ;
			x++;
		}
		y++;
	}
	info->cantplace = 1;
}

void		ft_place_bot_o(t_info *info, t_piece *piece)
{
	int		y;
	int		x;

	y = info->heightmap - 1;
	while (y > 0)
	{
		x = info->weightmap - 1;
		while (x > 0)
		{
			if (info->map[y][x] == info->letter)
				if (ft_take_piece_left(info, piece, y, x) == 1)
					return ;
			x--;
		}
		y--;
	}
	info->finish = 1;
}

void		ft_place_left_o(t_info *info, t_piece *piece)
{
	int		y;
	int		x;

	y = info->midmap + (info->heightmap / 10) - (info->heightmap / 11);
	while (y < info->midmap + (info->heightmap / 10) + (info->heightmap / 11))
	{
		x = 0;
		while (x < info->weightmap)
		{
			if (info->map[y][x] == info->letter)
				if (ft_take_piece_right(info, piece, y, x) == 1)
					return ;
			x++;
		}
		y++;
	}
	info->cantplacerl = 1;
}
