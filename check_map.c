/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:45:25 by welim             #+#    #+#             */
/*   Updated: 2022/06/23 22:47:44 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// static int	check_top_bot_line(int fd)
// static int	check_mid_line(int fd)
// int	counter_line(char *argv)
// static int check_buffer_len(char *argv)
// void check_map(char *argv)

static int	check_top_bot_line(int fd)
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

static int	check_mid_line(int fd)
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

//to get the total lines of the map
int	counter_line(char *argv)
{
	int		counter;
	int		fd;
	char	*buffer;

	counter = 0;
	fd = open(argv, O_RDONLY);
	buffer = get_next_line(fd);
	while (buffer)
	{
		free (buffer);
		buffer = get_next_line(fd);
		counter++;
	}
	free (buffer);
	close (fd);
	return (counter);
}

//to check if my map if a rectangle
static int	check_buffer_len(char *argv)
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
	return (cur == prev);
}

void	check_map(char *argv)
{
	int		fd;
	int		fd_len;

	fd_len = counter_line(argv);
	fd = open(argv, O_RDONLY);
	check_top_bot_line(fd);
	while (fd_len > 2)
	{
		check_mid_line(fd);
		fd_len--;
	}
	check_top_bot_line(fd);
	close (fd);
	if (!(check_buffer_len(argv)))
	{
		ft_putendl_fd("Invalid map", 2);
		exit (1);
	}
	return ;
}
