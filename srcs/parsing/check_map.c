/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahin <tbahin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:45:08 by tbahin            #+#    #+#             */
/*   Updated: 2025/06/25 18:39:45 by tbahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	strlen_path(char *src)
{
	int	i;

	i = 0;
	while (src[i] && src[i] >= 46 && src[i] <= 122)
		i++;
	return (i);
}

int	check_valid_name_tex(char *name)
{
	int	size;

	size = ft_strlen(name);
	if ( size < 4 || ft_strcmp(".xpm", &name[size - 4]))
		return (0);
	return (1);
}

char	*strcpy_path(char *src)
{
	int	i;
	char *dest;
	i = 0;
	dest = malloc(strlen_path(src) * (sizeof(char) + 1));
	if (!dest)
		return (NULL);
	while (src[i] && src[i] >= 46 && src[i] <= 122)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	if (!check_valid_name_tex(dest))
		return (NULL);
	return (dest);
}

void	strcpy_cube(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (src[i] == 10)
			break ;
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
		if (!(line[i] == '1' || line[i] == '0'
			|| (line[i] >= 9 && line[i] <= 13) || line[i] == 32))
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

int	get_color(int *color, char *str)
{
	int	r;
	int	g;
	int	b;
	int	i;

	r = 0;
	g = 0;
	b = 0;
	i = 0;
	r = ft_atoi(str);
	while (ft_isdigit(str[i]))
		i++;
	while (!ft_isdigit(str[i]))
		i++;
	g = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	while (!ft_isdigit(str[i]))
		i++;
	b = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] && str[i] != '\n')
		return (0);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (0);
	*color = conv_color(r, g, b);
	return(1);
}

int	check_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
		i++;
	if (line[i])
		return (0);
	return (1);
}

int	fill_path_text(char *line, t_data *da)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ' && da->i == 0)
		return (da->img.path_n = strcpy_path(&line[3]), da->i++, 1);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ' && da->i == 1)
		return (da->img.path_s = strcpy_path(&line[3]), da->i++, 1);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ' && da->i == 2)
		return (da->img.path_w = strcpy_path(&line[3]), da->i++, 1);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ' && da->i == 3)
		return (da->img.path_e = strcpy_path(&line[3]), da->i++, 1);
	else if (line[0] == 'F' && line[1] == ' ' && da->i == 4)
	{
		if (!get_color(&da->img.f_color, &line[2]))
			return (printf("error floor color\n"), 0);
		return(da->i++, 1);
	}
	else if (line[0] == 'C' && line[1] == ' ' && da->i == 5)
	{
		if (!get_color(&da->img.c_color, &line[2]))
			return (printf("error ciel color\n"), 0);
		return (da->i++, 1);
	}
	return (0);
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
	line = get_next_line(fd);
	if (line == NULL)
		return (close(fd), 0);
	while (line && !check_header(line))
	{
		while (check_space(line))
		{
			free(line);
			line = get_next_line(fd);
		}
		if (check_header(line))
			break ;
		if (data->i < 6 && !fill_path_text(line, data))
		{
			free(line);
			line = NULL;
			get_next_line(-1);
			return(close(fd), 0);
		}
		free(line);
		line = get_next_line(fd);
	}
	while (line && i < data->map_height)
	{
		strcpy_cube(data->map[i], line, data->map_width);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	data->map[i] = NULL;
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
	if (!get_map(data, file_path))
		return (0);
	return (1);
}

int	invalid_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("0 \n1NEWSC", str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	get_map_info(t_data *data, char *file_path) 
{
	char	*line;
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (!fd || fd < 0)
		return (0);
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	while (line && !check_header(line))
	{
		while (check_space(line))
		{
			free(line);
			line = get_next_line(fd);
		}
		if (check_header(line))
			break ;
		free(line);
		line = get_next_line(fd);
	}
	while (line != NULL)
	{
		if (invalid_line(line))
		{
			get_next_line(-1);
			free(line);
			return (0);	
		}
		data->map_height++;
		if ((int)ft_strlen_n(line) > data->map_width)
			data->map_width = (int)ft_strlen_n(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!malloc_function(data, file_path))
		return (0);
	if (!ft_parsing(data))
		return (0);
	return (1);
}

int check_door(t_data *data, int i, int j)
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
	if (!CHECK_HORIZONTAL_DOOR && !CHECK_VERTICAL_DOOR)
		return (0);
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
					return (ft_printf(2, "parsing error : invalid character around 0\n"), 0);
				i++;
			}
			else if (data->map[j][i] == 'C')
			{
				if (check_door(data, i, j) == 0)
					return (ft_printf(2, "parsing error : invalid character around door (C)\n"), 0);
				i++;
			}
			else if (data->map[j][i] != '1' && data->map[j][i] != ' ' &&
					data->map[j][i] != 'N' && data->map[j][i] != 'E' &&
					data->map[j][i] != 'S' && data->map[j][i] != 'W')
				return (ft_printf(2, "parsing error invalid character %i\n", data->map[j][i]), 0);
			else if (data->map[j][i] == 'N' || data->map[j][i] == 'E' ||
					data->map[j][i] == 'S' || data->map[j][i] == 'W')
			{
				if (!check_borders(data, i, j))
					return (ft_printf(2, "parsing error : invalid character around start position\n"), 0);
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
		return (ft_printf(2, "parsing error : you need one and only one position of player\n"), 0);
	return (1);
}
