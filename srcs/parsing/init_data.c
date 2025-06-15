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
	img->img_path = NULL;
	img->img_wall = NULL;
	img->img_player = NULL;
	img->img_ = NULL;
}

// t_img	xpm_to_img(t_data *game)
// {
// 	int width = 0;
// 	int height = 0;

// 	// game->img.img_path = get_sprite("sprites_cub3d/grass.xpm");
// 	// display_map_color(game->img.img_path);
// 	// game->img.img_wall = get_sprite("sprites_cub3d/water.xpm");
// 	// display_map_color(game->img.img_wall);
// 	// game->img.img_player = mlx_xpm_file_to_image(game->mlx_connection,
// 	// 		"sprites_cub3d/player.xpm", &width, &height);
// 	game->img.img_path = mlx_xpm_file_to_image(game->mlx_connection,
// 			"sprites_solong/grass.xpm", &width, &height);
// 	game->img.img_wall = mlx_xpm_file_to_image(game->mlx_connection,
// 			"sprites_solong/water.xpm", &width, &height);
// 	if (!game->img.img_path || !game->img.img_wall)
// 		close_program(game);
// 	return (game->img);
// }

// t_img	load_sprites(t_data *game)
// {
// 	initialize_img(&game->img);
// 	game->img = xpm_to_img(game);
// 	game->texture = (int **)malloc(sizeof(int *) * 4);
// 	game->texture[0] = game->img.img_path;
// 	game->texture[1] = game->img.img_wall;
// 	game->texture[2] = game->img.img_path;
// 	game->texture[3] = game->img.img_wall;
// 	return (game->img);
// }

void initialize_dda(t_dda *d)
{
	d->map_x = 0;
	d->map_y = 0;
	d->side_x = 0;
	d->side_y = 0;
	d->delta_x = 0;
	d->delta_y = 0;
	d->step_x = 0;
	d->step_y = 0;
	d->hit = 0;
	d->side = 0;
	d->ray_dir_x = 0;
	d->ray_dir_y = 0;
	d->tex_num = 0;
}

void initialize_sprit(t_sprit *s)
{
	s->color = NULL;
	s->width = 0;
	s->height = 0;
	s->tab = NULL;
	s->nb_colors = 0;
	s->sizeof_c = 0;
}

void initialize_mlx(t_mlx *mlx)
{
	mlx->img = NULL;
	mlx->addr = NULL;
	mlx->bits_per_pixel = 0;
	mlx->line_length = 0;
	mlx->endian = 0;
}

void initialize_conv(t_conv *conv)
{
	conv->c = 0;
	conv->color = 0;
}

void initialize_co(t_co *co)
{
	co->x = 0;
	co->y = 0;
}

void init_data(t_data *data)
{
    data->mlx_connection = NULL;
    data->mlx_window = NULL;
    data->img_mlx.img = NULL;
    data->img_mlx.addr = NULL;
    data->img_mlx.bits_per_pixel = 0;
    data->img_mlx.line_length = 0;
    data->img_mlx.endian = 0;
    data->screen_width = 1920;
    data->screen_height = 1080;
    data->map = NULL;
    data->player_x = 10;
    data->player_y = 4;
    data->dir_x = 0;
    data->dir_y = 0;
    data->plane_x = 0;
    data->plane_y = 0;
    data->texture[0] = NULL;
    data->texture[1] = NULL;
    data->texture[2] = NULL;
    data->texture[3] = NULL;
    data->map_width = 0;
    data->map_height = 0;
    data->player_start_x = 1;
    data->player_start_y = 1;
    data->i = 0;
    data->j = 0;
    initialize_img(&data->img);
}

int	*void_to_int(void *ptr)
{
	int bpp, sl, endian;
	if (!ptr)
		return (printf("test\n"),NULL);
	int *pixels = (int *)mlx_get_data_addr(ptr, &bpp, &sl, &endian);
	return (pixels);
}

void	load_textures(t_data *game)
{
	int	w;
	int	h;

	game->img.img_path = mlx_xpm_file_to_image(game->mlx_connection,
		"../sprites_cub3d/grass.xpm", &w, &h);
	game->img.img_wall = mlx_xpm_file_to_image(game->mlx_connection,
		"../sprites_cub3d/water.xpm", &w, &h);
	// Ajoute d'autres textures si besoin
	game->texture[0] = void_to_int(game->img.img_path);
	game->texture[1] = void_to_int(game->img.img_wall);
	game->texture[2] = void_to_int(game->img.img_path);
	game->texture[3] = void_to_int(game->img.img_wall);
	// Par exemple, tu peux ajouter d'autres textures ici
}


