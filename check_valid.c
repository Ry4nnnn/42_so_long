/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:41:50 by welim             #+#    #+#             */
/*   Updated: 2022/07/07 18:11:04 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static void	check_mapfile_name(char *argv)
{
	int		file_len;
	char	*res;
	int		valid;

	file_len = ft_strlen(argv);
	if (file_len >= 5)
	{
		res = ft_strnstr(argv, ".ber", file_len);
		if (res != NULL)
		{
			valid = ft_strncmp(res, ".ber", 4);
			if (valid == 0 && ft_strlen(res) == 4)
				return ;
		}
	}
	ft_putendl_fd("Wrong file name", 2);
	exit (1);
}

static void	check_map_size(char *argv)
{
	int		fd;
	int		fd_len;

	fd_len = counter_line(argv);
	fd = open(argv, O_RDONLY);
	check_top_line(fd);
	while (fd_len > 2)
	{
		check_mid_line(fd);
		fd_len--;
	}
	check_bot_line(fd);
	close (fd);
	if (!(check_buffer_len(argv)))
	{
		ft_putendl_fd("Invalid map", 2);
		exit (1);
	}
}

static void	check_rules(char *argv, t_data *data)
{
	int		fd;
	int		count;
	char	*buffer;

	count = counter_line(argv);
	fd = open(argv, O_RDONLY);
	while (count)
	{
		buffer = get_next_line(fd);
		populate_objects(buffer, data);
		free (buffer);
		count--;
	}
	close (fd);
	check_objects(data);
	return ;
}

void	check_valid(char *argv, t_data *data)
{
	check_mapfile_name(argv);
	check_map_size(argv);
	check_rules(argv, data);
	return ;
}
