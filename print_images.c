#include "so_long.h"

static void player_anime(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.floor.one, y * 32, x * 32);
	if (data->frame < 10 || (data->frame >= 30 && data->frame < 40))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.player.one, y * 32, x * 32);
	else if ((data->frame >= 10 && data->frame < 20) || (data->frame >= 40 && data->frame < 50))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.player.two, y * 32, x * 32);
	else if ((data->frame >= 20 && data->frame < 30) || (data->frame >= 50 && data->frame < 60))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.player.three, y * 32, x * 32);
}

static void killer_anime(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.floor.one, y * 32, x * 32);
	if (data->frame < 20)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.killer.one, y * 32, x * 32);
	else if (data->frame < 40)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.killer.two, y * 32, x * 32);
	else if (data->frame < 60)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.killer.three, y * 32, x * 32);

}

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
				player_anime(data, x, y);
			}
			if (data->map.map[x][y] == 'K')
			{
				data->image.k_x = x;
				data->image.k_y = y;
				killer_anime(data, x, y);
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
	data->frame++;
	if (data->frame > 49)
		data->frame = 0;
	return (0);
}
