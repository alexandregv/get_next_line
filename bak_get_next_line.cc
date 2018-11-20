/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:51:58 by aguiot--          #+#    #+#             */
/*   Updated: 2018/11/26 19:09:14 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "libft/libft.h"
#include "get_next_line.h"

static t_file		*get_fd_file(t_file **files, int fd)
{
	t_file			*file;

	file = *files;
	while (file)
	{
		if ((int)file->fd == fd)
			return (file);
		file = file->next;
	}
	file = (t_file*)malloc(sizeof(t_file));
	file->remainder = ft_strnew(1);
	file->fd = fd;
	file->tmp = ft_strnew(1);
	file->next = *files;
	*files = file;
	return (file);
}

int					get_next_line(const int fd, char **line)
{
	static t_file	*files;
	t_file			*file;
	char			buff[BUFF_SIZE + 1];
	int				ret;
	size_t			i;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	file = get_fd_file(&files, fd);
	if ((*line = ft_strnew(1)) == NULL)
		return (-1);
	free(*line);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		file->remainder = ft_strjoin(file->remainder, buff);
		if (ret == 1)
			ft_memdel((void**)&file->tmp);
		if (ft_strchr(file->remainder, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && ft_strlen(file->remainder) == 0)
		return (0);
	i = ft_str_copy_to(line, file->remainder, '\n');
	if (i < ft_strlen(file->remainder))
	{
		file->tmp = file->remainder;
		file->remainder += (i + 1);
	}
	else
		ft_strclr(file->remainder);
	return (1);
}
