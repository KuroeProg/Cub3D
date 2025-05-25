/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:30:43 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/04 23:00:17 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* **************************************************************************
** 0 = up
** 1 = down
** 2 = left
** 3 = right
** **************************************************************************/
static void	initialize_coordinates(int *new_x, int *new_y,
	t_game *game, int direction)
{
	*new_x = game->player_x;
	*new_y = game->player_y;
	if (direction == 0)
		(*new_y)--;
	else if (direction == 1)
		(*new_y)++;
	else if (direction == 2)
		(*new_x)--;
	else if (direction == 3)
		(*new_x)++;
}

/* **************************************************************************
** This function will move the player on the map.
** We will check if the player can move on the next tile. (if it's a wall or not)
** If the player can move, we will put the previous tile to '0' and the new 'P'.
** If the player can move, we will update the player position.
** If the player move on an item, we will call the collect_item function.
** If the player move on the exit, we will call the check_exit function.
** **************************************************************************/
int	move_player(t_game *game, int direction)
{
	int	new_x;
	int	new_y;

	initialize_coordinates(&new_x, &new_y, game, direction);
	if (new_x >= 0 && new_x < game->map_width && new_y >= 0
		&& new_y < game->map_height)
	{
		if (game->map[new_y][new_x] != '1')
		{
			if (game->map[game->player_y][game->player_x] != 'E')
				game->map[game->player_y][game->player_x] = '0';
			game->player_x = new_x;
			game->player_y = new_y;
			handle_player_action(game, new_x, new_y);
			mlx_clear_window(game->mlx_connection, game->mlx_window);
			render_frame(game);
			return (1);
		}
	}
	return (0);
}

/* **************************************************************************
** Here we will check if the player has collected all the items when 
** he is on the Exit tile.
** if he does, we will print a message and exit the program.
** **************************************************************************/
void	handle_player_action(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		collect_item(game);
		game->map[y][x] = '0';
	}
	else if (game->map[y][x] == 'E')
	{
		check_exit(game);
	}
}

int	check_exit(t_game *game)
{
	if (game->collected_items != game->total_items)
	{
		ft_printf("You need to collect all item for exit !\n");
		return (0);
	}
	else
	{
		ft_printf("You win !\n");
		close_program(game);
	}
	return (0);
}

/* **************************************************************************
** This function will collect the item on the map.
** When the player 'walk'/move on the item, we will increment the item_collected.
** and we will change the map to '0' to remove the item from the map.
** After we collect the item, all we have is the floor.
** **************************************************************************/

void	collect_item(t_game *game)
{
	game->collected_items++;
	ft_printf("Item collected: %d\n", game->collected_items);
}
