#include "../includes/cub3d.h"

/* **************************************************************************
** This function will take the keycode and the player structure as parameter.
** We will initialize the player structure.
** If the keycode is ESC we will exit the program.
** the function is actually not linked with move.c, but it will be used in the
 main.c
** **************************************************************************/

int	handle_keypress(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 0xff1b)
	 	close_program(data);
	else if (keycode == W)
		move_player(data, 0);
	else if (keycode == S)
		move_player(data, 1);
	else if (keycode == A)
		move_player(data, 2);
	else if (keycode == D)
		move_player(data, 3);
	else if (keycode == Q)
		cam_player(data, 0);
	else if (keycode == E)
		cam_player(data, 1);
	else if (keycode == F)
		open_door(data);
	else if (keycode == C)
	{
		if (!data->check_animation)
			data->check_animation = 1;
		else
			data->check_animation = 0;
	}
	data->check_move = 1;
	return (0);
}
