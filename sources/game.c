/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 18:35:07 by rorousse          #+#    #+#             */
/*   Updated: 2016/09/28 18:35:09 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	play_game(void)
{
	t_game	match;
	int		ret;

	init_game(&match);
	ret = 1;
	while (ret == 1)
	{
		read_game(&match);
		read_piece(&match);
		ret = algo_naif(&match);
		free_tab(match.piece.shape);
	}
	free_tab(match.board);
}
