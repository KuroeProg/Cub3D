/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahin <tbahin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:52:26 by tbahin            #+#    #+#             */
/*   Updated: 2025/06/25 16:15:52 by tbahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	raycast_door(t_data *da, t_dda *d)
{
	int		x;
	double	camera_x;

	x = SCREEN_WIDTH / 2;
	camera_x = 2 * x / (double)da->screen_width - 1;
	d->ray_dir_x = da->dir_x + da->plane_x * camera_x;
	d->ray_dir_y = da->dir_y + da->plane_y * camera_x;
	init_dda(d, da->player_x, da->player_y);
	perform_dda(da, d);
	if (d->side == 0)
		return ((d->map_x - da->player_x + (1 - d->step_x)
				/ 2) / d->ray_dir_x);
	else
		return ((d->map_y - da->player_y + (1 - d->step_y) / 2)
			/ d->ray_dir_y);
}

void	animate_door(t_data *data, t_dda *d, char etat)
{
	t_nx_f	*door;

	door = malloc(sizeof(t_nx_f));
	data->map[d->map_y][d->map_x] = 'D';
	data->check_move = 1;
	door->count = ANIME_SPEED;
	door->etat = etat;
	door->x = d->map_x;
	door->y = d->map_y;
	data->door = door;
}

void	open_door(t_data *data)
{
	t_dda	d;
	double	dist;

	dist = raycast_door(data, &d);
	if (d.door)
	{
		if (d.door == 1 && dist < 1.00)
			animate_door(data, &d, 'O');
		else if (d.door == 2 && dist < 1.00)
			animate_door(data, &d, 'C');
	}
}
