/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 16:50:38 by rorousse          #+#    #+#             */
/*   Updated: 2016/10/30 16:50:40 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	write_test(char *str)
{
	int	fd;

	fd = open("../test.txt", O_WRONLY | O_APPEND | O_CREAT);
	ft_putendl_fd(str, fd);
	close(fd);
}

void	write_plateau(char **plateau)
{
	int fd;
	int	i;

	i = 0;
	fd = open("plateau.txt", O_WRONLY | O_APPEND | O_CREAT);
	while (plateau[i] != NULL)
	{
		ft_putendl_fd(plateau[i], fd);
		i++;
	}
	close(fd);
}