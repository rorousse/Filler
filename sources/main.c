/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:15:11 by rorousse          #+#    #+#             */
/*   Updated: 2016/09/26 18:01:50 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	char *str;
	int	fd;

	fd = open("../test.txt", O_WRONLY);
	while (get_next_line(0, &str))
	{
		ft_putendl_fd(str, fd);
	}
	close(fd);
	return (0);
}
