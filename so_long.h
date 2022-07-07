/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:52:14 by welim             #+#    #+#             */
/*   Updated: 2022/07/07 17:20:17 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_motion
{
	void		*one;
	void		*two;
	void		*three;
	int			count;
}	t_motion;

typedef struct s_image
{
	t_motion	ply;
	t_motion	killer;
	t_motion	coin;
	t_motion	exit;
	t_motion	wall;
	t_motion	flr;
	int			p_x;
	int			p_y;
	int			k_x;
	int			k_y;
}	t_image;

typedef struct s_map
{
	char		**map;
	int			h;
	int			l;
}	t_map;

typedef struct s_data
{
	void		*m_p;
	void		*w_p;
	t_map		map;
	t_image		img;
	int			moves;
	int			frame;
}	t_data;

//so_long check_valid
void	check_valid(char *argv, t_data *data);
int		counter_line(char *argv);

//so_long check_valid_utils
int		check_top_line(int fd);
int		check_mid_line(int fd);
int		check_bot_line(int fd);
int		check_buffer_len(char *argv);
void	populate_objects(char *buffer, t_data *data);
void	check_objects(t_data *data);

//create_images
void	create_map(char *argv, t_data *data);
void	create_images(t_data *data);
int		print_image(t_data *data);

// windows
t_data	create_window(t_data *data, char *name);
int		exit_game(t_data *data);
void	moves_counter(t_data *data);

//main_controls
int		key_input(int key, t_data *data);

//player_control
void	move_pw(t_data *data);
void	move_pw2(t_data *data);
void	move_ps(t_data *data);
void	move_ps2(t_data *data);
void	move_pd(t_data *data);
void	move_pd2(t_data *data);
void	move_pa(t_data *data);
void	move_pa2(t_data *data);

//killer_controls
void	move_kw(t_data *data);
void	move_ks(t_data *data);
void	move_kd(t_data *data);
void	move_ka(t_data *data);

#endif