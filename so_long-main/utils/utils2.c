/* ************************************************************************** */
/*												                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:31:18 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/02 22:31:39 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game *game)
{
	free_sprites(&game->img, game->mlx_connection);
	if (game->mlx_window)
	{
		mlx_destroy_window(game->mlx_connection, game->mlx_window);
		game->mlx_window = NULL;
	}
	if (game->mlx_connection)
	{
		mlx_destroy_display(game->mlx_connection);
		free(game->mlx_connection);
		game->mlx_connection = NULL;
	}
	if (game->map)
	{
		free_map(game->map);
		game->map = NULL;
	}
	exit(0);
}

void	free_fd(t_game *game)
{
	free(game->map);
	free_sprites(&game->img, game->mlx_connection);
	return ;
}

void	free_fd_bis(int fd, t_game *game)
{
	free_sprites(&game->img, game->mlx_connection);
	close(fd);
	return ;
}

t_img	xpm_to_img(t_game *game, int width, int height)
{
	game->img.img_path = mlx_xpm_file_to_image(game->mlx_connection,
			"sprites_solong/grass.xpm", &width, &height);
	game->img.img_wall = mlx_xpm_file_to_image(game->mlx_connection,
			"sprites_solong/water.xpm", &width, &height);
	game->img.img_player = mlx_xpm_file_to_image(game->mlx_connection,
			"sprites_solong/player.xpm", &width, &height);
	game->img.img_item = mlx_xpm_file_to_image(game->mlx_connection,
			"sprites_solong/item.xpm", &width, &height);
	game->img.img_exit = mlx_xpm_file_to_image(game->mlx_connection,
			"sprites_solong/exit.xpm", &width, &height);
	if (!game->img.img_path || !game->img.img_wall || !game->img.img_player
		|| !game->img.img_item || !game->img.img_exit)
		close_program(game);
	return (game->img);
}
