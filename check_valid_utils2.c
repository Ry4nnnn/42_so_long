/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:06:53 by welim             #+#    #+#             */
/*   Updated: 2022/07/07 19:06:54 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	populate_objects(char *buffer, t_data *data)
{
	int		i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == 'P')
			data->img.ply.count += 1;
		else if (buffer[i] == 'E')
			data->img.exit.count += 1;
		else if (buffer[i] == 'C')
			data->img.coin.count += 1;
		else if (buffer[i] == 'K')
			data->img.killer.count += 1;
		i++;
	}
}

void	check_objects(t_data *data)
{
	if (data->img.ply.count != 1)
	{
		ft_putendl_fd("Must only contain one Player[P]", 2);
		exit (1);
	}
	else if (data->img.exit.count < 1)
	{
		ft_putendl_fd("Must atleast contain one Exit[E]", 2);
		exit (1);
	}
	else if (data->img.coin.count < 1)
	{
		ft_putendl_fd("Must atleast contain one Coin[C]", 2);
		exit (1);
	}
	else if (data->img.killer.count > 1)
	{
		ft_putendl_fd("Must only contain one Killer[K]", 2);
		exit (1);
	}
	return ;
}
