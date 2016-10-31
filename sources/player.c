/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 10:59:06 by rorousse          #+#    #+#             */
/*   Updated: 2016/09/29 10:59:07 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "../libft/libft.h"

static void	init_algo(t_game *match, t_coos *curr_play, int *i, int *j)
{
	*i = (match->piece.h) * (-1);
	*j = (match->piece.l) * (-1);
	curr_play->x = *j;
	curr_play->y = *i;
	curr_play->change = 0;
}

static void	calc_rel_dist(t_game *match, t_coos *curr_play, int i, int j)
{
	if (check_pose(*match, i, j))
	{
		if (((ft_abs(i - match->last_adv.y)
		+ ft_abs(j - match->last_adv.x))) < curr_play->rel_dist)
		{
			curr_play->rel_dist = (ft_abs(i - match->last_adv.y)
			+ ft_abs(j - match->last_adv.x));
			curr_play->x = j;
			curr_play->y = i;
			curr_play->change = 1;
		}
	}
}

static void	print_answer(t_coos curr_play)
{
	ft_putnbr(curr_play.y);
	ft_putchar(' ');
	ft_putnbr(curr_play.x);
	ft_putchar('\n');
}

static void	find_last_play(t_game *match)
{
	int			i;
	int			j;
	static int	b = 0;

	i = 0;
	while (i < match->h)
	{
		j = 0;
		while (j < match->l)
		{
			if (match->board[i][j] == match->adv
			|| (b == 0 && match->board[i][j] == match->adv - 32))
			{
				b = 1;
				match->last_adv.x = j;
				match->last_adv.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int			algo_naif(t_game *match)
{
	int				i;
	int				j;
	t_coos			curr_play;

	init_algo(match, &curr_play, &i, &j);
	curr_play.rel_dist = match->h + match->l;
	find_last_play(match);
	while (i < match->h)
	{
		j = (match->piece.l) * (-1);
		while (j < match->h)
		{
			calc_rel_dist(match, &curr_play, i, j);
			j++;
		}
		i++;
	}
	print_answer(curr_play);
	write_board(match->piece.shape);
	return (curr_play.change);
}
