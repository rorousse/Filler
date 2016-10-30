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

// secure
static int	check_out(t_game match, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	while (i < match.piece.h && y + i < 0)
	{
		j = 0;
		while (j < match.piece.l && x + j < 0)
		{
			if (match.piece.shape[i][j] == '*')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	read_piece(t_game *match)
{
	char	*line;
	int		i;

	i = 6;
	get_next_line(0, &line);
	free(line);
	(match->piece).h = ft_atoi(&(line[i]));
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	i++;
	(match->piece).l = ft_atoi(&(line[i]));
	(match->piece).shape = (char**)malloc(sizeof(char*)
	* ((match->piece).h + 1));
	i = 0;
	while (i < (match->piece).h)
	{
		get_next_line(0, &((match->piece).shape[i]));
		i++;
	}
	(match->piece).shape[i] = NULL;
}

int		check_pose(t_game match, int y, int x)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	if (!check_out(match, y, x))
		return (0);
	write(2, "go\n", 3);
	while (++i < match.piece.h)
	{
		j = 0;
		while (j < match.piece.l)
		{
			if (match.piece.shape[i][j] == '*')
			{
				if (y + i >= match.h || x + j >= match.l
				|| match.board[y + i][x + j] == match.adv
				|| match.board[y + i][x + j] == match.adv - 32)
				{
					write(2, "ou\n", 3);
					return (0);
				}
				if (match.board[y + i][x + j] == match.player
				|| match.board[y + i][x + j] == match.player - 32)
					count++;
			}
			j++;
		}
	}
	write(2, "ou\n", 3);
	return (count == 1) ? 1 : 0;
}
