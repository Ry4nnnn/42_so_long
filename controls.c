#include "so_long.h"

static void	move_w(t_data *data)
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

static void	move_s(t_data *data)
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

static void	move_d(t_data *data)
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

static void	move_a(t_data *data)
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

int	key_input(int key, t_data *data)
{
	if (key == 13)
	{
		move_w(data);
		move_w2(data);
	}
	else if (key == 0)
	{
		move_a(data);
		move_a2(data);
	}
	else if (key == 1)
	{
		move_s(data);
		move_s2(data);
	}
	else if (key == 2)
	{
		move_d(data);
		move_d2(data);
	}
	else if (key == 53)
		exit_game(data);
	moves_counter(data);
	return (0);
}