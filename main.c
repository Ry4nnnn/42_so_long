/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:49:08 by welim             #+#    #+#             */
/*   Updated: 2022/07/06 16:05:28 by welim            ###   ########.fr       */
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
	data->image.p_x = 0;
	data->image.p_y = 0;
	data->moves = 0;
	return (data);
}

int	main(int argc, char **argv)
{
	t_data		*data;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: [Programe Name] [Map.ber]", 1);
		exit(1);
	}
	data = malloc(sizeof(t_data));
	init_struct(data);
	check_valid(argv[1], data);
	create_map(argv[1], data);
	data->mlx_ptr = mlx_init();
	create_window(data, "so_long");
	create_images(data);
	print_image(data);
	mlx_loop_hook(data->mlx_ptr, &print_image, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, exit_game, data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, data->map.height * 32, 0xFFFFFF, "Moves:");
	mlx_key_hook(data->win_ptr, key_input, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
