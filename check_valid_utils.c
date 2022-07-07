/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:42:49 by welim             #+#    #+#             */
/*   Updated: 2022/07/07 17:31:50 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_top_line(int fd)
{
	int		buff_len;
	int		i;
	char	*buffer;

	i = 0;
	buffer = get_next_line(fd);
	buff_len = ft_strlen(buffer) - 1;
	while (buff_len > i)
	{
		if (buffer[i] != '1')
		{
			free (buffer);
			ft_putendl_fd("Top must be covered by wall", 2);
			exit (0);
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
	if (buffer[0] != '1' || buffer[buff_len - 2] != '1')
	{
		free (buffer);
		ft_putendl_fd("Side must be covered by wall", 2);
		exit (0);
	}
	buff_len = 0;
	free (buffer);
	return (1);
}

int	check_bot_line(int fd)
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
			ft_putendl_fd("Bottom must be covered by wall", 2);
			exit (0);
		}
		i++;
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
