/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_p2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:44:59 by welim             #+#    #+#             */
/*   Updated: 2022/07/06 20:50:47 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_pw2(t_data *data)
{
	char		**map;

	map = data->map.map;
	if (map[data->img.p_x - 1][data->img.p_y] == 'C')
	{
		map[data->img.p_x][data->img.p_y] = '0';
		map[data->img.p_x - 1][data->img.p_y] = 'P';
		data->img.coin.count--;
		data->moves++;
	}
	else if (map[data->img.p_x - 1][data->img.p_y] == 'E')
	{
		if (data->img.coin.count == 0)
		{
			ft_putstr_fd("YOU WON!", 1);
			exit_game(data);
		}
	}
	return ;
}

void	move_ps2(t_data *data)
{
	char		**map;

	map = data->map.map;
	if (map[data->img.p_x + 1][data->img.p_y] == 'C')
	{
		map[data->img.p_x][data->img.p_y] = '0';
		map[data->img.p_x + 1][data->img.p_y] = 'P';
		data->img.coin.count--;
		data->moves++;
	}
	else if (map[data->img.p_x + 1][data->img.p_y] == 'E')
	{
		if (data->img.coin.count == 0)
		{
			ft_putstr_fd("YOU WON!", 1);
			exit_game(data);
		}
	}
	return ;
}

void	move_pd2(t_data *data)
{
	char		**map;

	map = data->map.map;
	if (map[data->img.p_x][data->img.p_y + 1] == 'C')
	{
		map[data->img.p_x][data->img.p_y] = '0';
		map[data->img.p_x][data->img.p_y + 1] = 'P';
		data->img.coin.count--;
		data->moves++;
	}
	else if (map[data->img.p_x][data->img.p_y + 1] == 'E')
	{
		if (data->img.coin.count == 0)
		{
			ft_putstr_fd("YOU WON!", 1);
			exit_game(data);
		}
	}
	return ;
}

void	move_pa2(t_data *data)
{
	char		**map;

	map = data->map.map;
	if (map[data->img.p_x][data->img.p_y - 1] == 'C')
	{
		map[data->img.p_x][data->img.p_y] = '0';
		map[data->img.p_x][data->img.p_y - 1] = 'P';
		data->img.coin.count--;
		data->moves++;
	}
	else if (map[data->img.p_x][data->img.p_y - 1] == 'E')
	{
		if (data->img.coin.count == 0)
		{
			ft_putstr_fd("YOU WON!", 1);
			exit_game(data);
		}
	}
	return ;
}
