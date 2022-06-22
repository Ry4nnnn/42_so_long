#include "so_long.h"

int	check_mapfile_name(char *argv)
{
	int file_len;
	char *res;
	int valid;

	file_len = ft_strlen(argv);
	if (file_len >= 5)
	{
		res = ft_strnstr(argv, ".ber", file_len);
		if (res != NULL)
		{
			valid = ft_strncmp(res, ".ber", 4);
			if (valid == 0 && ft_strlen(res) == 4)
				return (1);
		}
	}
	return (0);
}
