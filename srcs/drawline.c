#include "../includes/cub3d.h"
#include <math.h>

void	draw_pixel(t_mlx *img_mlx, char *ptr, int color, int y)
{
	ptr += y * img_mlx->line_length;
	*(unsigned int *)ptr = color;
}

void	init_draw_line(t_dwl *dw)
{
	dw->line_height = 0;
    dw->draw_start = 0;
    dw->draw_end = 0;
    dw->y = 0;
    dw->wall_x = 0;
    dw->tex_x = 0;
    dw->tex_y = 0;
    dw->step = 0;
    dw->tex_pos = 0;
    dw->color = 0;
}

void	select_tex(t_dda *d)
{
	if (d->side == 0 && d->ray_dir_x > 0)
    	d->tex_num = EA;
	else if (d->side == 0 && d->ray_dir_x <= 0)
    	d->tex_num = WE;
	else if (d->side == 1 && d->ray_dir_y > 0)
   		d->tex_num = SO;
	else if (d->side == 1 && d->ray_dir_y <= 0)
    	d->tex_num = NO;
	if (d->door == 1)
    	d->tex_num = DOOR;
	if (d->door == 2)
    	d->tex_num = 5;
	if (d->door == 3)
    	d->tex_num = 6;
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

void	draw_vertical_line(t_data *data, double perp_wall_dist, t_dda *d)
{
	t_dwl dw;

	init_draw_line(&dw);
	data->draw += ((&data->img_mlx)->bits_per_pixel / 8);
	range_line(data, perp_wall_dist, &dw, d);
	select_tex(d);
    dw.tex_x = (int)(dw.wall_x * 64.0);
    if (d->side == 0 && d->ray_dir_x > 0)
        dw.tex_x = TEX_WIDTH - dw.tex_x - 1;
    if (d->side == 1 && d->ray_dir_y < 0)
        dw.tex_x = TEX_WIDTH - dw.tex_x - 1;
    dw.step = 1.0 * TEX_HEIGHT / dw.line_height;
    dw.tex_pos = (dw.draw_start - data->screen_height / 2
            + dw.line_height / 2) * dw.step;
    dw.y = dw.draw_start;
    while (dw.y < dw.draw_end)
    {
        dw.tex_y = (int)dw.tex_pos & (TEX_HEIGHT - 1);
        dw.tex_pos += dw.step;
        dw.color = data->texture[d->tex_num][TEX_WIDTH * dw.tex_y + dw.tex_x];
		draw_pixel(&data->img_mlx, data->draw, dw.color, dw.y);
        dw.y++;
    }
}
