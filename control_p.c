#include "so_long.h"

void	move_pw(t_data *data)
{
	char **map;

	map = data->map.map;
	if (map[data->image.p_x - 1][data->image.p_y] == '1')
		return ;
	else if (map[data->image.p_x - 1][data->image.p_y] == '0')
	{
		map[data->image.p_x][data->image.p_y] = '0';
		map[data->image.p_x - 1][data->image.p_y] = 'P';
		data->moves++;
	}
	else if (map[data->image.p_x - 1][data->image.p_y] == 'K')
	{
		ft_putstr_fd("You have been kiled, Game Over", 1);
		exit_game(data);
	}
	return ;
}

void	move_ps(t_data *data)
{
	char **map;

	map = data->map.map;
	if (map[data->image.p_x + 1][data->image.p_y] == '1')
		return ;
	else if (map[data->image.p_x + 1][data->image.p_y] == '0')
	{
		map[data->image.p_x][data->image.p_y] = '0';
		map[data->image.p_x + 1][data->image.p_y] = 'P';
		data->moves++;
	}
	else if (map[data->image.p_x + 1][data->image.p_y] == 'K')
	{
		ft_putstr_fd("You have been kiled, Game Over", 1);
		exit_game(data);
	}
	return ;
}

void	move_pd(t_data *data)
{
	char **map;

	map = data->map.map;
	if (map[data->image.p_x][data->image.p_y + 1] == '1')
		return ;
	else if (map[data->image.p_x][data->image.p_y + 1] == '0')
	{
		map[data->image.p_x][data->image.p_y] = '0';
		map[data->image.p_x][data->image.p_y + 1] = 'P';
		data->moves++;
	}
	else if (map[data->image.p_x][data->image.p_y + 1] == 'K')
	{
		ft_putstr_fd("You have been kiled, Game Over", 1);
		exit_game(data);
	}
	return ;
}

void	move_pa(t_data *data)
{
	char **map;

	map = data->map.map;
	if (map[data->image.p_x][data->image.p_y - 1] == '1')
		return ;
	else if (map[data->image.p_x][data->image.p_y - 1] == '0')
	{
		map[data->image.p_x][data->image.p_y] = '0';
		map[data->image.p_x][data->image.p_y - 1] = 'P';
		data->moves++;
	}
	else if (map[data->image.p_x][data->image.p_y - 1] == 'K')
	{
		ft_putstr_fd("You have been kiled, Game Over", 1);
		exit_game(data);
	}
	return ;
}
