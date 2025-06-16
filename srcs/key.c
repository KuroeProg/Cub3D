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
	else if (keycode == 0x0077)
		move_player(data, 0);
	else if (keycode == 0x0073)
		move_player(data, 1);
	else if (keycode == 0x0061)
		move_player(data, 2);
	else if (keycode == 0x0064)
		move_player(data, 3);
	return (0);
}
