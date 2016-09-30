/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 17:25:33 by rorousse          #+#    #+#             */
/*   Updated: 2016/09/28 17:25:34 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"
#include "../libft/libft.h"

void	read_piece(t_game *partie)
{
	char	*line;
	int		i;

	i = 6;
	get_next_line(0, &line);
	(partie->piece).hauteur = ft_atoi(&(line[i]));
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	i++;
	(partie->piece).largeur = ft_atoi(&(line[i]));
	(partie->piece).forme = (char**)malloc(sizeof(char*) * ((partie->piece).hauteur + 1));
	i = 0;
	while (i < (partie->piece).hauteur)
	{
		get_next_line(0, &((partie->piece).forme[i]));
		i++;
	}
	(partie->piece).forme[i] = NULL;
}

int		check_pose(t_game partie, int y, int x)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < partie.piece.hauteur)
	{
		j = 0;
		while (j < partie.piece.largeur)
		{
			if (partie.piece.forme[i][j] != '.')
			{
				if (x + i >= partie.hauteur || y + j >= partie.largeur)
					return (0);
				if (partie.plateau[x + i][y + j] == partie.player || partie.plateau[x + i][y + j] == partie.player - 32)
					count++;
			}
		}
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}