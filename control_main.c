/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:43:44 by welim             #+#    #+#             */
/*   Updated: 2022/07/06 19:44:00 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_control(int key, t_data *data)
{
	if (key == 13)
	{
		move_pw(data);
		move_pw2(data);
	}
	else if (key == 0)
	{
		move_pa(data);
		move_pa2(data);
	}
	else if (key == 1)
	{
		move_ps(data);
		move_ps2(data);
	}
	else if (key == 2)
	{
		move_pd(data);
		move_pd2(data);
	}
}

static void	killer_control(int key, t_data *data)
{
	if (key == 126)
		move_kw(data);
	else if (key == 123)
		move_ka(data);
	else if (key == 125)
		move_ks(data);
	else if (key == 124)
		move_kd(data);
}

int	key_input(int key, t_data *data)
{
	if (data->frame > 0)
	{
		player_control(key, data);
		killer_control(key, data);
		if (key == 53)
			exit_game(data);
		moves_counter(data);
	}
	data->frame = 0;
	return (0);
}
