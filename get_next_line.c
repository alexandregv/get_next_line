/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:51:58 by aguiot--          #+#    #+#             */
/*   Updated: 2018/11/27 19:21:25 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
	file->remainder = "";
	file->fd = fd;
	file->tmp = file->remainder;
	file->next = *files;
	*files = file;
	return (file);
}

static int			check_errors(int fd, char **line, char *buff)
{
	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0
		|| ((*line = ft_strnew(0)) == NULL))
		return (-1);
	return (0);
}

static void			read_line(int *ret, int fd, char *buff, t_file **file)
{
	char			*tmp;
	int				time;

	time = 1;
	while ((*ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[*ret] = '\0';
		tmp = (*file)->remainder;
		(*file)->remainder = ft_strjoin((*file)->remainder, buff);
		if (time > 1)
			free(tmp);
		++time;
		if (ft_strchr((*file)->remainder, '\n'))
			break ;
	}
}

int					get_next_line(const int fd, char **line)
{
	static t_file	*files;
	t_file			*file;
	char			buff[BUFF_SIZE + 1];
	int				ret;
	size_t			i;

	if (check_errors(fd, line, buff) == -1)
		return (-1);
	file = get_fd_file(&files, fd);
	free(*line);
	read_line(&ret, fd, buff, &file);
	if (ret < BUFF_SIZE && ft_strlen(file->remainder) == 0)
	{
		return (0);
	}
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
