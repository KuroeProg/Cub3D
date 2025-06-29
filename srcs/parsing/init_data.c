/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahin <tbahin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:51:53 by tbahin            #+#    #+#             */
/*   Updated: 2025/06/25 14:51:53 by tbahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_player(t_data *data, char c, int x, int y)
{
	if (c == 'N')
	{
		data->dir_x = 0;
		data->dir_y = -1;
	}
	else if (c == 'E')
	{
		data->dir_x = 1;
		data->dir_y = 0;
	}
	else if (c == 'S')
	{
		data->dir_x = 0;
		data->dir_y = 1;
	}
	else if (c == 'W')
	{
		data->dir_x = -1;
		data->dir_y = 0;
	}
	data->player_x = x + 0.5;
	data->player_y = y + 0.5;
	data->plane_x = -data->dir_y * 0.66;
	data->plane_y = data->dir_x * 0.66;
	data->rad = atan2(data->dir_y, data->dir_x);
}

void	init_anime(t_data *data)
{
	data->tex_s = malloc(sizeof(t_nx_f));
	data->tex_e = malloc(sizeof(t_nx_f));
	data->tex_s->count = ANIME_SPEED;
	data->tex_e->count = ANIME_SPEED;
	data->tex_s->etat = 0;
	data->tex_e->etat = 0;
}

void	set_squale_map(t_data *data)
{
	if (SCREEN_HEIGHT >= SCREEN_WIDTH && SCREEN_WIDTH > 100)
		data->squale_map = SCREEN_WIDTH / 100;
	else if (SCREEN_HEIGHT < SCREEN_WIDTH && SCREEN_HEIGHT > 100)
		data->squale_map = SCREEN_HEIGHT / 100;
	data->valid_size_map = SCREEN_HEIGHT < 100 && SCREEN_WIDTH < 100;
}

void	init_data(t_data *data)
{
	data->keys['a'] = 0;
	data->keys['w'] = 0;
	data->keys['d'] = 0;
	data->keys['s'] = 0;
	data->keys['q'] = 0;
	data->keys['e'] = 0;
	data->screen_width = SCREEN_WIDTH;
	data->screen_height = SCREEN_HEIGHT;
	data->plane_x = -0.66;
	data->check_move = 1;
	data->prev_x = SCREEN_WIDTH / 2;
	data->rotation_speed = 0.05;
	data->check_animation = 1;
	set_squale_map(data);
	init_anime(data);
}
