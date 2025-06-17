#include "../includes/cub3d.h"

int	valid_move(t_data *data, int move)
{
	float x;
	float y;

	x = 0;
	y = 0;
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
	if (data->map[(int)y][(int)x] == '1')
		return (0);
	else
		return (1);
}

void	move_player(t_data *data, int move)
{
	if (move == 0 && valid_move(data, 0))
	{
		data->player_x += data->dir_x * 0.04;
		data->player_y += data->dir_y * 0.04;
	}
	else if (move == 1 && valid_move(data, 1))
	{
		data->player_x -= data->dir_x * 0.04;
		data->player_y -= data->dir_y * 0.04;
	}
	else if (move == 2 && valid_move(data, 2))
	{
		data->player_x += data->dir_y * 0.04;
		data->player_y -= data->dir_x * 0.04;
	}
	else if (move == 3 && valid_move(data, 3))
	{
		data->player_x -= data->dir_y * 0.04;
		data->player_y += data->dir_x * 0.04;
	}
}

void	cam_player(t_data *data, int cam)
{
	if (cam == 0)
	{ 
		data->rad -= PI/64;
		data->dir_x += data->dir_y * (PI / 64);
		data->dir_y += -data->dir_x * (PI / 64);
		data->plane_x = -data->dir_y * 0.66;
		data->plane_y = data->dir_x * 0.66;
	}
	else if (cam == 1)
	{
		data->rad += PI/64;
		data->dir_x += -data->dir_y * (PI / 64);
		data->dir_y += data->dir_x * (PI / 64);
		data->plane_x = -data->dir_y * 0.66;
		data->plane_y = data->dir_x * 0.66;
	}
}
