#include "../../includes/cub3d.h"

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

// void	display_map(t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (data->map[i])
// 	{
// 		j = 0;
// 		while (data->map[i][j] && data->map[i][j] != '\n')
// 		{
// 			ft_printf(1, "%c", data->map[i][j]);
// 			j++;
// 		}
// 		ft_printf(1, "\n");
// 		i++;
// 	}
// }


// void	display_map_color(int **map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < 32)
// 	{
// 		j = 0;
// 		while (j < 32 && map[i][j] != '\n')
// 		{
// 			ft_printf(1, "%d ", map[i][j]);
// 			j++;
// 		}
// 		ft_printf(1, "\n");
// 		i++;
// 	}
// }

int	strlen_path(char *src)
{
	int	i;

	i = 0;
	while (src[i] && src[i] >= 46 && src[i] <= 122)
		i++;
	return (i);
}

char	*strcpy_path(char *src)
{
	int	i;
	char *dest;
	i = 0;
	dest = malloc(strlen_path(src) * (sizeof(char) + 1));
	while (src[i] && src[i] >= 46 && src[i] <= 122)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	strcpy_cube(char *dest, char *src, int size)
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

int	check_header(char *line)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	while (line[i])
	{
		if (!(line[i] == '1' || line[i] == '0' || (line[i] >= 9 && line[i] <= 13) || line[i] == 32))
			return (0);
		else if (line[i] == '1')
			check = 1;
		i++;
	}
	if (check == 0)
		return (0);
	return (1);
}

int	conv_color(int r, int g, int b)
{
	int color;

	color = (r << 16) | (g << 8) | b;
	return (color);
}

int	get_color(char *str)
{
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 0;
	b = 0;
	while (!ft_isdigit(*str))
		str++;
	r = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	while (!ft_isdigit(*str))
		str++;
	g = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	while (!ft_isdigit(*str))
		str++;
	b = ft_atoi(str);
	return (conv_color(r, g, b));
}

void	fill_path_text(char *line, t_data *data)
{
	if (line[0] == 'N' && line[1] == 'O')
		data->img.path_N = strcpy_path(&line[3]);
	else if (line[0] == 'S' && line[1] == 'O')
		data->img.path_S = strcpy_path(&line[3]);
	else if (line[0] == 'W' && line[1] == 'E')
		data->img.path_W = strcpy_path(&line[3]);
	else if (line[0] == 'E' && line[1] == 'A')
		data->img.path_E = strcpy_path(&line[3]);
	else if (line[0] == 'F' && line[1] == ' ')
		data->img.c_color = get_color(line);
	else if (line[0] == 'C' && line[1] == ' ')
		data->img.f_color = get_color(line);
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
	while (line && !check_header(line))
	{
		// fill_info(); remplir les infos de la map (exemple : NO)
		fill_path_text(line, data);
		free(line);
		line = get_next_line(fd);
	}
	while (line != NULL && data->map[i] && i < data->map_height)
	{
		strcpy_cube(data->map[i], line, data->map_width);
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
	while (line && !check_header(line))
	{
		// fill_info(); remplir les infos de la map (exemple : NO)
		free(line);
		line = get_next_line(fd);
	}
	while (line != NULL)
	{
		data->map_height++;
		if ((int)ft_strlen_n(line) > data->map_width)
			data->map_width = (int)ft_strlen_n(line);
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
	int	count;

	j = 0;
	count = 0;
	while (j < data->map_height)
	{
		i = 0;
		while (data->map[j][i] && i < data->map_width)
		{
			if (data->map[j][i] >= 9 && data->map[j][i] <= 13)
				i++;
			else if (data->map[j][i] == '0')
			{
				if (check_borders(data, i, j) == 0)
					return (printf("parsing error 1\n"), 0);
				i++;
			}
			else if (data->map[j][i] != '1' && data->map[j][i] != ' ' &&
					data->map[j][i] != 'N' && data->map[j][i] != 'E' &&
					data->map[j][i] != 'S' && data->map[j][i] != 'W')
				return (printf("parsing error 2 %i\n", data->map[j][i]), 0);
			else if (data->map[j][i] == 'N' || data->map[j][i] == 'E' ||
					data->map[j][i] == 'S' || data->map[j][i] == 'W')
			{
				if (!check_borders(data, i, j))
					return (printf("parsing error 1\n"), 0);
				else
					count++;
				init_player(data, data->map[j][i], i, j);
				i++;
			}
			else
				i++;
		}
		j++;
	}
	if (count != 1)
		return (printf("parsing error 3 %d\n", count), 0);
	// if (!flood_fill(data->map, data, i, j))
	// 	return (printf("parsing error\n"), 0);
	return (1);
}

int check_borders(t_data *data, int i, int j)
{
    if (i == 0 || j == 0 || i == data->map_width - 1 || j == data->map_height - 1)
        return (0);
    if (data->map[j - 1][i] == ' ' || data->map[j - 1][i] == '\0')
        return (0);
    if (data->map[j + 1][i] == ' ' || data->map[j + 1][i] == '\0')
        return (0);
    if (data->map[j][i - 1] == ' ' || data->map[j][i - 1] == '\0')
        return (0);
    if (data->map[j][i + 1] == ' ' || data->map[j][i + 1] == '\0')
        return (0);
    if (!(CHECK_MAP_TOP))
        return (0);
    if (!(CHECK_MAP_DOWN))
        return (0);
    if (!(CHECK_MAP_LEFT))
        return (0);
    if (!(CHECK_MAP_RIGHT))
        return (0);
    return (1);
}
