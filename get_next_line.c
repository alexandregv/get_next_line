/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:51:58 by aguiot--          #+#    #+#             */
/*   Updated: 2018/11/27 19:21:25 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			check_errors(int fd, char **line, char *buff)
{
	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0
		|| ((*line = ft_strnew(0)) == NULL))
		return (-1);
	free(*line);
	return (0);
}

static t_list		*get_fd_file(t_list **files, int fd)
{
	t_list			*file;

	file = *files;
	while (file)
	{
		if ((int)file->content_size == fd)
			return (file);
		file = file->next;
	}
	file = ft_lstnew("", fd);
	free(file->content);
	file->content = "";
	ft_lstadd(files, file);
	return (file);
}

static void			read_line(int *ret, int fd, char *buff, t_list **file)
{
	char			*tmp;

	while ((*ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[*ret] = '\0';
		tmp = (*file)->content;
		(*file)->content = ft_strjoin((*file)->content, buff);
		if (!buff)
			free(tmp);
		if (ft_strchr((*file)->content, '\n'))
			break ;
	}
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*files;
	t_list			*file;
	size_t			offset;
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (check_errors(fd, line, buff) == -1)
		return (-1);
	file = get_fd_file(&files, fd);
	read_line(&ret, fd, buff, &file);
	if (ret < BUFF_SIZE && ft_strlen(file->content) == 0)
		return (0);
	offset = ft_str_copy_to(line, file->content, '\n');
	if (ft_strlen(file->content) > offset++)
		file->content += offset;
	else
		ft_strclr(file->content);
	return (1);
}
