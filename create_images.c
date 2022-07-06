/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:45:23 by welim             #+#    #+#             */
/*   Updated: 2022/07/06 20:15:43 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_data	*converter(t_data *data, char *path)
{
	t_data	*img;
	int		n;

	img = mlx_xpm_file_to_image(data->m_p, path, &n, &n);
	return (img);
}

static void	create_player(t_data *data)
{
	data->img.ply.one = converter(data, "./image/player1.xpm");
	data->img.ply.two = converter(data, "./image/player2.xpm");
	data->img.ply.three = converter(data, "./image/player3.xpm");
}

static void	create_killer(t_data *data)
{
	data->img.killer.one = converter(data, "./image/killer1.xpm");
	data->img.killer.two = converter(data, "./image/killer2.xpm");
	data->img.killer.three = converter(data, "./image/killer3.xpm");
}

static void	create_objects(t_data *data)
{
	data->img.wall.one = converter(data, "./image/wall.xpm");
	data->img.flr.one = converter(data, "./image/floor.xpm");
	data->img.coin.one = converter(data, "./image/coin.xpm");
	data->img.exit.one = converter(data, "./image/exit.xpm");
}

void	create_images(t_data *data)
{
	create_player(data);
	create_killer(data);
	create_objects(data);
}
