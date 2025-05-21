#include "../cub3d.h"

int	malloc_function(t_data *data)
{
	int	i;

	i = 0;
	data->map = malloc(sizeof(char *) * (data->map->height + 1));
	if (!data->map)
		return (perror("malloc"), 0);
	while (i < data->map->height)
	{
		data->map[i] = malloc(sizeof(char) * (data->map->width + 1))
		if (!data->map[i])
			return (perror("malloc"), 0);
		i++;
	}
	data->map[i] = '\0';
	return (1);
}

int	get_map_info(char *file_path, t_data *data) 
{
	char	line;
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (!fd || fd < 0)
		return (0);
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	while (line != NULL)
	{
		data->map_height++;
		if (ft_strlen(line) > data->map_width)
			data->map_width = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("debug get_map_info : map_height : %d, map_width : %d\n", data->map_height, data->map_width);
	if (!malloc_function(data))
		return (0);
	if (!ft_parsing)
		return (0);
	return (1); //if everything is good.
}

int ft_parsing(t_data *data)
{
	// verifier si a la fin et au debut de la ligne, il y a un 1 ou whitespace
	int	i;
	int	j;

	i = 0;
	j = 0;
	// check si les rebords sont soit des 0 soit des 1/whitespace
	while (j < data->map_height)
	{
		while (i < data->map_width)
		{
			if (map[j][i] == 0 || (map[j][i] >= 9 || map[j][i] <= 13))
				i++;
			else if (if (map[j][i] == 1 && /*contour de map == 0 or 1 or whitespace or NULL*/))
				i++;
			else
				return (printf("parsing error\n", 0));
		}
		j++;
	}
	// et si tab[0][sizeof(line[0])] == 1 or tab[0][sizeof(EOF)] == 1
}