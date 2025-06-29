/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahin <tbahin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:52:17 by tbahin            #+#    #+#             */
/*   Updated: 2025/06/29 18:43:37 by tbahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	display_minimap(t_data *d, int x, int y)
{
	while (d->map[x])
	{
		y = 0;
		while (d->map[x][y])
		{
			if (d->map[x][y] == '1')
				print_block(d, 0x000000, y * d->squale_map, x * d->squale_map);
			else if (d->map[x][y] == '0' || d->map[x][y] == 'N'
			|| d->map[x][y] == 'W' || d->map[x][y] == 'E'
			|| d->map[x][y] == 'S')
				print_block(d, 0xFFFFFF, y * d->squale_map, x * d->squale_map);
			else if (d->map[x][y] == 'C')
				print_block(d, 0xBB0000, y * d->squale_map, x * d->squale_map);
			else if (d->map[x][y] == 'D')
				print_block(d, 0xF7BC14, y * d->squale_map, x * d->squale_map);
			else if (d->map[x][y] == 'O')
				print_block(d, 0x14F725, y * d->squale_map, x * d->squale_map);
			y++;
		}
		x++;
	}
	display_player(d, 0x00CCCC, d->player_x * (double)d->squale_map,
		d->player_y * (double)d->squale_map);
}

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
			tex_s->count = (float)(ANIME_SPEED * 2.25)
				/ (float)(SCREEN_WIDTH / 1000);
		}
		tex_e->count--;
		if (tex_e->count == 0)
		{
			if (tex_e->etat == 11)
				tex_e->etat = 0;
			else
				tex_e->etat++;
			tex_e->count = (float)ANIME_SPEED
				/ (float)(SCREEN_WIDTH / 1000);
		}
	}
}

void	mini_map(t_data *data)
{
	if (data->valid_size_map)
		return ;
	display_minimap(data, 0, 0);
}

int	render_frame(t_data *data)
{
	if (!data->map || !data->mlx_connection || !data->mlx_window)
		return (0);
	if (data->keys['w'])
		move_player(data, 0);
	if (data->keys['s'])
		move_player(data, 1);
	if (data->keys['a'])
		move_player(data, 2);
	if (data->keys['d'])
		move_player(data, 3);
	if (data->keys['q'])
		cam_player(data, 0);
	if (data->keys['e'])
		cam_player(data, 1);
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
	mini_map(data);
	mlx_put_image_to_window(data->mlx_connection,
		data->mlx_window, data->img_mlx.img, 0, 0);
	if (!data->door)
		data->check_move = 0;
	return (0);
}
