#include "so_long.h"


static t_data	*converter(t_data *data, char *path)
{
	t_data	*img;
	int n;

	img = mlx_xpm_file_to_image(data->mlx_ptr, path, &n, &n);
	return (img);
}

static void	create_player(t_data *data)
{
	data->image.player.one = converter(data, "./image/player1.xpm");
	data->image.player.two = converter(data, "./image/player2.xpm");
	data->image.player.three = converter(data, "./image/player3.xpm");
}

static void	create_killer(t_data *data)
{
	data->image.killer.one = converter(data, "./image/killer1.xpm");
	data->image.killer.two = converter(data, "./image/killer2.xpm");
	data->image.killer.three = converter(data, "./image/killer3.xpm");
}

static void	create_objects(t_data *data)
{
	data->image.wall.one = converter(data, "./image/wall.xpm");
	data->image.floor.one = converter(data, "./image/floor.xpm");
	data->image.coin.one = converter(data, "./image/coin.xpm");
	data->image.exit.one = converter(data, "./image/exit.xpm");
}

void	create_images(t_data *data)
{
	create_player(data);
	create_killer(data);
	create_objects(data);
}
