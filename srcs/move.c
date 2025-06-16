#include "../includes/cub3d.h"

void	move_player(t_data *data, int move)
{
	if (move == 0)
	{
		data->player_x += data->dir_x * 0.03;
		data->player_y += data->dir_y * 0.03;
	}
	else if (move == 1)
	{
		data->player_x -= data->dir_x * 0.03;
		data->player_y -= data->dir_y * 0.03;
	}
	else if (move == 2)
	{
		data->player_x += data->dir_y * 0.03;
		data->player_y -= data->dir_x * 0.03;
	}
	else if (move == 3)
	{
		data->player_x -= data->dir_y * 0.03;
		data->player_y += data->dir_x * 0.03;
	}
}
