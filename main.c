#include "so_long.h"

int	exit_game(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}

static	int	key_input(int key, t_data *data)
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
	{
		ft_putstr_fd("Key pressed: ESC\n", 1);
		exit_game(data);
	}
	return (0);
}

static int init_image(t_data *data)
{
	data->player.path = "./image/player.xpm";
	data->wall.path = "./image/wall.xpm";
	data->floor.path = "./image/floor.xpm";
	return(0);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	void		*play;
	// int			fd;
	if (argc == 2)
	{
		data = malloc(sizeof(t_data));
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, 640, 320, "Ryan's so_long");
		int w = 32;
		int h = 32;

		if (check_mapfile_name(argv[1]))//check filename
		{
			check_map(argv[1]);//check for wall
			init_image(data);
			play = mlx_xpm_file_to_image(data->mlx_ptr, data->player.path, &w, &h);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, play, 32, 64);
			mlx_hook(data->win_ptr, 17, 1L << 17, exit_game, data);
			mlx_key_hook(data->win_ptr, key_input, data);
			mlx_loop(data->mlx_ptr);
		}
		ft_putstr_fd("Filename must end with .ber", 1);
	}
	else
		ft_putstr_fd("Usage: [Programe Name] [Map.ber]", 1);
		return (0);
}