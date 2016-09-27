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

void	init_game()
{
	char	*line;
	t_game	partie;
	int		i;

	i = 0;
	get_next_line(0, &line);
	if (line[11] == '1')
	{
		partie.player = 'o';
		partie.adv = 'x';
	}
	else
	{
		partie.player = 'x';
		partie.adv = 'o';
	}
	get_next_line(0, &line);
	while (line[i] && (line[i] < '0' || line[i] > '9'))
		i++;
	partie.y = ft_atoi(&(line[i]));
	while (line[i] != ' ')
		i++;
	partie.x = ft_atoi(&(line[i]));
	partie.plateau = init_plateau(partie.x, partie.y);
}