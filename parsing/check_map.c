#include "../cub3d.h"
// #include "../.minilibx-linux/mlx.h"

// void	ft_flood_fill(char **map, t_data *data, int i, int j)
// {
// 	if (i < 0 || j < 0 || i >= data->map_width || j >= data->map_height)
// 		return ;
// 	if (map[j][i] == '1' || map[j][i] == 'F')
// 		return ;
// 	if (map[j][i] == '0' || map[j][i] == 'W' || map[j][i] == 'N' ||
// 		|| map[j][i] == 'S' || map[j][i] == 'E')
// 		map[j][i] = 'F';
// 	else
// 	{
// 		// ft_check_free2(i, j, game, map);
// 		// ft_error(8, game);
// 		return ;
// 	}
// 	ft_flood_fill(map, game, i + 1, j);
// 	ft_flood_fill(map, game, i - 1, j);
// 	ft_flood_fill(map, game, i, j + 1);
// 	ft_flood_fill(map, game, i, j - 1);
// }

void	display_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		printf("%s", data->map[i]);
		i++;
	}
}

void	ft_strcpy_cube(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (src && src[i])
			dest[i] = src[i];
		else
			dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
}

int	ft_check_header(char *line)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	while (line[i])
	{
		if (!(line[i] == '1' || line[i] == '0' || (line[i] >= 9 && line[i] <= 13)))
			return (0);
		else if (line[i] == '1')
			check = 1;
		i++;
	}
	if (check == 0)
		return (0);
	return (1);
}

int	get_map(t_data *data, char *file_path) 
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(file_path, O_RDONLY);
	if (!fd || fd < 0)
		return (0);
	line = get_next_line(fd); //implicit declaration
	if (line == NULL)
		return (0);
	while (line && !ft_check_header(line))
	{
		// fill_info(); remplir les infos de la map (exemple : NO)
		free(line);
		line = get_next_line(fd);
	}
	while (line != NULL && data->map[i] && i < data->map_height)
	{
		ft_strcpy_cube(data->map[i], line, data->map_width);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	malloc_function(t_data *data, char *file_path)
{
	int	i;

	i = 0;
	data->map = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map)
		return (perror("malloc"), 0);
	while (i < data->map_height)
	{
		data->map[i] = malloc(sizeof(char) * (data->map_width + 1));
		if (!data->map[i])
			return (perror("malloc"), 0);
		i++;
	}
	data->map[i] = NULL;
	get_map(data, file_path);
	return (1);
}

int	get_map_info(t_data *data, char *file_path) 
{
	char	*line;
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (!fd || fd < 0)
		return (0);
	line = get_next_line(fd); //implicit declaration
	if (line == NULL)
		return (0);
	while (line && !ft_check_header(line))
	{
		// fill_info(); remplir les infos de la map (exemple : NO)
		free(line);
		line = get_next_line(fd);
	}
	while (line != NULL)
	{
		data->map_height++;
		if ((int)ft_strlen(line) > data->map_width)
			data->map_width = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("debug get_map_info : map_height : %d, map_width : %d\n", data->map_height, data->map_width);
	if (!malloc_function(data, file_path))
		return (0);
	if (!ft_parsing(data))
		return (0);
	return (1); //if everything is good.
}

int ft_parsing(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < data->map_height)
	{
		while (i < data->map_width)
		{
			if (data->map[j][i] >= 9 && data->map[j][i] <= 13)
				i++;
			else if (data->map[j][i] == '0')
			{
				if (check_borders(data, i, j) == 0)
					return (printf("parsing error3\n"), 0);
				i++;
			}
			else if (data->map[j][i] != '1' && data->map[j][i] != ' ' &&
					data->map[j][i] != 'N' && data->map[j][i] != 'E' &&
					data->map[j][i] != 'S' && data->map[j][i] != 'W')
				return (printf("parsing error\n"), 0);
			else
				i++;
		}
		j++;
	}
	// if (!flood_fill(data->map, data, i, j))
	// 	return (printf("parsing error\n"), 0);
	return (1);
}

int check_borders(t_data *data, int i, int j)
{
    if (i == 0 || j == 0 || i == data->map_width - 1 ||
		j == data->map_height - 1)
        return (0);
    if (CHECK_MAP_TOP)
        return (0);
    if (CHECK_MAP_DOWN)
        return (0);
    if (CHECK_MAP_LEFT)
        return (0);
    if (CHECK_MAP_RIGHT)
        return (0);
    return (1);
}
