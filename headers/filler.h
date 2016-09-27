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

struct	s_game
{
	int		x;
	int		y;
	char	player;
	char	adv;
	char	**plateau;
};

typedef struct s_game t_game;

/*
** INIT_C
*/

void	init_game(void);

/*
** PLATEAU_C
*/

char	**init_plateau(int x, int y);
void	free_plateau(char **plateau);
void	lecture_plateau(t_game partie);

#endif