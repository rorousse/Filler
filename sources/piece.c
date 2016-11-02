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

static int	ft_matching(t_game match, int *count, int x, int y)
{
	if (y >= match.h || x >= match.l
	|| match.board[y][x] == match.adv
	|| match.board[y][x] == match.adv - 32)
		return (0);
	if (match.board[y][x] == match.player
	|| match.board[y][x] == match.player - 32)
		(*count)++;
	return (1);
}

static int	check_out(t_game match, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	while (i < match.piece.h)
	{
		j = 0;
		while (j < match.piece.l)
		{
			if (match.piece.shape[i][j] == '*' && ((x + j < 0) || (y + i < 0)))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void		read_piece(t_game *match)
{
	char	*line;
	int		i;

	i = 6;
	get_next_line(0, &line);
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

int			check_pose(t_game match, int y, int x)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	if (!check_out(match, y, x))
		return (0);
	while (i < match.piece.h)
	{
		j = 0;
		while (j < match.piece.l)
		{
			if (match.piece.shape[i][j] == '*' && (y + i >= 0) && (x + j >= 0))
				if (!ft_matching(match, &count, x + j, y + i))
					return (0);
			j++;
		}
		i++;
	}
	return (count == 1) ? 1 : 0;
}
