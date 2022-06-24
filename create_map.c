#include "so_long.h"

// static char *fill_column(char *buffer)
// {
// 	char *temp;

// 	temp = ft_strdup(buffer);
// 	return (temp);
// }

void	init_map(char *argv, t_data *data)
{
	int rows;
	char *buffer;
	int fd;
	int	column;
	int i;
	char *temp;

	i = 0;
	fd = open(argv, O_RDONLY);
	rows = counter_line(argv);//5
	data->map.map = (char **)malloc(sizeof(char *) * rows);//5
	while (rows > i)
	{
		buffer = get_next_line(fd);
		// printf ("%s\n", buffer);
		column = ft_strlen(buffer);
		temp = ft_strdup(buffer);
		printf("d: |%d|", i);
		printf ("%s\n", temp);
		data->map.map[i] = temp;
		printf ("data->map: |%s", data->map.map[i]);
		free (buffer);
		free (temp);
		i++;
	}
	// int j = 0;
	// while (data->map.map[1][j])
	// {
	// 	printf ("%c", data->map.map[1][j]);
	// 	j++;
	// }
	// data->map.map[i] = 0;
}

void	create_map(char *argv, t_data *data)
{
	init_map(argv, data);
}
