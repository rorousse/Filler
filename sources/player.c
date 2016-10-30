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

static void	init_algo(t_coos *curr_play, int *i, int *j)
{
	*i = 0;
	*j = 0;
	curr_play->x = -1;
	curr_play->y = -1;
}

static int	print_answer(t_coos curr_play)
{
	if (curr_play.x != -1)
	{
		ft_putnbr(curr_play.y);
		ft_putchar(' ');
		ft_putnbr(curr_play.x);
		ft_putchar('\n');
		return (1);
	}
	return (0);
}

static void	find_last_play(t_game *partie)
{
	int			i;
	int			j;
	static int	b = 0;

	i = 0;
	while (i < partie->hauteur)
	{
		j = 0;
		while (j < partie->largeur)
		{
			if (partie->plateau[i][j] == partie->adv
			|| (b == 0 && partie->plateau[i][j] == partie->adv - 32))
			{
				b = 1;
				partie->last_adv.x = j;
				partie->last_adv.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int			algo_naif(t_game *partie)
{
	int				i;
	int				j;
	t_coos			curr_play;
	unsigned int	dist_rel;

	init_algo(&curr_play, &i, &j);
	dist_rel = partie->hauteur + partie->largeur;
	find_last_play(partie);
	while (i < partie->hauteur)
	{
		j = 0;
		while (j < partie->hauteur)
		{
			if (check_pose(*partie, i, j))
			{
				if (((ft_abs(i - partie->last_adv.y)
				+ ft_abs(j - partie->last_adv.x)) / 2) < dist_rel)
				{
					dist_rel = (ft_abs(i - partie->last_adv.y)
					+ ft_abs(j - partie->last_adv.x)) / 2;
					curr_play.x = j;
					curr_play.y = i;
				}
			}
			j++;
		}
		i++;
	}
	print_answer(curr_play);
	return (curr_play.x == -1) ?  0 : 1;
}
