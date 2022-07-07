/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:45:55 by welim             #+#    #+#             */
/*   Updated: 2022/07/07 19:06:42 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*fill_column(char *buffer)
{
	char	*temp;
	char	*newline;
	char	*res;

	newline = "\n";
	temp = ft_strdup(buffer);
	res = ft_strtrim(temp, newline);
	free (temp);
	return (res);
}

static void	init_map(char *argv, t_data *data)
{
	int		rows;
	char	*buffer;
	int		fd;
	int		i;

	i = 0;
	rows = counter_line(argv);
	fd = open(argv, O_RDONLY);
	data->map.map = malloc(sizeof(char *) * (rows + 1));
	while (rows > i)
	{
		buffer = get_next_line(fd);
		data->map.map[i] = fill_column(buffer);
		free (buffer);
		i++;
	}
	data->map.map[i] = 0;
	close (fd);
}

static void	init_map_size(char *argv, t_data *data)
{
	int		fd;
	char	*buffer;
	char	*temp;

	data->map.h = counter_line(argv);
	fd = open(argv, O_RDONLY);
	buffer = get_next_line(fd);
	close (fd);
	temp = fill_column(buffer);
	free (buffer);
	data->map.l = ft_strlen(temp);
	free(temp);
}

void	create_map(char *argv, t_data *data)
{
	init_map(argv, data);
	init_map_size(argv, data);
}
