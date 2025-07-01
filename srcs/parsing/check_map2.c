/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:11:06 by cfiachet          #+#    #+#             */
/*   Updated: 2025/07/01 10:37:45 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_valid_door(char c)
{
	if (c == 'W' || c == 'E' || c == 'N' || c == 'S' || c == '0')
		return (1);
	return (0);
}

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'E'
		|| c == 'S' || c == 'W' || c == 'C');
}

static int	is_border_or_invalid(t_data *d, int i, int j)
{
	if (i == 0 || j == 0 || i == d->map_width - 1
		|| j == d->map_height - 1)
		return (1);
	if (d->map[j - 1][i] == ' ' || d->map[j - 1][i] == '\0'
		|| d->map[j + 1][i] == ' ' || d->map[j + 1][i] == '\0'
		|| d->map[j][i - 1] == ' ' || d->map[j][i - 1] == '\0'
		|| d->map[j][i + 1] == ' ' || d->map[j][i + 1] == '\0')
		return (1);
	return (0);
}

int	check_door(t_data *d, int i, int j)
{
	if (is_border_or_invalid(d, i, j))
		return (0);
	if (!is_valid_char(d->map[j - 1][i]) || !is_valid_char(d->map[j + 1][i])
		|| !is_valid_char(d->map[j][i - 1]) || !is_valid_char(d->map[j][i + 1]))
		return (0);
	if (!(check_valid_door(d->map[j][i + 1])
		&& check_valid_door(d->map[j][i - 1])
		&& d->map[j + 1][i] == '1' && d->map[j - 1][i] == '1')
		&& !(d->map[j][i + 1] == '1' && d->map[j][i - 1] == '1'
		&& check_valid_door(d->map[j + 1][i])
		&& check_valid_door(d->map[j - 1][i])))
		return (0);
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
