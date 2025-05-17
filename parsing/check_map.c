#include "../cub3d.h"

int	get_map_info(int fd, t_data *data) 
{
	char	line;

	if (!fd)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		data->map_height++;
		if (ft_strlen(line) < data->map_width)
			// dans ce cas la map_width = taille max de colonne
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	// verifier si a la fin et au debut de la ligne, il y a un 1 ou whitespace
	// et si tab[0][sizeof(line[0])] == 1 or tab[0][sizeof(EOF)] == 1
	// allocate size of map
	// free fd
	// why did i made a extract line in my so_long wtf
}

ft_parsing()