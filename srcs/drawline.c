#include "../includes/cub3d.h"
#include <math.h>

void	draw_pixel(t_mlx *img_mlx, char *ptr, int color, int y)
{
	ptr += y * img_mlx->line_length;
	*(unsigned int *)ptr = color;
}

void	draw_vertical_line(t_data *data, int x, double perp_wall_dist, t_dda *d)
{
    int		line_height = 0;
    int		draw_start = 0;
    int		draw_end = 0;
    int		y = 0;
    double	wall_x = 0;
    int		tex_x = 0;
    int		tex_y = 0;
    double	step = 0;
    double	tex_pos = 0;
    int		color = 0;
	// char	*ptr;

	(void)x;
	data->draw += ((&data->img_mlx)->bits_per_pixel / 8);
    line_height = (int)(data->screen_height / perp_wall_dist);
    draw_start = -line_height / 2 + data->screen_height / 2;
	//ne depasse pas le bas de l'ecran
    if (draw_start < 0)
        draw_start = 0;
    draw_end = line_height / 2 + data->screen_height / 2;
	//ne depasse pas le haut de l'ecran
    if (draw_end >= data->screen_height)
        draw_end = data->screen_height - 1;
    if (d->side == 0)
        wall_x = data->player_y + perp_wall_dist * d->ray_dir_y;
    else
        wall_x = data->player_x + perp_wall_dist * d->ray_dir_x;
    wall_x -= floor(wall_x);
	// printf("d_side %d\n", d->side);
	// printf("d_ray_dir_x %f\n", d->ray_dir_x);
	// printf("d_ray_dir_y %f\n", d->ray_dir_y);
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
    tex_x = (int)(wall_x * 64.0);
    if (d->side == 0 && d->ray_dir_x > 0)
        tex_x = TEX_WIDTH - tex_x - 1;
    if (d->side == 1 && d->ray_dir_y < 0)
        tex_x = TEX_WIDTH - tex_x - 1;
    step = 1.0 * TEX_HEIGHT / line_height;
    tex_pos = (draw_start - data->screen_height / 2
            + line_height / 2) * step;
    y = draw_start;
    while (y < draw_end)
    {
        tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
        tex_pos += step;
        color = data->texture[d->tex_num][TEX_WIDTH * tex_y + tex_x];
		draw_pixel(&data->img_mlx, data->draw, color, y);
        // my_mlx_pixel_put(&data->img_mlx, x, y, color);
        y++;
    }
}
