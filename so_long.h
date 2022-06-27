/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:52:14 by welim             #+#    #+#             */
/*   Updated: 2022/06/27 22:44:34 by welim            ###   ########.fr       */
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

typedef struct s_motion
{
	void *one;
	void *two;
	void *three;
	void *four;
	void *five;
	int count;
	int x;
	int y;
}	t_motion;

typedef struct s_image
{
	t_motion player;
	t_motion killer;
	t_motion coin;
	t_motion exit;
	t_motion wall;
	t_motion floor;
	int		coin_count;
}	t_image;

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
	t_image		image;
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

// mlx.c
void	mlx_create_window(t_data *data);
int	exit_game(t_data *data);
int	key_input(int key, t_data *data);

#endif