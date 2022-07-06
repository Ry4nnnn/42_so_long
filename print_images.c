#include "so_long.h"

int	print_image(t_data *data)
{
	int x;
	int y;

	x = 0;
	while (data->map.map[x] != 0)
	{
		y = 0;
		while (data->map.map[x][y] != 0)
		{
			if (data->map.map[x][y] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.wall.one, y * 32, x * 32);
			if (data->map.map[x][y] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.floor.one, y * 32, x * 32);
			if (data->map.map[x][y] == 'P')
			{
				data->image.p_x = x;
				data->image.p_y = y;
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.floor.one, y * 32, x * 32);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.player.one, y * 32, x * 32);
			}
			if (data->map.map[x][y] == 'K')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.floor.one, y * 32, x * 32);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.killer.one, y * 32, x * 32);
			}
			if (data->map.map[x][y] == 'C')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.floor.one, y * 32, x * 32);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.coin.one, y * 32, x * 32);
			}
			if (data->map.map[x][y] == 'E')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.floor.one, y * 32, x * 32);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.exit.one, y * 32, x * 32);
			}
			y++;
		}
		x++;
	}
	// idk(data):
	return (0);
}
