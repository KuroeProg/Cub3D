#include "../includes/cub3d.h"


double	raycast_door(t_data *data, t_dda *d)
{
    int		x;
    double	camera_x;

    x = SCREEN_WIDTH / 2;
    camera_x = 2 * x / (double)data->screen_width - 1;
    d->ray_dir_x = data->dir_x + data->plane_x * camera_x;
    d->ray_dir_y = data->dir_y + data->plane_y * camera_x;
    init_dda(d, data->player_x, data->player_y, d->ray_dir_x, d->ray_dir_y);
    perform_dda(data, d);
    if (d->side == 0)
        return((d->map_x - data->player_x + (1 - d->step_x) / 2) / d->ray_dir_x);
    else
        return((d->map_y - data->player_y + (1 - d->step_y) / 2) / d->ray_dir_y);
    // draw_vertical_line(data, x, perp_wall_dist, &d);
}

void	animate_door(t_data *data, t_dda *d, char etat)
{
	data->map[d->map_y][d->map_x] = 'D';
	data->check_move = 1;
	render_frame(data);
	data->map[d->map_y][d->map_x] = etat;
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
		
		printf("dist : %f\n", dist);
	}
}
