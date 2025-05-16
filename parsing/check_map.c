#include "../cub3d.h"

int	check_map(t_map *map) 
{
	char	line;

	if (!map)
		return (0);
	line = get_next_line(map);
	while (line != NULL)
	{
		game->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	// allocate size of map
	// free fd
	// why did i made a extract line in my so_long wtf
}