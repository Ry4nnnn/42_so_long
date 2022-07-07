/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:46:52 by welim             #+#    #+#             */
/*   Updated: 2022/07/07 17:51:57 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_data *data)
{
	mlx_destroy_window(data->m_p, data->w_p);
	system("leaks so_long");
	exit(0);
	return (0);
}

t_data	create_window(t_data *data, char *name)
{
	int		l;
	int		h;

	l = data->map.l * 32;
	h = data->map.h * 32 + 32;
	data->w_p = mlx_new_window(data->m_p, l, h, name);
	mlx_hook(data->w_p, 17, 0, exit_game, data);
	return (*data);
}

void	moves_counter(t_data *data)
{
	int		i;
	char	*n;
	int		j;
	char	*k;

	i = 0;
	n = ft_itoa(data->moves);
	k = "Moves:";
	while (i < data->map.l * 32)
	{
		j = data->map.h * 32;
		mlx_pixel_put(data->m_p, data->w_p, i++, data->map.h * 32, 0x000000);
		while (j < data->map.h * 32 + 32)
		{
			mlx_pixel_put(data->m_p, data->w_p, i, j++, 0x000000);
		}
	}
	mlx_string_put(data->m_p, data->w_p, 0, data->map.h * 32, 0xFFFFFF, k);
	mlx_string_put(data->m_p, data->w_p, 65, data->map.h * 32, 0x00FF00, n);
	free (n);
}
