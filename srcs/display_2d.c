#include "../includes/cub3d.h"

// // void	display_player(t_data *data)
// // {
// // 	int	i;
// // 	int	j;

// // 	i = 0;
// // 	while (i < 16)
// // 	{
// // 		j = 0;
// // 		while(j < 16)
// // 		{
// // 			ft_draw(&data->img_mlx, data->player_start_y * 32 + 8 + i, data->player_start_x * 32 + 8 + j, 0xFF0000);
// // 			j ++;
// // 		}
// // 		i++;
// // 	}
// // }

// void	ft_movesprite(char *line, t_data *game, int j, t_img *img)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i])
// 	{
// 		if (line[i] == 'P')
// 			mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
// 				img->img_player, i * 32, j * 32);
// 		i++;
// 	}
// }

/* ********************************************************************
** This function will display the line of the map. By 'Line' we mean
** the horizontal line of the map. We loop until the end of the line.
** If we find a '1' we put the wall sprite, if we find a '0' 
** we put the path sprite.
** We use the mlx_put_image_to_window function to put the sprites on the window.
** *******************************************************************/

// void	display_line(char *line, t_mlx *img_mlx, t_img *img, int j)
// {
// 	int	i;

// 	i = 0;
// 	(void)img;
// 	while (line[i])
// 	{
// 		if (line[i] == '1')
// 			ft_mlx_put_image_to_window(img_mlx, 0x000000, i * 32, j * 32);
// 		else if (line[i] == '0' || line [i] == 'N' || line[i] == 'W'
// 			|| line[i] == 'E' || line[i] == 'S')
// 			ft_mlx_put_image_to_window(img_mlx, 0xFFFFFF, i * 32, j * 32);
// 		i++;
// 	}
// }

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
	// int	j;

	// j = 0;
	if (!data->check_move)
		return (0);
	if (!data->map || !data->mlx_connection || !data->mlx_window)
		return (0);
	data->draw = data->img_mlx.addr;
	// ft_reset_img(data);
	/*
	while (data->map[j])
	{
		display_line(data->map[j], &data->img_mlx, &data->img, j);wdsadsdaws
		j++;
	} Minimap */
	ft_mlx_put_image(data, data->img.f_color, data->img.c_color);
	// printf("c : %d | f : %d", data->img.c_color, data->img.f_color);
	raycast_scene(data);
	// display_player(data);
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->img_mlx.img, 0, 0);
	// ft_mlx_put_image_to_window(data->mlx_connection, data->mlx_window,
	// 	data->img.img_player, data->player_x * 32, data->player_y * 32);
	data->check_move = 0;
	return (0);
}
