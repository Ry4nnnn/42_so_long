/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:49:08 by welim             #+#    #+#             */
/*   Updated: 2022/07/06 20:15:14 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_data	*init_struct(t_data *data)
{
	data->img.coin.count = 0;
	data->img.ply.count = 0;
	data->img.exit.count = 0;
	data->img.killer.count = 0;
	data->map.h = 0;
	data->map.l = 0;
	data->img.p_x = 0;
	data->img.p_y = 0;
	data->img.k_x = 0;
	data->img.k_y = 0;
	data->moves = 0;
	return (data);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	char		*c;

	c = "Moves:";
	if (argc != 2)
	{
		ft_putstr_fd("Usage: [Programe Name] [Map.ber]", 1);
		exit(1);
	}
	data = malloc(sizeof(t_data));
	init_struct(data);
	check_valid(argv[1], data);
	create_map(argv[1], data);
	data->m_p = mlx_init();
	create_window(data, "so_long");
	create_images(data);
	print_image(data);
	mlx_loop_hook(data->m_p, &print_image, data);
	mlx_hook(data->w_p, 17, 1L << 17, exit_game, data);
	mlx_string_put(data->m_p, data->w_p, 0, data->map.h * 32, 0xFFFFFF, c);
	mlx_key_hook(data->w_p, key_input, data);
	mlx_loop(data->m_p);
	return (0);
}
