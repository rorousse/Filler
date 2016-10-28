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
	int x;
	int y;
};

typedef struct s_coos t_coos;

struct	s_piece
{
	char	**forme;
	int		hauteur;
	int		largeur;
};

typedef struct s_piece t_piece;

struct	s_game
{
	int		largeur;
	int		hauteur;
	char	player;
	char	adv;
	t_coos	last_adv;
	char	**plateau;
	t_piece	piece;
};

typedef struct s_game t_game;

/*
**	GAME_C
*/

void	play_game(void);
/*
** INIT_C
*/

void	write_test(char *str);
void	write_plateau(char **plateau);
void	free_tab(char **tab);
void	init_game(t_game *partie);

/*
**	PIECE_C
*/

void	read_piece(t_game *partie);
int		check_pose(t_game partie, int x, int y);

/*
** PLATEAU_C
*/

char	**init_plateau(int x, int y);
void	init_size(t_game *partie);
void	lecture_plateau(t_game *partie);

/*
**	PLAYER_C
*/

int		algo_naif(t_game *partie);

#endif