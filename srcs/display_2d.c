#include "../includes/cub3d.h"

void	ft_movesprite(char *line, t_data *game, int j, t_img *img)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
				img->img_player, i * 32, j * 32);
		i++;
	}
}

/* ********************************************************************
** This function will display the line of the map. By 'Line' we mean
** the horizontal line of the map. We loop until the end of the line.
** If we find a '1' we put the wall sprite, if we find a '0' 
** we put the path sprite.
** We use the mlx_put_image_to_window function to put the sprites on the window.
** *******************************************************************/

void	display_line(char *line, t_mlx *img_mlx, t_img *img, int j)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			ft_mlx_put_image_to_window(img_mlx, img->img_wall, i * 32, j * 32);
		else if (line[i] == '0' || line [i] == 'N' || line[i] == 'W'
			|| line[i] == 'E' || line[i] == 'S')
			ft_mlx_put_image_to_window(img_mlx, img->img_path, i * 32, j * 32);
		i++;
	}
}

/* ********************************************************************
** This function will put the player, the item and the exit on the map.
** We loop until the end of the line. if we find a 'P' we put the player
** if we find a 'C' we put the item, if we find a 'E' we put the exit.
** We use the mlx_put_image_to_window function to put the sprites on the window.
** *******************************************************************/
// void	ft_movesprite(char *line, t_data *game, int j, t_img *img)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i])
// 	{
// 		if (line[i] == 'P')
// 			mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
// 				img->img_player, i * 32, j * 32);
// 		else if (line[i] == 'C')
// 			mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
// 				img->img_item, i * 32, j * 32);
// 		else if (line[i] == 'E')
// 			mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
// 				img->img_exit, i * 32, j * 32);
// 		i++;
// 	}
// }

int	render_frame(t_data *data)
{
	int	j;

	j = 0;
	if (!data->map || !data->mlx_connection || !data->mlx_window)
		return (0);
	// ft_reset_img(data);
	while (data->map[j])
	{
		display_line(data->map[j], &data->img_mlx, &data->img, j);
		// ft_movesprite(data->map[j], data, j, &data->img);
		j++;
	}
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->img_mlx.img, 0, 0);
	// ft_mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
	// 	data->img.img_player, data->player_x * 32, data->player_y * 32);
	return (0);
}