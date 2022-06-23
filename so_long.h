/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:52:14 by welim             #+#    #+#             */
/*   Updated: 2022/06/23 23:01:34 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include "mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

// typedef struct s_position
// {
// 	int	x;
// 	int	y;
// }	t_position;

typedef struct s_wall
{
	char	*path;
}	t_wall;

typedef struct s_floor
{
	char	*path;
}	t_floor;

typedef struct s_enemy
{
	char	*path;
}	t_enemy;

typedef struct s_player
{
	char		*path;
	int			count;
}	t_player;

typedef struct s_collect
{
	char		*path;
	int			count;
}	t_collect;

typedef struct s_exit
{
	char		*path;
	int			count;
}	t_exit;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_player	player;
	t_wall		wall;
	t_floor		floor;
	t_enemy		enemy;
	t_collect	collect;
	t_exit		exit;
}	t_data;

//int main function
void	check_map(char *argv);
int		counter_line(char *argv);
void	check_valid(char *argv, t_data *data);

#endif