#include "so_long.h"

int	check_top_bot_line(int fd)
{
	int		buff_len;
	int		i;
	char	*buffer;

	i = 0;
	buffer = get_next_line(fd);
	buff_len = ft_strlen(buffer);
	while (buff_len > i)
	{
		if (buffer[i] != '1')
		{
			free (buffer);
			return (0);
		}
		i++;
	}
	free (buffer);
	return (1);
}

int	check_mid_line(int fd)
{
	char	*buffer;
	int		buff_len;

	buffer = get_next_line(fd);
	buff_len = ft_strlen(buffer);
	if (buffer[1] != '1' && buffer[buff_len] != '1')
	{
		free (buffer);
		return (0);
	}
	free (buffer);
	return (1);
}

//to check if my map if a rectangle
int	check_buffer_len(char *argv)
{
	char	c;
	int		fd;
	int		prev;
	int		cur;

	fd = open(argv, O_RDONLY);
	prev = 0;
	while (read(fd, &c, 1) && c != '\n')
		prev++;
	cur = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
		{
			if (cur != prev)
				return (0);
			prev = cur;
			cur = 0;
		}
		else
			cur++;
	}
	close (fd);
	return (cur == prev);
}

void	populate_objects(char *buffer, t_data *data)
{
	int		i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == 'P')
			data->image.player.count += 1;
		else if (buffer[i] == 'E')
			data->image.exit.count += 1;
		else if (buffer[i] == 'C')
			data->image.coin.count += 1;
		else if (buffer[i] == 'K')
			data->image.killer.count += 1;
		i++;
	}
}

void	check_objects(t_data *data)
{
	if (data->image.player.count != 1)
	{
		ft_putendl_fd("Must only contain one Player[P]", 2);
		exit (1);
	}
	else if (data->image.exit.count < 1)
	{
		ft_putendl_fd("Must atleast contain one Exit[E]", 2);
		exit (1);
	}
	else if (data->image.coin.count < 1)
	{
		ft_putendl_fd("Must atleast contain one Coin[C]", 2);
		exit (1);
	}
	else if (data->image.killer.count > 1)
	{
		ft_putendl_fd("Must only contain one Killer[K]", 2);
		exit (1);
	}
	return ;
}
