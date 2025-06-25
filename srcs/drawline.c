/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahin <tbahin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:52:41 by tbahin            #+#    #+#             */
/*   Updated: 2025/06/25 14:52:43 by tbahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

void	draw_pixel(t_mlx *img_mlx, char *ptr, int color, int y)
{
	ptr += y * img_mlx->line_length;
	*(unsigned int *)ptr = color;
}

void	select_tex(t_data *data, t_dda *d, int *etat)
{
	if (d->side == 0 && d->ray_dir_x > 0)
	{
		d->tex_num = EA;
		*etat = data->tex_e->etat;
	}
	else if (d->side == 0 && d->ray_dir_x <= 0)
		d->tex_num = WE;
	else if (d->side == 1 && d->ray_dir_y > 0)
	{
		d->tex_num = SO;
		*etat = data->tex_s->etat;
	}
	else if (d->side == 1 && d->ray_dir_y <= 0)
		d->tex_num = NO;
	if (d->door)
	{
		d->tex_num = DOOR;
		*etat = d->door - 1;
	}
}

void	range_line(t_data *data, double perp_wall_dist, t_dwl *dw, t_dda *d)
{
	dw->line_height = (int)(data->screen_height / perp_wall_dist);
	dw->draw_start = -dw->line_height / 2 + data->screen_height / 2;
	if (dw->draw_start < 0)
		dw->draw_start = 0;
	dw->draw_end = dw->line_height / 2 + data->screen_height / 2;
	if (dw->draw_end >= data->screen_height)
		dw->draw_end = data->screen_height - 1;
	if (d->side == 0)
		dw->wall_x = data->player_y + perp_wall_dist * d->ray_dir_y;
	else
		dw->wall_x = data->player_x + perp_wall_dist * d->ray_dir_x;
	dw->wall_x -= floor(dw->wall_x);
}

void	draw_side(t_data *data, int start, int end)
{
	int	y;

	y = 0;
	while (y < start)
	{
		draw_pixel(&data->img_mlx, data->draw, data->img.f_color, y);
		y++;
	}
	y = end + 1;
	while (y > end && y < SCREEN_HEIGHT)
	{
		draw_pixel(&data->img_mlx, data->draw, data->img.c_color, y);
		y++;
	}
}

void	draw_vertical_line(t_data *da, double perp_wall_dist, t_dda *d)
{
	t_dwl	dw;
	int		e;

	e = 0;
	dw = (t_dwl){0};
	da->draw += ((&da->img_mlx)->bits_per_pixel / 8);
	range_line(da, perp_wall_dist, &dw, d);
	select_tex(da, d, &e);
	dw.tex_x = (int)(dw.wall_x * 64.0);
	if (d->side == 0 && d->ray_dir_x > 0)
		dw.tex_x = TEX_WIDTH - dw.tex_x - 1;
	if (d->side == 1 && d->ray_dir_y < 0)
		dw.tex_x = TEX_WIDTH - dw.tex_x - 1;
	dw.step = 1.0 * TEX_HEIGHT / dw.line_height;
	dw.tex_pos = (dw.draw_start - da->screen_height / 2
			+ dw.line_height / 2) * dw.step;
	dw.y = dw.draw_start;
	draw_side(da, dw.draw_start, dw.draw_end);
	while (dw.y < dw.draw_end)
	{
		dw.tex_y = (int)dw.tex_pos & (TEX_HEIGHT - 1);
		dw.tex_pos += dw.step;
		dw.color = da->texture[d->tex_num][e][TEX_WIDTH * dw.tex_y + dw.tex_x];
		draw_pixel(&da->img_mlx, da->draw, dw.color, dw.y++);
	}
}
