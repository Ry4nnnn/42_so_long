#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include "mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

// typedef	struct	s_position
// {
// 	int	x;
// 	int	y;
// }	t_position;

typedef	struct	s_player
{
	char		*path;
	int			count;
}	t_player;

typedef	struct	s_wall
{
	char	*path;
}	t_wall;

typedef	struct	s_floor
{
	char	*path;
}	t_floor;

typedef	struct	s_enemy
{
	char	*path;
}	t_enemy;

typedef	struct s_data
{
	void 		*mlx_ptr;
	void 		*win_ptr;
	t_player	player;
	t_wall		wall;
	t_floor		floor;
	t_enemy		enemy;
}	t_data;

//int main function
int	check_mapfile_name(char *argv);
int check_map(char *argv);
//
int	check_top_bot_line(char *buffer);
int	check_middle_line(char *buffer);
int	counter_line(char *argv);
int check_buffer_len(char *argv);

#endif