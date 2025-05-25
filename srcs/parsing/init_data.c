#include "../../includes/cub3d.h"

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

void init_data(t_data *data)
{
    data->map_width = 0;
    data->map_height = 0;
    data->dirX = 0;
    data->dirY = 0;
    data->PlaneX = 0;
    data->PlaneY = 0;
    data->i = 0;
    data->j = 0;
	// deplace dans le main
    // if (!get_map_info(file_path, data))
    //     return (0);
	//Deja present dans get_map_info
    // if (!ft_parsing(data))
    //     return (0);
}
