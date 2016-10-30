/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plateau.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 13:11:41 by rorousse          #+#    #+#             */
/*   Updated: 2016/09/27 13:11:42 by rorousse         ###   ########.fr       */
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

static void	read_board(t_game *partie, int dec, char *line)
{
	int		i;
	int		j;

	i = 0;
	while (i < partie->h)
	{
		j = 0;
		while (line[j + dec])
		{
			partie->plateau[i][j] = line[j + dec];
			j++;
		}
		i++;
		if (i != partie->h - 1)
		{
			free_line(line);
			get_next_line(0, &line);
		}
	}
	free_line(line);
}

char		**init_plateau(int x, int y)
{
	char	**plateau;
	int		i;
	int		j;

	i = 0;
	plateau = (char**)malloc((y + 1) * sizeof(char*));
	while (i < y)
	{
		plateau[i] = (char*)malloc((x + 1) * sizeof(char));
		i++;
	}
	plateau[i] = NULL;
	i = 0;
	j = 0;
	while (i < y)
	{
		while (j < x)
		{
			plateau[i][j] = '.';
			j++;
		}
		plateau[i][j] = '\0';
		i++;
	}
	return (plateau);
}

void		init_size(t_game *partie)
{
	int		i;
	char	*line;

	i = 0;
	get_next_line(0, &line);
	while (line[i] && (line[i] < '0' || line[i] > '9'))
		i++;
	partie->h = ft_atoi(&(line[i]));
	while (line[i] != ' ')
		i++;
	partie->l = ft_atoi(&(line[i]));
	partie->plateau = init_plateau(partie->l, partie->h);
	free(line);
}

void		read_game(t_game *partie)
{
	char	*line;
	int		dec;
	int		ret;

	dec = 0;
	if (partie->plateau != NULL)
	{
		ret = get_next_line(0, &line);
		free(line);
	}
	else
		init_size(partie);
	ret = get_next_line(0, &line);
	free_line(line);
	ret = get_next_line(0, &line);
	while (line[dec] != ' ')
		dec++;
	dec++;
	read_board(partie, dec, line);
}
