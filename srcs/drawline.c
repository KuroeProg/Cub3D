#include "../includes/cub3d.h"
#include <math.h>

void	draw_vertical_line(t_data *data, int x, double perp_wall_dist, t_dda *d)
{
    int		line_height;
    int		draw_start;
    int		draw_end;
    int		y;
    double	wall_x;
    int		tex_x;
    int		tex_y;
    double	step;
    double	tex_pos;
    int		color;

    line_height = (int)(data->screen_height / perp_wall_dist);
    draw_start = -line_height / 2 + data->screen_height / 2;
    if (draw_start < 0)
        draw_start = 0;
    draw_end = line_height / 2 + data->screen_height / 2;
    if (draw_end >= data->screen_height)
        draw_end = data->screen_height - 1;
    if (d->side == 0)
        wall_x = data->player_y + perp_wall_dist * d->ray_dir_y;
    else
        wall_x = data->player_x + perp_wall_dist * d->ray_dir_x;
    wall_x -= floor(wall_x);
    tex_x = (int)(wall_x * 64.0);
    if (d->side == 0 && d->ray_dir_x > 0)
        tex_x = 64 - tex_x - 1;
    if (d->side == 1 && d->ray_dir_y < 0)
        tex_x = 64 - tex_x - 1;
    step = 1.0 * 64 / line_height;
    tex_pos = (draw_start - data->screen_height / 2
            + line_height / 2) * step;
    y = draw_start;
    while (y <= draw_end)
    {
        tex_y = (int)tex_pos & (64 - 1);
        tex_pos += step;
        color = data->texture[d->tex_num][64 * tex_y + tex_x];
        my_mlx_pixel_put(&data->img_mlx, x, y, color);
        y++;
    }
}