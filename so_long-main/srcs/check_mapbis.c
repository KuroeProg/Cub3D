/* ************************************************************************** */
/*													                        */
/*                                                        :::      ::::::::   */
/*   check_mapbis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 22:10:16 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/02 22:10:26 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_rectangular(t_game *game)
{
	int	i;
	int	line_length;

	if (!game->map || game->map_height == 1)
	{
		if (!game->map)
			ft_printf("Error\nMap is empty\n");
		else
			ft_printf("Map is too small\n");
		close_program(game);
	}
	line_length = nl_strlen(game->map[0]);
	i = 1;
	while (i < game->map_height)
	{
		if (nl_strlen(game->map[i]) != line_length)
		{
			ft_printf("Error\nMap is not rectangular\n");
			close_program(game);
		}
		i++;
	}
	game->map_width = line_length;
}

void	ft_checkerror(t_check *check, t_game *game)
{
	if (check->check_exit != 1)
		ft_error(2, game);
	if (check->check_player != 1)
		ft_error(3, game);
	if (check->check_item < 1)
		ft_error(4, game);
}

void	free_map_copy(char **map_copy, int map_height)
{
	int	k;

	k = 0;
	while (k < map_height)
	{
		free(map_copy[k]);
		k++;
	}
	free(map_copy);
}

void	ft_check_free(int k, int l, t_game *game, char **map_copy)
{
	k = 0;
	while (k < game->map_height)
	{
		l = 0;
		while (l < game->map_width)
		{
			if (map_copy[k][l] == 'C' || map_copy[k][l] == 'E')
			{
				free_map_copy(map_copy, game->map_height);
				ft_error(5, game);
			}
			l++;
		}
		k++;
	}
	free_map_copy(map_copy, game->map_height);
}

void	ft_check_free2(int k, int l, t_game *game, char **map_copy)
{
	k = 0;
	while (k < game->map_height)
	{
		l = 0;
		while (l < game->map_width)
		{
			if (map_copy[k][l] == 'C' || map_copy[k][l] == 'E')
			{
				free_map_copy(map_copy, game->map_height);
				ft_error(8, game);
			}
			l++;
		}
		k++;
	}
	free_map_copy(map_copy, game->map_height);
}
