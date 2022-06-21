// #include <unistd.h>
// #include "mlx.h"
// #include "libft.h"
#include "so_long.h"

int	exit_game(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}

static	int	deal_key(int key, t_data *data)
{
	if (key == 13)
		ft_putstr_fd("Key pressed: W\n", 1);
	else if (key == 0)
		ft_putstr_fd("Key pressed: A\n", 1);
	else if (key == 1)
		ft_putstr_fd("Key pressed: S\n", 1);
	else if (key == 2)
		ft_putstr_fd("Key pressed: D\n", 1);
	else if (key == 53)
		exit_game(data);
	return (0);
}

int init_player(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	data->player->path = "player.xpm";
	return(0);
}

int init_wall(t_data *data)
{
	data->wall = malloc(sizeof(t_wall));
	data->wall->path = "wall.xpm";
	return (0);
}

int	main(void)
{
	t_data *data;
	data = malloc(sizeof(t_data));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 600, 300, "test_so_long");
	void *play;
	int w = 32;
	int h = 32;

	init_player(data);
	play = mlx_xpm_file_to_image(data->mlx_ptr, data->player->path, &w, &h);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, play, 2, 2);
	// mlx_hook(data->win_ptr, 17, 1L << 17, exit_game, data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}