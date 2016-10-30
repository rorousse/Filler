/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 14:25:23 by rorousse          #+#    #+#             */
/*   Updated: 2016/09/27 14:25:24 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "filler.h"

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	init_game(t_game *match)
{
	char	*line;

	get_next_line(0, &line);
	free(line);
	if (line[10] == '1')
	{
		match->player = 'o';
		match->adv = 'x';
	}
	else
	{
		match->player = 'x';
		match->adv = 'o';
	}
	match->board = NULL;
}
