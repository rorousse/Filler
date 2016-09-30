/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 10:59:06 by rorousse          #+#    #+#             */
/*   Updated: 2016/09/29 10:59:07 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "../libft/libft.h"

int		algo_naif(t_game *partie)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (i < partie->hauteur)
	{
		y = 0;
		while (y < partie->hauteur)
		{
			if (check_pose(*partie, i, y))
			{
				ft_putnbr(i);
				ft_putchar(' ');
				ft_putnbr(y);
				ft_putchar('\n');
				return (1);
			}
			y++;
		}
		i++;
	}
	return (0);
}