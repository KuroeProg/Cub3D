/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahin <tbahin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:52:58 by tbahin            #+#    #+#             */
/*   Updated: 2025/06/29 22:49:01 by tbahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* **************************************************************************
** This function will take the keycode and the player structure as parameter.
** We will initialize the player structure.
** If the keycode is ESC we will exit the program.
** the function is actually not linked with move.c, but it will be used in the
 main.c
** **************************************************************************/

int	handle_keypress2(int keycode, t_data *data)
{
	if (keycode == D)
		move_player(data, 3);
	else if (keycode == Q || keycode == 65361)
		cam_player(data, 0);
	else if (keycode == E || keycode == 65363)
		cam_player(data, 1);
	else if (keycode == F)
		open_door(data);
	return (0);
}

int	handle_keypress(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 0xff1b)
		close_program(data);
	if (ft_strchr("aswdqe", keycode))
	{;
		data->keys[keycode] = 1;
		return (0);
	}
	if (keycode == W)
		move_player(data, 0);
	else if (keycode == S)
		move_player(data, 1);
	else if (keycode == A)
		move_player(data, 2);
	else if (keycode == C)
	{
		if (!data->check_animation)
			data->check_animation = 1;
		else
			data->check_animation = 0;
	}
	handle_keypress2(keycode, data);
	return (0);
}
