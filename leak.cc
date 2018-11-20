#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "libft/libft.h"
#include "get_next_line.h"

int			main(int argc, char **argv)
{
	int		fd;
	int		status;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("########## Couldn't open file ##########");
		return (1);
	}
	ft_putendl("----------[ File opened. Starting reading... ]----------");
	
	status = get_next_line(fd, &line);
	free(line);

	if (close(fd) == -1)
	{
		ft_putendl("########## Couldn't close file ##########");
		return (1);
	}
	ft_putendl("--------------------[ File closed ]---------------------");
	
	sleep(4);
	(void)argc;
	return (0);
}
