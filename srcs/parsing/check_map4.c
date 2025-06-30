/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:16:51 by cfiachet          #+#    #+#             */
/*   Updated: 2025/06/30 22:40:20 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
