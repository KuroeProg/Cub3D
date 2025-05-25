/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:35:37 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/02 22:35:43 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* **************************************************************************
** This function will initialize the player structure at 0.
** **************************************************************************/
void	initialize_player(t_game *game, int start_x, int start_y)
{
	game->player_x = start_x;
	game->player_y = start_y;
	game->collected_items = 0;
	game->move_count = 0;
}

void	initialize_game(t_game *game)
{
	game->mlx_connection = NULL;
	game->mlx_window = NULL;
	game->map = NULL;
	game->img.img_path = NULL;
	game->img.img_wall = NULL;
	game->img.img_player = NULL;
	game->img.img_item = NULL;
	game->img.img_exit = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->collected_items = 0;
	game->total_items = 0;
	game->player_start_x = 0;
	game->player_start_y = 0;
	game->move_count = 0;
	game->is_updated = 0;
}

void	initialize_check(t_check *check)
{
	check->check_exit = 0;
	check->check_player = 0;
	check->check_item = 0;
}

void	initialize_img(t_img *img)
{
	img->img_path = NULL;
	img->img_wall = NULL;
	img->img_player = NULL;
	img->img_item = NULL;
	img->img_exit = NULL;
}
