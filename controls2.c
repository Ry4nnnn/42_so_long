#include "so_long.h"

void	move_w2(t_data *data)
{
	char **map;

	map = data->map.map;
	if (map[data->image.p_x - 1][data->image.p_y] == 'C')
	{
		map[data->image.p_x][data->image.p_y] = '0';
		map[data->image.p_x - 1][data->image.p_y] = 'P';
		data->image.coin.count--;
		data->moves++;
	}
	else if (map[data->image.p_x - 1][data->image.p_y] == 'E')
	{
		if (data->image.coin.count == 0)
		{
			ft_putstr_fd("YOU WON!", 1);
			exit_game(data);
		}
	}
	return ;
}

void	move_s2(t_data *data)
{
	char **map;

	map = data->map.map;
	if (map[data->image.p_x + 1][data->image.p_y] == 'C')
	{
		map[data->image.p_x][data->image.p_y] = '0';
		map[data->image.p_x + 1][data->image.p_y] = 'P';
		data->image.coin.count--;
		data->moves++;
	}
	else if (map[data->image.p_x + 1][data->image.p_y] == 'E')
	{
		if (data->image.coin.count == 0)
		{
			ft_putstr_fd("YOU WON!", 1);
			exit_game(data);
		}
	}
	return ;
}

void	move_d2(t_data *data)
{
	char **map;

	map = data->map.map;
	if (map[data->image.p_x][data->image.p_y + 1] == 'C')
	{
		map[data->image.p_x][data->image.p_y] = '0';
		map[data->image.p_x][data->image.p_y + 1] = 'P';
		data->image.coin.count--;
		data->moves++;
	}
	else if (map[data->image.p_x][data->image.p_y + 1] == 'E')
	{
		if (data->image.coin.count == 0)
		{
			ft_putstr_fd("YOU WON!", 1);
			exit_game(data);
		}
	}
	return ;
}

void	move_a2(t_data *data)
{
	char **map;

	map = data->map.map;
	if (map[data->image.p_x][data->image.p_y - 1] == 'C')
	{
		map[data->image.p_x][data->image.p_y] = '0';
		map[data->image.p_x][data->image.p_y - 1] = 'P';
		data->image.coin.count--;
		data->moves++;
	}
	else if (map[data->image.p_x][data->image.p_y - 1] == 'E')
	{
		if (data->image.coin.count == 0)
		{
			ft_putstr_fd("YOU WON!", 1);
			exit_game(data);
		}
	}
	return ;
}
