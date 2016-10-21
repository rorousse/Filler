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

void	play_game()
{
	t_game	partie;
	int		ret;

	init_game(&partie);
	ret = 1;
	// init ok
	while (ret == 1)
	{
		lecture_plateau(&partie);
		read_piece(&partie);
		write_plateau(partie.piece.forme);
		write_test("in");
		ret = algo_naif(&partie);
		write_test("out");
		free_tab(partie.piece.forme);
	}
	free_tab(partie.plateau);
}