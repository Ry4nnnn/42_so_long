#include "so_long.h"

int	exit_game(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}

t_data	create_window(t_data *data, char *name)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map.length * 32, data->map.height * 32 + 32, name);
	mlx_hook(data->win_ptr, 17, 0, exit_game, data);
	return (*data);
}

void	moves_counter(t_data *data)
{
	int i = 0;
	while (i < data->map.length * 32)
	{
		int j = data->map.height * 32;
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, i++, data->map.height * 32, 0x000000);
		while (j < data->map.height * 32 + 32)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, j++, 0x000000);
		}
	}
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, data->map.height * 32, 0xFFFFFF, "Moves:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 65, data->map.height * 32, 0x00FF00, ft_itoa(data->moves));
}
