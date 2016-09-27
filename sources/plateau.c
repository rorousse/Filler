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

void	free_plateau(char **plateau)
{
	int		i;

	i = 0;
	while (plateau[i] != NULL)
	{
		free(plateau[i]);
		i++;
	}
	free(plateau);
}

char	**init_plateau(int x, int y)
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

void	lecture_plateau(t_game partie)
{
	char	*line;
	int		dec;
	int		i;
	int		j;
	int		ret;

	j = 0;
	i = 0;
	dec = 0;
	get_next_line(1, &line);
	ret = get_next_line(1, &line);
	while (line[dec] != ' ')
		dec++;
	dec++;
	while (ret > 0)
	{
		j = 0;
		while (line[j + dec])
		{
			partie.plateau[i][j] = line[j + dec];
			j++;
		}
		i++;
		ret = get_next_line(1, &line);
	}
}

