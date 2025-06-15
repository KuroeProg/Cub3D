#include "../includes/cub3d.h"

int	close_program(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	free_game(data);
	exit(0);
	return (0);
}

int main(int argc, char **argv)
{
	t_data data;

	init_data(&data);
	if (argc != 2)
		return (printf("Error\nUsage: ./cub3d [map.ber]\n"), 1);
	//check validation map + parsing
	if (!get_map_info(&data, argv[1]))
		ft_printf(1, "Invalide\n");
	else
		ft_printf(1, "Valide\n");
	//affichage de la map recu, dans le terminal
	// display_map(&data);
	//chargement des textures
	data.mlx_connection = mlx_init();
	load_textures(&data);
	//affichage de la map en 2D avec la minilibx
	data.mlx_window = mlx_new_window(data.mlx_connection,
		data.screen_width, data.screen_height, "cub3d");
	data.img_mlx.img = mlx_new_image(data.mlx_connection, data.screen_width, data.screen_height);
	data.img_mlx.addr = mlx_get_data_addr(data.img_mlx.img,
			&data.img_mlx.bits_per_pixel, &data.img_mlx.line_length, &data.img_mlx.endian);
	mlx_key_hook(data.mlx_window, handle_keypress, &data);
	mlx_loop_hook(data.mlx_connection, render_frame, &data);
	mlx_hook(data.mlx_window, 17, 0, close_program, &data);
	mlx_loop(data.mlx_connection);
	close_program(&data);
	return (0);
}
