/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahin <tbahin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:53:11 by cfiachet          #+#    #+#             */
/*   Updated: 2025/06/30 22:37:20 by tbahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	skip_to_map(int fd, char **line)
{
	*line = get_next_line(fd);
	if (!(*line))
		return (0);
	while (*line && !check_header(*line))
	{
		while (check_space(*line))
		{
			free(*line);
			*line = get_next_line(fd);
		}
		if (check_header(*line))
			break ;
		free(*line);
		*line = get_next_line(fd);
	}
	return (*line != NULL);
}

static int	parse_map_lines(t_data *data, int fd, char *line)
{
	while (line)
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
	return (1);
}

int	get_map_info(t_data *data, char *file_path)
{
	char	*line;
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!skip_to_map(fd, &line))
		return (0);
	if (!parse_map_lines(data, fd, line))
	{
		close(fd);
		return (0);
	}
	close(fd);
	if (!malloc_function(data, file_path))
		return (0);
	if (!ft_parsing(data))
		return (0);
	return (1);
}
