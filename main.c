/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:24:02 by aguiot--          #+#    #+#             */
/*   Updated: 2018/11/27 19:16:39 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "libft.h"
#include "get_next_line.h"

int			main(int argc, char **argv)
{
	int		fd;
	int		status;
	char	*line;

	fd = open(argv[1], O_RDWR);
	ft_putendl("----------[ File opened. Starting reading... ]----------");
	status = 0;
	while ((status = get_next_line(fd, &line)))
	{
		ft_putstr("#");
		ft_putnbr(status);
		ft_putstr(" [");
		ft_putstr(line);
		ft_putstr("]\n");
		free(line);
	}
	ft_putstr("#");
	ft_putnbr(status);
	ft_putchar('\n');
	close(fd);
	ft_putendl("--------------------[ File closed ]---------------------");
	(void)argc;
	return (0);
}
