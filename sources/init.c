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

// pour les test
#include <fcntl.h>
#include <unistd.h>


void	write_test(char *str)
{
	int	fd;

	fd = open("../test.txt", O_WRONLY);
	ft_putendl_fd(str, fd);
	close(fd);
}

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

void	init_game(t_game *partie)
{
	char	*line;

	get_next_line(0, &line);
	if (line[10] == '1')
	{
		partie->player = 'o';
		partie->adv = 'x';
	}
	else
	{
		partie->player = 'x';
		partie->adv = 'o';
	}
	partie->plateau = NULL;
}