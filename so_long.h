/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:52:14 by welim             #+#    #+#             */
/*   Updated: 2022/06/24 21:42:41 by welim            ###   ########.fr       */
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

typedef struct s_killer
{
	char	*path;
	int		count;
}	t_killer;

typedef struct s_player
{
	char		*path;
	int			count;
}	t_player;

typedef struct s_coin
{
	char		*path;
	int			count;
}	t_coin;

typedef struct s_exit
{
	char		*path;
	int			count;
}	t_exit;

typedef struct	s_map
{
	char 	**map;
	int 	height;
	int 	length;
	
}	t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_player	player;
	t_wall		wall;
	t_floor		floor;
	t_killer	killer;
	t_coin		coin;
	t_exit		exit;
}	t_data;

//so_long check_valid
void	check_valid(char *argv, t_data *data);
int		counter_line(char *argv);

//so_long check_valid_utils
int		check_top_bot_line(int fd);
int		check_mid_line(int fd);
int		check_buffer_len(char *argv);
void	populate_objects(char *buffer, t_data *data);
void	check_objects(t_data *data);

//create_map
void	create_map(char *argv, t_data *data);

#endif