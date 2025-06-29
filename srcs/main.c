/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahin <tbahin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:53:05 by tbahin            #+#    #+#             */
/*   Updated: 2025/06/25 14:53:05 by tbahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_program(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	free_game(data);
	exit(0);
	return (0);
}

int	release_key(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode > 255)
		return (0);
	data->keys[keycode] = 0;
	if (ft_strchr("aswdqe", keycode))
		data->check_move--;
	return (0);
}

void	all_mlx_hook(t_data *data)
{
	mlx_hook(data->mlx_window, 2, (1L << 0), handle_keypress, data);
	mlx_hook(data->mlx_window, 3, (1L << 1), release_key, data);
	mlx_loop_hook(data->mlx_connection, render_frame, data);
	mlx_hook(data->mlx_window, 6, 1L << 6, mouse_move, data);
	mlx_hook(data->mlx_window, 17, 0, close_program, data);
	mlx_loop(data->mlx_connection);
}

int	check_valid_name(char *name)
{
	int	size;

	size = ft_strlen(name);
	if (size < 4 || ft_strcmp(".cub", &name[size - 4]))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data = (t_data){0};
	init_data(&data);
	if (argc != 2 || !check_valid_name(argv[1]))
		return (printf("Error\nUsage: ./cub3D [map.cub]\n"), 1);
	if (!get_map_info(&data, argv[1]))
		return (free_data(&data), ft_printf(2, "Invalid map\n"), 0);
	data.mlx_connection = mlx_init();
	load_textures(&data);
	data.mlx_window = mlx_new_window(data.mlx_connection,
			data.screen_width, data.screen_height, "cub3D");
	data.img_mlx.img = mlx_new_image(data.mlx_connection,
			data.screen_width, data.screen_height);
	data.img_mlx.addr = mlx_get_data_addr(data.img_mlx.img,
			&data.img_mlx.bits_per_pixel, &data.img_mlx.line_length,
			&data.img_mlx.endian);
	all_mlx_hook(&data);
	close_program(&data);
	return (0);
}
