#include "so_long.h"

int	exit_game(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}

t_data	create_window(t_data *data, char *name)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map.length * 32, data->map.height * 32, name);
	mlx_hook(data->win_ptr, 17, 0, exit_game, data);
	return (*data);
}
