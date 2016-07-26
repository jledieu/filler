/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_and_piece.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledieu <jledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 21:03:38 by jledieu           #+#    #+#             */
/*   Updated: 2016/04/23 17:43:45 by jledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void	ft_get_piece(t_piece *piece)
{
	char	*line;
	char	*piecejoin;
	int		i;
	int		nblinepiece;

	i = 0;
	piecejoin = "\0";
	nblinepiece = 0;
	get_next_line(0, &line);
	while (ft_isdigit(line[i]) == 0)
		i++;
	piece->heightpiece = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]) == 1)
		i++;
	i++;
	piece->weightpiece = ft_atoi(&line[i]);
	while (get_next_line(0, &line) > 0)
	{
		piecejoin = ft_strjoin(piecejoin, line);
		piecejoin = ft_strjoin(piecejoin, "\n");
		nblinepiece++;
		if (nblinepiece == piece->heightpiece)
			break ;
	}
	piece->piece = ft_strsplit(piecejoin, '\n');
}

void	ft_get_map(t_info *info, t_piece *piece)
{
	char	*line;
	char	*mapjoin;
	int		nbline;

	mapjoin = "\0";
	nbline = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_isdigit(line[0]) == 1)
		{
			mapjoin = ft_strjoin(mapjoin, &line[4]);
			mapjoin = ft_strjoin(mapjoin, "\n");
			nbline++;
		}
		if (nbline == info->heightmap)
			break ;
	}
	info->map = ft_strsplit(mapjoin, '\n');
	ft_get_piece(piece);
}

void	ft_get_midmap(t_info *info)
{
	int		midmap;
	int		j;

	j = 0;
	midmap = (info->heightmap / 2) - (info->heightmap / 10);
	while (info->map[midmap][j] != '\0')
	{
		if (info->map[midmap][j] == 'X')
			info->midmap = midmap;
		j++;
	}
}
