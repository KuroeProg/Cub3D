/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:49:45 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/09 16:32:09 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	render_frame(t_game *game)
{
	int	j;

	j = 0;
	if (!game->map || !game->mlx_connection || !game->mlx_window)
		return (0);
	while (game->map[j])
	{
		display_line(game->map[j], game, &game->img, j);
		ft_movesprite(game->map[j], game, j, &game->img);
		j++;
	}
	mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
		game->img.img_player, game->player_x * 32, game->player_y * 32);
	return (0);
}

int	close_program(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_game(game);
	exit(0);
	return (0);
}

/* ********************************************************************
** The main function is here to 'pilote' the program
** It will initialize the mlx connection, the window, the sprites
** and the player. Then it will parse the map and run the game loop
** the 'mlx' functions are from the graphic library minilibx
** the 'ft_parsing' function is a custom function that will parse the map
** the 'run_game_loop' function is a custom function that will run the game loop
** at the end, it will free the memory and close the program.
** *******************************************************************/
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Error\nUsage: ./so_long [map.ber]\n"), 1);
	initialize_game(&game);
	game.mlx_connection = mlx_init();
	game.mlx_window = mlx_new_window(game.mlx_connection,
			WIDTH, HEIGHT, "so_long");
	ft_parsing(argv[1], &game);
	is_conform(&game);
	mlx_destroy_window(game.mlx_connection, game.mlx_window);
	game.mlx_window = mlx_new_window(game.mlx_connection,
			game.map_width * 32, game.map_height * 32, "so_long");
	initialize_player(&game, game.player_start_x, game.player_start_y);
	mlx_key_hook(game.mlx_window, handle_keypress, &game);
	if (game.is_updated == 0)
	{
		mlx_loop_hook(game.mlx_connection, render_frame, &game);
		game.is_updated = 1;
	}
	mlx_hook(game.mlx_window, 17, 0, close_program, &game);
	mlx_loop(game.mlx_connection);
	close_program(&game);
	return (0);
}
