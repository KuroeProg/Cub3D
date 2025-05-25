#include "../includes/cub3d.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
void	free_sprites(t_img *img, void *mlx_connection)
{
	if (!img || !mlx_connection)
		return ;
	if (img->img_path)
		mlx_destroy_image(mlx_connection, img->img_path);
	if (img->img_wall)
		mlx_destroy_image(mlx_connection, img->img_wall);
}

void	free_game(t_data *game)
{
	free_sprites(&game->img, game->mlx_connection);
	if (game->mlx_window)
	{
		mlx_destroy_window(game->mlx_connection, game->mlx_window);
		game->mlx_window = NULL;
	}
	if (game->mlx_connection)
	{
		mlx_destroy_display(game->mlx_connection);
		free(game->mlx_connection);
		game->mlx_connection = NULL;
	}
	if (game->map)
	{
		free_map(game->map);
		game->map = NULL;
	}
	exit(0);
}

int	close_program(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	free_game(data);
	exit(0);
	return (0);
}

void	initialize_img(t_img *img)
{
	img->img_path = NULL;
	img->img_wall = NULL;

}

t_img	xpm_to_img(t_data *game, int width, int height)
{
	game->img.img_path = mlx_xpm_file_to_image(game->mlx_connection,
			"sprites_cub3d/grass.xpm", &width, &height);
	game->img.img_wall = mlx_xpm_file_to_image(game->mlx_connection,
			"sprites_cub3d/water.xpm", &width, &height);
	if (!game->img.img_path || !game->img.img_wall)
		close_program(game);
	return (game->img);
}

t_img	load_sprites(t_data *game)
{
	int		width;
	int		height;

	width = 0;
	height = 0;
	initialize_img(&game->img);
	game->img = xpm_to_img(game, width, height);
	return (game->img);
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
	display_map(&data);
	//chargement des textures
	data.mlx_connection = mlx_init();
	data.img = load_sprites(&data);
	//affichage de la map en 2D avec la minilibx
	data.mlx_window = mlx_new_window(data.mlx_connection,
		data.map_width * 32, data.map_height * 32, "so_long");
	mlx_loop_hook(data.mlx_connection, render_frame, &data);
	mlx_hook(data.mlx_window, 17, 0, close_program, &data);
	mlx_loop(data.mlx_connection);
	close_program(&data);
	return (0);
}
