#include "so_long.h"

int	check_top_bot_line(char *buffer)
{
	int buff_len;
	int i;

	i = 0;
	buff_len = ft_strlen(buffer);
	while (buff_len)//10
	{
		if (buffer[i] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
	free (buffer);
}

int	check_mid_line(char *buffer)
{
	int buff_len;

	buff_len = ft_strlen(buffer);
	if (buffer[1] != '1' && buffer[buff_len] != '1')
	{
		return (0);
	}
	return (1);
	free (buffer);
}

int	counter_line(char *argv)
{
	int counter;
	int fd;
	char *buffer;

	counter = 1;
	fd  = open(argv, O_RDONLY);
	buffer = get_next_line(fd);
	while (buffer)
	{
		free (buffer);
		counter++;
	}
	close (fd);
	return (counter);
}

int check_buffer_len(char *argv)
{
	size_t i;
	int fd_len;
	int fd;
	char *buffer;

	fd = open(argv, O_RDONLY);
	buffer = get_next_line(fd);
	i = ft_strlen(buffer);
	fd_len = counter_line(argv);
	while (fd_len)
	{
		if (i != ft_strlen(buffer))
		{
			free (buffer);
			return (0);
		}
		fd_len--;
	}
	return (1);
}

int check_map(char *argv)
{
	int	fd;
	char *buffer;
	int fd_len;
	
	fd_len = counter_line(argv);//return number of lines in .ber
	fd  = open(argv, O_RDONLY);
	buffer = get_next_line(fd);
	check_top_bot_line(buffer);
	while (fd_len > 1)
	{
		buffer = get_next_line(fd);
		check_mid_line(buffer);
		fd_len--;
	}
	buffer = get_next_line(fd);
	check_top_bot_line(buffer);
	close (fd);
	check_buffer_len(argv);
	return (1);
}
