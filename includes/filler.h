/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledieu <jledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 22:01:31 by jledieu           #+#    #+#             */
/*   Updated: 2016/04/23 17:46:40 by jledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <fcntl.h>
# include "../libft/includes/libft.h"

typedef struct	s_info
{
	int		numplayer;
	int		midmap;
	int		heightmap;
	int		weightmap;
	int		stopaggresive;
	int		cantplace;
	int		cantplacerl;
	int		finish;
	char	letter;
	char	**map;
}				t_info;

typedef struct	s_piece
{
	int		heightpiece;
	int		weightpiece;
	int		x;
	int		y;
	char	**piece;
}				t_piece;

void			ft_place_top_x(t_info *info, t_piece *piece);
void			ft_place_bot_x(t_info *info, t_piece *piece);
void			ft_place_right_x(t_info *info, t_piece *piece);
void			ft_place_block_x(t_info *info, t_piece *piece);
void			ft_place_top_o(t_info *info, t_piece *piece);
void			ft_place_bot_o(t_info *info, t_piece *piece);
void			ft_place_left_o(t_info *info, t_piece *piece);
void			ft_get_info(t_info *info);
void			ft_get_map(t_info *info, t_piece *piece);
void			ft_get_midmap(t_info *info);
int				player_1(t_info *info, t_piece *piece);
int				player_2(t_info *info, t_piece *piece);
int				ft_checkplace_piece(t_info *info, t_piece *piece, int x, int y);
int				get_next_line(int const fd, char **line);
#endif
