/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 14:22:31 by rorousse          #+#    #+#             */
/*   Updated: 2016/09/27 14:22:34 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

struct s_coos
{
	int 			x;
	int 			y;
	unsigned int	rel_dist;
	int				change;
};

typedef struct s_coos t_coos;

struct	s_piece
{
	char	**shape;
	int		h;
	int		l;
};

typedef struct s_piece t_piece;

struct	s_game
{
	int		l;
	int		h;
	char	player;
	char	adv;
	t_coos	last_adv;
	char	**board;
	t_piece	piece;
};

typedef struct s_game t_game;

/*
** BOARD_C
*/

char	**init_board(int x, int y);
void	init_size(t_game *match);
void	read_game(t_game *match);

/*
**	GAME_C
*/

void	play_game(void);

/*
** INIT_C
*/

void	free_tab(char **tab);
void	init_game(t_game *match);

/*
**	PIECE_C
*/

void	read_piece(t_game *match);
int		check_pose(t_game match, int x, int y);

/*
**	PLAYER_C
*/

int		algo_naif(t_game *match);

/*
**	TESTING_C
*/

void	write_test(char *str);
void	write_board(char **plateau);

#endif