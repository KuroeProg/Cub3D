/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahin <tbahin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:07:50 by cfiachet          #+#    #+#             */
/*   Updated: 2025/06/15 20:55:32 by tbahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* ********************************************************************
** This function will display the line of the map. By 'Line' we mean
** the horizontal line of the map. We loop until the end of the line.
** If we find a '1' we put the wall sprite, if we find a '0' 
** we put the path sprite.
** We use the mlx_put_image_to_window function to put the sprites on the window.
** *******************************************************************/

void	display_line(char *line, t_game *game, t_img *img, int j)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
				img->img_wall, i * 32, j * 32);
		else if (line[i] == '0' || line [i] == 'C' || line[i] == 'E'
			|| line[i] == 'P')
			mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
				img->img_path, i * 32, j * 32);
		i++;
	}
}

/* ********************************************************************
** This function will put the player, the item and the exit on the map.
** We loop until the end of the line. if we find a 'P' we put the player
** if we find a 'C' we put the item, if we find a 'E' we put the exit.
** We use the mlx_put_image_to_window function to put the sprites on the window.
** *******************************************************************/
void	ft_movesprite(char *line, t_game *game, int j, t_img *img)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
				img->img_player, i * 32, j * 32);
		else if (line[i] == 'C')
			mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
				img->img_item, i * 32, j * 32);
		else if (line[i] == 'E')
			mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
				img->img_exit, i * 32, j * 32);
		i++;
	}
}
/* ********************************************************************
** This function will parse the map and display it, by 'parsing' we mean that
** it will read the file and display the map depends of what is written, in 
** the window.
** We check if the fd is valid, if not we return. (fd is the file descriptor)
** We load the sprites with the load_sprites function.
** We loop until the end of the file, we read the line and display it with the
** display_line function.
** We use the move_sprite function to put the player, the item and the
** exit. on the map.
** We free the line and close the file. And also free the img, 
** for not having leaks.
** *******************************************************************/

void	ft_parsing(char *file_path, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return ;
	game->img = load_sprites(game);
	if (!game->img.img_path || !game->img.img_wall || !game->img.img_player
		|| !game->img.img_item || !game->img.img_exit)
		free_fd_bis(fd, game);
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		free_fd(game);
	ft_extrct_line(game, line, fd);
}

void	ft_extrct_line(t_game *game, char *line, int fd)
{
	game->j = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (game->map_width == 0)
			game->map_width = ftff_strlen(line) - 1;
		game->map[game->j] = line;
		game->i = 0;
		while (line[game->i])
		{
			if (line[game->i] == 'P')
			{
				game->player_start_x = game->i;
				game->player_start_y = game->j;
			}
			else if (line[game->i] == 'C')
				game->total_items++;
			game->i++;
		}
		game->j++;
		line = get_next_line(fd);
	}
	free(line);
	game->map[game->j] = NULL;
	close(fd);
}
