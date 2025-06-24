#include "../includes/cub3d.h"

int	close_program(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_mouse_show(data->mlx_connection, data->mlx_window);
	free_game(data);
	exit(0);
	return (0);
}

void	all_mlx_hook(t_data *data)
{
	mlx_hook(data->mlx_window, 2, (1L << 0), handle_keypress, data);
	mlx_loop_hook(data->mlx_connection, render_frame, data);
	mlx_hook(data->mlx_window, 6, 1L << 6, mouse_move, data);
	mlx_hook(data->mlx_window, 17, 0, close_program, data);
	mlx_loop(data->mlx_connection);
}

int main(int argc, char **argv)
{
	t_data data;

	init_data(&data);
	if (argc != 2)
		return (printf("Error\nUsage: ./cub3d [map.ber]\n"), 1);
	if (!get_map_info(&data, argv[1]))
		return (ft_printf(2, "Invalid map\n"), 0);
	data.mlx_connection = mlx_init();
	load_textures(&data);
	data.mlx_window = mlx_new_window(data.mlx_connection,
		data.screen_width, data.screen_height, "cub3D");
	mlx_mouse_hide(data.mlx_connection, data.mlx_window);
	data.img_mlx.img = mlx_new_image(data.mlx_connection, data.screen_width, data.screen_height);
	data.img_mlx.addr = mlx_get_data_addr(data.img_mlx.img,
			&data.img_mlx.bits_per_pixel, &data.img_mlx.line_length, &data.img_mlx.endian);
	all_mlx_hook(&data);
	close_program(&data);
	return (0);
}
