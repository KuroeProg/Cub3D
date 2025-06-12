#include "../../includes/cub3d.h"

void	initialize_player(t_data *game, int start_x, int start_y)
{
	(void)start_x;
	(void)start_y;
	game->player_x = 10;
	game->player_y = 4;
}

void	initialize_img(t_img *img)
{
	img->img_path = 0;
	img->img_wall = 0;
	img->img_player = 0;
}

// t_img	xpm_to_img(t_data *game)
// {
	// game->img.img_path = get_sprite("sprites_cub3d/grass.xpm");
	// display_map_color(game->img.img_path);
	// game->img.img_wall = get_sprite("sprites_cub3d/water.xpm");
	// display_map_color(game->img.img_wall);
	// game->img.img_player = mlx_xpm_file_to_image(game->mlx_connection,
	// 		"sprites_cub3d/player.xpm", &width, &height);
	// if (!game->img.img_path || !game->img.img_wall)
	// 	close_program(game);
// 	return (game->img);
// }

t_img	load_sprites(t_data *game)
{
	initialize_img(&game->img);
	// game->img = xpm_to_img(game);
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
