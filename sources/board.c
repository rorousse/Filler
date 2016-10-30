/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 17:04:47 by rorousse          #+#    #+#             */
/*   Updated: 2016/10/30 17:04:49 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"
#include "../libft/libft.h"

static void	free_line(char *line)
{
	if (line != NULL)
		free(line);
}

static void	read_board(t_game *match, int dec, char *line)
{
	int		i;
	int		j;

	i = 0;
	while (i < match->h)
	{
		j = 0;
		while (line[j + dec])
		{
			match->board[i][j] = line[j + dec];
			j++;
		}
		i++;
		if (i != match->h - 1)
		{
			free_line(line);
			get_next_line(0, &line);
		}
	}
	free_line(line);
}

char		**init_board(int x, int y)
{
	char	**board;
	int		i;
	int		j;

	i = 0;
	board = (char**)malloc((y + 1) * sizeof(char*));
	while (i < y)
	{
		board[i] = (char*)malloc((x + 1) * sizeof(char));
		i++;
	}
	board[i] = NULL;
	i = 0;
	j = 0;
	while (i < y)
	{
		while (j < x)
		{
			board[i][j] = '.';
			j++;
		}
		board[i][j] = '\0';
		i++;
	}
	return (board);
}

void		init_size(t_game *match)
{
	int		i;
	char	*line;

	i = 0;
	get_next_line(0, &line);
	while (line[i] && (line[i] < '0' || line[i] > '9'))
		i++;
	match->h = ft_atoi(&(line[i]));
	while (line[i] != ' ')
		i++;
	match->l = ft_atoi(&(line[i]));
	match->board = init_board(match->l, match->h);
	free_line(line);
}

void		read_game(t_game *match)
{
	char	*line;
	int		dec;
	int		ret;

	dec = 0;
	if (match->board != NULL)
	{
		ret = get_next_line(0, &line);
		free(line);
	}
	else
		init_size(match);
	ret = get_next_line(0, &line);
	free_line(line);
	ret = get_next_line(0, &line);
	while (line[dec] != ' ')
		dec++;
	dec++;
	read_board(match, dec, line);
}
