/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:45:14 by welim             #+#    #+#             */
/*   Updated: 2022/06/23 22:45:14 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// static void	check_mapfile_name(char *argv)
// static void populate_objects(char *buffer, t_data *data)
// static void check_objects(t_data *data)
// static void check_rules(char *argv, t_data *data)
// void	check_error(char *argv, t_data *data)

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

static void	populate_objects(char *buffer, t_data *data)
{
	int		i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == 'P')
			data->player.count += 1;
		else if (buffer[i] == 'E')
			data->exit.count += 1;
		else if (buffer[i] == 'C')
			data->collect.count += 1;
		i++;
	}
}

static void	check_objects(t_data *data)
{
	if (data->player.count != 1)
	{
		ft_putendl_fd("Must only contain one [P]", 2);
		exit (1);
	}
	else if (data->exit.count < 1)
	{
		ft_putendl_fd("Must atleast contain one [E]", 2);
		exit (1);
	}
	else if (data->collect.count < 1)
	{
		ft_putendl_fd("Must atleast contain one [C]", 2);
		exit (1);
	}
	return ;
}

static void	check_rules(char *argv, t_data *data)
{
	int		fd;
	int		count;
	char	*buffer;

	fd = open(argv, O_RDONLY);
	count = counter_line(argv);
	while (count)
	{
		buffer = get_next_line(fd);
		populate_objects(buffer, data);
		count--;
	}
	check_objects(data);
	return ;
}

void	check_error(char *argv, t_data *data)
{
	check_mapfile_name(argv);
	check_map(argv);
	check_rules(argv, data);
	return ;
}
