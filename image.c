#include "so_long.h"

void	mlx_create_window(t_data *data)
{
	int w;
	void *play;
	// void *killer;

	// data->mlx_ptr = mlx_init();
	// data->win_ptr = mlx_new_window(data->mlx_ptr, data->map.length * 32, data->map.height * 32, "so_long");
	play = mlx_xpm_file_to_image(data->mlx_ptr, data->image.player.one, &w, &w);
	// killer = mlx_xpm_file_to_image(data->mlx_ptr, data->image.killer.one, &w, &w);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, play, data->image.player.y * 32, data->image.player.x * 32);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, killer, data->image.killer.y * 32, data->image.killer.x * 32);
	//
	mlx_hook(data->win_ptr, 17, 1L << 17, exit_game, data);
	mlx_key_hook(data->win_ptr, key_input, data);
	mlx_loop(data->mlx_ptr);
}