#include "so_long.h"

void	move_kw(t_data *data)
{
	char **map;

	map = data->map.map;
	if (map[data->image.k_x - 1][data->image.k_y] == '1')
		return ;
	else if (map[data->image.k_x - 1][data->image.k_y] == 'C')
		return ;
	else if (map[data->image.k_x - 1][data->image.k_y] == 'E')
		return ;
	else if (map[data->image.k_x - 1][data->image.k_y] == '0')
	{
		map[data->image.k_x][data->image.k_y] = '0';
		map[data->image.k_x - 1][data->image.k_y] = 'K';
	}
	else if (map[data->image.k_x - 1][data->image.k_y] == 'P')
	{
		ft_putstr_fd("Opponent Won", 1);
		exit_game(data);
	}
	return ;
}

void	move_ks(t_data *data)
{
	char **map;

	map = data->map.map;
	if (map[data->image.k_x + 1][data->image.k_y] == '1')
		return ;
	else if (map[data->image.k_x + 1][data->image.k_y] == '0')
	{
		map[data->image.k_x][data->image.k_y] = '0';
		map[data->image.k_x + 1][data->image.k_y] = 'K';
	}
	else if (map[data->image.k_x + 1][data->image.k_y] == 'P')
	{
		ft_putstr_fd("Opponent Won", 1);
		exit_game(data);
	}
	if (map[data->image.k_x + 1][data->image.k_y] == 'C')
		return ;
	else if (map[data->image.k_x + 1][data->image.k_y] == 'E')
		return ;
	return ;
}

void	move_kd(t_data *data)
{
	char **map;

	map = data->map.map;
	if (map[data->image.k_x][data->image.k_y + 1] == '1')
		return ;
	else if (map[data->image.k_x][data->image.k_y + 1] == '0')
	{
		map[data->image.k_x][data->image.k_y] = '0';
		map[data->image.k_x][data->image.k_y + 1] = 'K';
	}
	else if (map[data->image.k_x][data->image.k_y + 1] == 'P')
	{
		ft_putstr_fd("Opponent Won", 1);
		exit_game(data);
	}
	if (map[data->image.k_x][data->image.k_y + 1] == 'C')
		return ;
	else if (map[data->image.k_x][data->image.k_y + 1] == 'E')
		return ;
	return ;
}

void	move_ka(t_data *data)
{
	char **map;

	map = data->map.map;
	if (map[data->image.k_x][data->image.k_y - 1] == '1')
		return ;
	else if (map[data->image.k_x][data->image.k_y - 1] == '0')
	{
		map[data->image.k_x][data->image.k_y] = '0';
		map[data->image.k_x][data->image.k_y - 1] = 'K';
	}
	else if (map[data->image.k_x][data->image.k_y - 1] == 'P')
	{
		ft_putstr_fd("Opponent Won", 1);
		exit_game(data);
	}
	else if (map[data->image.k_x][data->image.k_y - 1] == 'C')
		return ;
	else if (map[data->image.k_x][data->image.k_y - 1] == 'E')
		return ;
	return ;
}
