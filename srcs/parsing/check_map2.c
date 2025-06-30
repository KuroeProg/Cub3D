/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahin <tbahin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:11:06 by cfiachet          #+#    #+#             */
/*   Updated: 2025/06/30 23:22:28 by tbahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int check_valid_door(char c)
{
	if (c == 'W' || c == 'E' || c == 'N' || c == 'S' || c == '0')
		return (1);
	return (0);
}

int	check_door(t_data *data, int i, int j)
{
	if (i == 0 || j == 0 || i == data->map_width - 1
		|| j == data->map_height - 1)
		return (0);
	if (data->map[j - 1][i] == ' ' || data->map[j - 1][i] == '\0')
		return (0);
	if (data->map[j + 1][i] == ' ' || data->map[j + 1][i] == '\0')
		return (0);
	if (data->map[j][i - 1] == ' ' || data->map[j][i - 1] == '\0')
		return (0);
	if (data->map[j][i + 1] == ' ' || data->map[j][i + 1] == '\0')
		return (0);
	if (!((data->map[j - 1][i] == '0' || data->map[j - 1][i] == '1' || \
    data->map[j - 1][i] == 'N' || data->map[j - 1][i] == 'E' || \
	data->map[j - 1][i] == 'S' || data->map[j - 1][i] == 'W' || \
    data->map[j - 1][i] == 'C')))
		return (0);
	if (!((data->map[j + 1][i] == '0' || data->map[j + 1][i] == '1' || \
    data->map[j + 1][i] == 'N' || data->map[j + 1][i] == 'E' || \
	data->map[j + 1][i] == 'S' || data->map[j + 1][i] == 'W' || \
    data->map[j + 1][i] == 'C')))
		return (0);
	if (!((data->map[j][i - 1] == '0' || data->map[j][i - 1] == '1' || \
     data->map[j][i - 1] == 'N' || data->map[j][i - 1] == 'E' || \
     data->map[j][i - 1] == 'S' || data->map[j][i - 1] == 'W' || \
	 data->map[j][i - 1] == 'C')))
		return (0);
	if (!((data->map[j][i + 1] == '0' || data->map[j][i + 1] == '1' || \
     data->map[j][i + 1] == 'N' || data->map[j][i + 1] == 'E' || \
     data->map[j][i + 1] == 'S' || data->map[j][i + 1] == 'W' || \
	 data->map[j][i + 1] == 'C')))
		return (0);
	if (!(check_valid_door(data->map[j][i + 1]) && check_valid_door(data->map[j][i - 1]) && \
     data->map[j + 1][i] == '1' && data->map[j - 1][i] == '1') && !(data->map[j][i + 1] == '1' && data->map[j][i - 1] == '1' && \
     check_valid_door(data->map[j + 1][i]) && check_valid_door(data->map[j - 1][i])))
		return (0);
	return (1);
}

int	check_borders(t_data *data, int i, int j)
{
	if (i == 0 || j == 0 || i == data->map_width - 1
		|| j == data->map_height - 1)
		return (0);
	if (data->map[j - 1][i] == ' ' || data->map[j - 1][i] == '\0')
		return (0);
	if (data->map[j + 1][i] == ' ' || data->map[j + 1][i] == '\0')
		return (0);
	if (data->map[j][i - 1] == ' ' || data->map[j][i - 1] == '\0')
		return (0);
	if (data->map[j][i + 1] == ' ' || data->map[j][i + 1] == '\0')
		return (0);
	if (!((data->map[j - 1][i] == '0' || data->map[j - 1][i] == '1' || \
    data->map[j - 1][i] == 'N' || data->map[j - 1][i] == 'E' || \
	data->map[j - 1][i] == 'S' || data->map[j - 1][i] == 'W' || \
    data->map[j - 1][i] == 'C')))
		return (0);
	if (!((data->map[j + 1][i] == '0' || data->map[j + 1][i] == '1' || \
    data->map[j + 1][i] == 'N' || data->map[j + 1][i] == 'E' || \
	data->map[j + 1][i] == 'S' || data->map[j + 1][i] == 'W' || \
    data->map[j + 1][i] == 'C')))
		return (0);
	if (!((data->map[j][i - 1] == '0' || data->map[j][i - 1] == '1' || \
     data->map[j][i - 1] == 'N' || data->map[j][i - 1] == 'E' || \
     data->map[j][i - 1] == 'S' || data->map[j][i - 1] == 'W' || \
	 data->map[j][i - 1] == 'C')))
		return (0);
	if (!((data->map[j][i + 1] == '0' || data->map[j][i + 1] == '1' || \
     data->map[j][i + 1] == 'N' || data->map[j][i + 1] == 'E' || \
     data->map[j][i + 1] == 'S' || data->map[j][i + 1] == 'W' || \
	 data->map[j][i + 1] == 'C')
))
		return (0);
	return (1);
}

static int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	handle_map_char(t_data *d, int i, int j, int *count)
{
	if (d->map[j][i] == '0')
	{
		if (!check_borders(d, i, j))
			return (ft_printf(2, "invalid char : around 0\n"), 0);
	}
	else if (d->map[j][i] == 'C')
	{
		if (!check_door(d, i, j))
			return (ft_printf(2, "invalid char : around door\n"), 0);
	}
	else if (is_player_char(d->map[j][i]))
	{
		if (!check_borders(d, i, j))
			return (ft_printf(2, "invalid char : start pos\n"), 0);
		(*count)++;
		init_player(d, d->map[j][i], i, j);
	}
	else if (d->map[j][i] != '1' && d->map[j][i] != ' ')
		return (ft_printf(2, "invalid char %i\n", d->map[j][i]), 0);
	return (1);
}

int	ft_parsing(t_data *data)
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
			else
			{
				if (!handle_map_char(data, i, j, &count))
					return (0);
				i++;
			}
		}
		j++;
	}
	if (count != 1)
		return (ft_printf(2, "error : one player position allowed\n"), 0);
	return (1);
}
