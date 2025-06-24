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

/* ********************************************************************
** This function will display the line of the map. By 'Line' we mean
** the horizontal line of the map. We loop until the end of the line.
** If we find a '1' we put the wall sprite, if we find a '0' 
** we put the path sprite.
** We use the mlx_put_image_to_window function to put the sprites on the window.
** *******************************************************************/

void	display_minimap(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == '1')
				print_block(data, 0x000000, j * SZC, i * SZC);
			else if (data->map[j][i] == '0' || data->map[j][i] == 'N'
			|| data->map[j][i] == 'W' || data->map[j][i] == 'E'
			|| data->map[j][i] == 'S')
				print_block(data, 0xFFFFFF, j * SZC, i * SZC);
			else if (data->map[j][i] == 'C')
				print_block(data, 0xBB0000, j * SZC, i * SZC);
			i++;
		}
		j++;
	}
}

// void	display_minimap(t_data *data)
// {
// 	int	st_x;
// 	int	st_y;
// 	int	x;
// 	int	y;

// 	st_x = data->player_x;
// 	st_y = data->player_y;
// 	x = -3;
// 	while (x <= 3)
// 	{
// 		y = -3;
// 		while (y <= 3)
// 		{
// 			if ((x + st_x >= 0 && y + st_y >= 0) && (x + st_x < data->map_height && y + st_y < data->map_width))
// 			{
// 				if (data->map[x + st_x][y + st_y] == '1')
// 					print_block(data, 0x000000, (int)(x + st_x) * SZC, (int)(y + st_y) * SZC);
// 				else if (data->map[x + st_x][y + st_y] == '0' || data->map[x + st_x][y + st_y] == 'N'
// 				|| data->map[x + st_x][y + st_y] == 'W' || data->map[x + st_x][y + st_y] == 'E'
// 				|| data->map[x + st_x][y + st_y] == 'S')
// 					print_block(data, 0xFFFFFF, (int)(x + st_x) * SZC, (int)(y + st_y) * SZC);
// 				else if (data->map[x + st_x][y + st_y] == 'C')
// 					print_block(data, 0xBB0000, (int)(x + st_x) * SZC, (int)(y + st_y) * SZC);
// 			}
// 			else
// 				printf("x %d y %d\n", x + st_x, y + st_y);
// 			y++;
// 		}
// 		x++;
// 	}
// 	printf("x %d y %d\n", st_x, st_y);
// 	display_player(data, 0x00CCCC, data->player_x * SZC, data->player_y * SZC);
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

void	manage_anime(t_data *data, t_nx_f *tex_s, t_nx_f *tex_e)
{
	if (!data->check_animation)
	{
		tex_s->count--;
		if (tex_s->count == 0)
		{
			if (tex_s->etat == 4)
				tex_s->etat = 0;
			else
				tex_s->etat++;
			tex_s->count = (float)(ANIME_SPEED * 2.25) / (float)(SCREEN_WIDTH / 1000);
		}
		tex_e->count--;
		if (tex_e->count == 0)
		{
			if (tex_e->etat == 11)
				tex_e->etat = 0;
			else
				tex_e->etat++;
			tex_e->count = (float)ANIME_SPEED  / (float)(SCREEN_WIDTH / 1000);
		}
	}
}

void	mini_map(t_data *data)
{
	display_minimap(data);
}

int	render_frame(t_data *data)
{
	if (!data->check_move && data->check_animation)
		return (0);
	if (!data->map || !data->mlx_connection || !data->mlx_window)
		return (0);
	if (data->door)
	{
		data->door->count--;
		if (data->door->count == 0)
		{
			data->map[data->door->y][data->door->x] = data->door->etat;
			free(data->door);
			data->door = NULL;
		}
	}
	manage_anime(data, data->tex_s, data->tex_e);
	data->draw = data->img_mlx.addr;
	raycast_scene(data);
	// mini_map(data);
	mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->img_mlx.img, 0, 0);
	if (!data->door)
		data->check_move = 0;
	return (0);
}
