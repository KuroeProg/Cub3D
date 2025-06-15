#include "../includes/cub3d.h"
#include <math.h>

void	init_dda(t_dda *d, double pos_x, double pos_y, double dir_x, double dir_y)
{
    d->map_x = (int)pos_x;
    d->map_y = (int)pos_y;
    d->delta_x = fabs(1.0 / dir_x);
    d->delta_y = fabs(1.0 / dir_y);
    d->hit = 0;
    if (dir_x < 0)
    {
        d->step_x = -1;
        d->side_x = (pos_x - d->map_x) * d->delta_x;
    }
    else
    {
        d->step_x = 1;
        d->side_x = (d->map_x + 1.0 - pos_x) * d->delta_x;
    }
    if (dir_y < 0)
    {
        d->step_y = -1;
        d->side_y = (pos_y - d->map_y) * d->delta_y;
    }
    else
    {
        d->step_y = 1;
        d->side_y = (d->map_y + 1.0 - pos_y) * d->delta_y;
    }
}

void	perform_dda(t_data *data, t_dda *d)
{
    while (d->hit == 0)
    {
        if (d->side_x < d->side_y)
        {
            d->side_x += d->delta_x;
            d->map_x += d->step_x;
            d->side = 0;
        }
        else
        {
            d->side_y += d->delta_y;
            d->map_y += d->step_y;
            d->side = 1;
        }
        if (data->map[d->map_y][d->map_x] == '1')
            d->hit = 1;
    }
}

void	raycast_scene(t_data *data)
{
    int		x;
    double	camera_x;
    // double	ray_dir_x;
    // double	ray_dir_y;
    double	perp_wall_dist;
    t_dda	d;

    x = 0;
    while (x < data->screen_width)
    {
        camera_x = 2 * x / (double)data->screen_width - 1;
        d.ray_dir_x = data->dir_x + data->plane_x * camera_x;
        d.ray_dir_y = data->dir_y + data->plane_y * camera_x;
        init_dda(&d, data->player_x, data->player_y, d.ray_dir_x, d.ray_dir_y);
        perform_dda(data, &d);
        if (d.side == 0)
            perp_wall_dist = (d.map_x - data->player_x + (1 - d.step_x) / 2) / d.ray_dir_x;
        else
            perp_wall_dist = (d.map_y - data->player_y + (1 - d.step_y) / 2) / d.ray_dir_y;
        draw_vertical_line(data, x, perp_wall_dist, &d);
        x++;
    }
}
