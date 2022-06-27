/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:49:08 by welim             #+#    #+#             */
/*   Updated: 2022/06/27 22:04:07 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_data	*init_struct(t_data *data)
{
	data->image.coin.count = 0;
	data->image.player.count = 0;
	data->image.exit.count = 0;
	data->image.killer.count = 0;
	data->map.height = 0;
	data->map.length = 0;
	data->image.player.x = 0;
	data->image.player.y = 0;
	return (data);
}

int	exit_game(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}

int	key_input(int key, t_data *data)
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

static int	init_image_path(t_data *data)
{
	data->image.player.one = "./image/player.xpm";
	data->image.killer.one  = "/image/killer.xpm";
	data->image.wall = "./image/wall.xpm";
	data->image.floor = "./image/floor.xpm";
	return (0);
}

static void	init_obj_pos(t_data *data)
{
	int x;
	int y;
	int w;
	void *wall;

	x = 0;
	// printf ("%c\n", data->map.map[1][3]);
	while (data->map.map[x] != 0)
	{
		y = 0;
		while (data->map.map[x][y] != 0)
		{
			if (data->map.map[x][y] == '1')
			{
				wall = mlx_xpm_file_to_image(data->mlx_ptr, data->image.player.one, &w, &w);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, wall, y * 32, x * 32);
			}
			// if (data->map.map[x][y] == 'P')
			// {
			// 	data->image.player.x = x;
			// 	data->image.player.y = y;
			// }
			// if (data->map.map[x][y] == 'K')
			// {
			// 	data->image.killer.x = x;
			// 	data->image.killer.y = y;
			// }
			// if (data->map.map[x][y] == 'E')
			// {
				// data->image.player.x = x;
				// data->image.player.y = y;
			// }
			y++;
		}
		x++;
	}
	printf ("x = %d\n", data->image.player.x);
	printf ("y = %d\n", data->image.player.y);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	// void		*play; 
	// int			w;

	if (argc == 2)
	{
		data = malloc(sizeof(t_data));
		init_struct(data);
		check_valid(argv[1], data);
		create_map(argv[1], data);
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, data->map.length * 32, data->map.height * 32, "so_long");
		init_image_path(data);
		init_obj_pos(data);
		// mlx_create_window(data);
		// data->mlx_ptr = mlx_init();
		// data->win_ptr = mlx_new_window(data->mlx_ptr, data->map.length * 32, data->map.height * 32, "so_long");
		// play = mlx_xpm_file_to_image(data->mlx_ptr, data->image.player.one, &w, &w);
		// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, play, 32, 64);
		// mlx_hook(data->win_ptr, 17, 1L << 17, exit_game, data);
		// mlx_key_hook(data->win_ptr, key_input, data);
		// mlx_loop(data->mlx_ptr);
	}
	else
		ft_putstr_fd("Usage: [Programe Name] [Map.ber]", 1);
	return (0);
}
