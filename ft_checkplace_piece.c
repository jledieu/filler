/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkplace_piece.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledieu <jledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 13:44:13 by jledieu           #+#    #+#             */
/*   Updated: 2016/04/23 17:44:05 by jledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

static int	check_place(t_info *info, t_piece *piece, int x, int y)
{
	if (x > info->weightmap || x < 0)
		return (0);
	if (y > info->heightmap || y < 0)
		return (0);
	if (x + piece->weightpiece > info->weightmap)
		return (0);
	if (y + piece->heightpiece > info->heightmap)
		return (0);
	return (1);
}

static int	check_superpose(t_info *info, t_piece *piece, int x, int y)
{
	int		i;
	int		j;
	int		tmpx;
	int		compt;

	i = -1;
	tmpx = x;
	compt = 0;
	while (++i < piece->heightpiece)
	{
		j = -1;
		x = tmpx;
		while (++j < piece->weightpiece)
		{
			if (info->numplayer == 1)
				if (piece->piece[i][j] == '*' && info->map[y][x] == 'O')
					compt++;
			if (info->numplayer == 2)
				if (piece->piece[i][j] == '*' && info->map[y][x] == 'X')
					compt++;
			x++;
		}
		y++;
	}
	return ((compt > 1) ? 0 : 1);
}

static int	check_superpose_adverse(t_info *info, t_piece *piece, int x, int y)
{
	int		i;
	int		j;
	int		tmpx;

	i = 0;
	tmpx = x;
	while (i < piece->heightpiece)
	{
		j = 0;
		x = tmpx;
		while (j < piece->weightpiece)
		{
			if (info->numplayer == 1)
				if (piece->piece[i][j] == '*' && info->map[y][x] == 'X')
					return (0);
			if (info->numplayer == 2)
				if (piece->piece[i][j] == '*' && info->map[y][x] == 'O')
					return (0);
			j++;
			x++;
		}
		i++;
		y++;
	}
	return (1);
}

int			ft_checkplace_piece(t_info *info, t_piece *piece, int x, int y)
{
	if (check_place(info, piece, x, y) == 0)
		return (0);
	if (check_superpose(info, piece, x, y) == 0)
		return (0);
	if (check_superpose_adverse(info, piece, x, y) == 0)
		return (0);
	return (1);
}
