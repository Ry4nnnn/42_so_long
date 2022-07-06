/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:41:38 by welim             #+#    #+#             */
/*   Updated: 2022/07/06 20:43:33 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_anime(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->m_p, data->w_p,
		data->img.flr.one, y * 32, x * 32);
	if (data->frame < 10 || (data->frame >= 30 && data->frame < 40))
		mlx_put_image_to_window(data->m_p, data->w_p,
			data->img.ply.one, y * 32, x * 32);
	else if (data->frame >= 10 && data->frame < 20)
		mlx_put_image_to_window(data->m_p, data->w_p,
			data->img.ply.two, y * 32, x * 32);
	else if (data->frame >= 40 && data->frame < 50)
		mlx_put_image_to_window(data->m_p, data->w_p,
			data->img.ply.two, y * 32, x * 32);
	else if (data->frame >= 20 && data->frame < 30)
		mlx_put_image_to_window(data->m_p, data->w_p,
			data->img.ply.three, y * 32, x * 32);
	else if (data->frame >= 50 && data->frame < 60)
		mlx_put_image_to_window(data->m_p, data->w_p,
			data->img.ply.three, y * 32, x * 32);
}

static void	killer_anime(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->m_p, data->w_p,
		data->img.flr.one, y * 32, x * 32);
	if (data->frame < 20)
		mlx_put_image_to_window(data->m_p, data->w_p,
			data->img.killer.one, y * 32, x * 32);
	else if (data->frame < 40)
		mlx_put_image_to_window(data->m_p, data->w_p,
			data->img.killer.two, y * 32, x * 32);
	else if (data->frame < 60)
		mlx_put_image_to_window(data->m_p, data->w_p,
			data->img.killer.three, y * 32, x * 32);
}

static void	check_obj_to_print(t_data *data, int x, int y)
{
	if (data->map.map[x][y] == 'K')
	{
		data->img.k_x = x;
		data->img.k_y = y;
		killer_anime(data, x, y);
	}
	if (data->map.map[x][y] == 'C')
	{
		mlx_put_image_to_window(data->m_p, data->w_p,
			data->img.flr.one, y * 32, x * 32);
		mlx_put_image_to_window(data->m_p, data->w_p,
			data->img.coin.one, y * 32, x * 32);
	}
	if (data->map.map[x][y] == 'P')
	{
		data->img.p_x = x;
		data->img.p_y = y;
		player_anime(data, x, y);
	}
}

static void	check_obj_to_print2(t_data *data, int x, int y)
{
	if (data->map.map[x][y] == '0')
		mlx_put_image_to_window(data->m_p, data->w_p,
			data->img.flr.one, y * 32, x * 32);
	if (data->map.map[x][y] == '1')
		mlx_put_image_to_window(data->m_p, data->w_p,
			data->img.wall.one, y * 32, x * 32);
	if (data->map.map[x][y] == 'E')
	{
		mlx_put_image_to_window(data->m_p, data->w_p,
			data->img.flr.one, y * 32, x * 32);
		mlx_put_image_to_window(data->m_p, data->w_p,
			data->img.exit.one, y * 32, x * 32);
	}
}

int	print_image(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	while (data->map.map[x] != 0)
	{
		y = 0;
		while (data->map.map[x][y] != 0)
		{
			check_obj_to_print(data, x, y);
			check_obj_to_print2(data, x, y);
			y++;
		}
		x++;
	}
	data->frame++;
	if (data->frame > 49)
		data->frame = 0;
	return (0);
}
