#include "../includes/cub3d.h"

int	valid_move(t_data *data, int move, float x, float y)
{
	if (move == 0)
	{
		x = data->player_x + data->dir_x * 0.04;
		y = data->player_y + data->dir_y * 0.04;
	}
	else if (move == 1)
	{
		x = data->player_x - data->dir_x * 0.04;
		y = data->player_y - data->dir_y * 0.04;
	}
	else if (move == 2)
	{
		x = data->player_x + data->dir_y * 0.04;
		y = data->player_y - data->dir_x * 0.04;
	}
	else if (move == 3)
	{
		x = data->player_x - data->dir_y * 0.04;
		y = data->player_y + data->dir_x * 0.04;
	}
	if (data->map[(int)y][(int)x] == '1' || data->map[(int)y][(int)x] == 'C')
		return (0);
	else
		return (1);
}

void	move_player(t_data *data, int move)
{
	
	if (move == 0 && valid_move(data, 0, 0 ,0))
	{
		data->player_x += data->dir_x * 0.04;
		data->player_y += data->dir_y * 0.04;
		data->cor_map_x += data->dir_x * 0.04;
		data->cor_map_y += data->dir_y * 0.04;

	}
	else if (move == 1 && valid_move(data, 1, 0, 0))
	{
		data->player_x -= data->dir_x * 0.04;
		data->player_y -= data->dir_y * 0.04;
		data->cor_map_x -= data->dir_x * 0.04;
		data->cor_map_y -= data->dir_y * 0.04;
	}
	else if (move == 2 && valid_move(data, 2, 0, 0))
	{
		data->player_x += data->dir_y * 0.04;
		data->player_y -= data->dir_x * 0.04;
		data->cor_map_x += data->dir_x * 0.04;
		data->cor_map_y -= data->dir_y * 0.04;
	}
	else if (move == 3 && valid_move(data, 3, 0, 0))
	{
		data->player_x -= data->dir_y * 0.04;
		data->player_y += data->dir_x * 0.04;
		data->cor_map_x -= data->dir_x * 0.04;
		data->cor_map_y += data->dir_y * 0.04;
	}
}

void	cam_player(t_data *data, int cam)
{
	if (cam == 0)
	{ 
		data->dir_x += data->dir_y * (PI / 64);
		data->dir_y += -data->dir_x * (PI / 64);
		data->plane_x = -data->dir_y * 0.66;
		data->plane_y = data->dir_x * 0.66;
		data->cor_map_x += data->dir_x * 0.04;
		data->cor_map_y += -data->dir_y * 0.04;
	}
	else if (cam == 1)
	{
		data->dir_x += -data->dir_y * (PI / 64);
		data->dir_y += data->dir_x * (PI / 64);
		data->plane_x = -data->dir_y * 0.66;
		data->plane_y = data->dir_x * 0.66;
		data->cor_map_x += -data->dir_x * 0.04;
		data->cor_map_y += data->dir_y * 0.04;
	}
}

int	mouse_move(int x, int y, t_data *data)
{
	int	delta_x;

	delta_x = x - data->prev_x;
	(void)y;
	if (delta_x != 0)
	{
		data->dir_x += -data->dir_y * (PI / 8) * ((float)delta_x / (SCREEN_WIDTH / 2));
		data->dir_y += data->dir_x * (PI / 8) * ((float)delta_x / (SCREEN_WIDTH / 2));
		data->plane_x = -data->dir_y * 0.66;
		data->plane_y = data->dir_x * 0.66;
		data->check_move = 2;
		mlx_mouse_move(data->mlx_connection, data->mlx_window, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	}

	return (0);
}
