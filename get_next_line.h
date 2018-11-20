/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiot-- <aguiot--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:54:37 by aguiot--          #+#    #+#             */
/*   Updated: 2018/11/27 19:14:35 by aguiot--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 4000

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct		s_file
{
	char			*remainder;
	char			*tmp;
	size_t			fd;
	struct s_file	*next;
}					t_file;

int					get_next_line(const int fd, char **line);

#endif
