/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:33:25 by cfiachet          #+#    #+#             */
/*   Updated: 2025/07/01 10:40:33 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'E'
		|| c == 'S' || c == 'W' || c == 'C');
}

int	check_borders(t_data *data, int i, int j)
{
	if (i == 0 || j == 0 || i == data->map_width - 1
		|| j == data->map_height - 1)
		return (0);
	if (data->map[j - 1][i] == ' ' || data->map[j - 1][i] == '\0'
		|| data->map[j + 1][i] == ' ' || data->map[j + 1][i] == '\0'
		|| data->map[j][i - 1] == ' ' || data->map[j][i - 1] == '\0'
		|| data->map[j][i + 1] == ' ' || data->map[j][i + 1] == '\0')
		return (0);
	if (!is_valid_char(data->map[j - 1][i])
		|| !is_valid_char(data->map[j + 1][i])
		|| !is_valid_char(data->map[j][i - 1])
		|| !is_valid_char(data->map[j][i + 1]))
		return (0);
	return (1);
}

static int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	handle_map_char(t_data *d, int i, int j, int *count)
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
