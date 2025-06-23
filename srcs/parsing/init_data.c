#include "../../includes/cub3d.h"

void	init_player(t_data *data, char c, int x, int y)
{
	if (c == 'N')
	{
		data->dir_x = 0;
		data->dir_y = -1;
	}
	else if (c == 'E')
	{
		data->dir_x = 1;
		data->dir_y = 0;
	}
	else if (c == 'S')
	{
		data->dir_x = 0;
		data->dir_y = 1;
	}
	else if (c == 'W')
	{
		data->dir_x = -1;
		data->dir_y = 0;
	}
	data->player_x = x + 0.5;
	data->player_y = y + 0.5;
	data->plane_x = -data->dir_y * 0.66;
	data->plane_y = data->dir_x * 0.66;
	data->rad = atan2(data->dir_y, data->dir_x);
}

void	initialize_img(t_img *img)
{
	img->path_S = NULL;
	img->path_E = NULL;
	img->path_N = NULL;
	img->path_W = NULL;
}

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
	d->door = 0;
}

void initialize_mlx(t_mlx *mlx)
{
	mlx->img = NULL;
	mlx->addr = NULL;
	mlx->bits_per_pixel = 0;
	mlx->line_length = 0;
	mlx->endian = 0;
}

void	init_data_mlx(t_data *data)
{
	data->mlx_connection = NULL;
    data->mlx_window = NULL;
	data->img_mlx.img = NULL;
    data->img_mlx.addr = NULL;
    data->img_mlx.bits_per_pixel = 0;
    data->img_mlx.line_length = 0;
    data->img_mlx.endian = 0;
}

void	init_anime(t_data *data)
{
	data->tex_s = malloc(sizeof(t_nx_f));
	data->tex_e = malloc(sizeof(t_nx_f));
	data->tex_s->count = ANIME_SPEED;
	data->tex_e->count = ANIME_SPEED;
	data->tex_s->etat = 0;
	data->tex_e->etat = 0;
}

void	init_data(t_data *data)
{
	init_data_mlx(data);
    data->screen_width = SCREEN_WIDTH;
    data->screen_height = SCREEN_HEIGHT;
    data->map = NULL;
    data->player_x = 0;
    data->player_y = 0;
    data->dir_x = 0;
    data->dir_y = 0;
    data->plane_x = -0.66;
    data->plane_y = 0;
    data->map_width = 0;
    data->map_height = 0;
    data->player_start_x = 0;
    data->player_start_y = 0;
    data->i = 0;
    data->j = 0;
	data->check_move = 1;
	data->prev_x = SCREEN_WIDTH / 2;
	data->rotation_speed = 0.05;
	data->door = NULL;
	data->check_animation = 1;
	init_anime(data);
    initialize_img(&data->img);
}

int	*void_to_int(t_data *data,	void *ptr)
{
	int bpp;
	int	sl;
	int	endian;
	int w;
	int	h;

	if (!ptr)
	{
		ptr = mlx_xpm_file_to_image(data->mlx_connection,
			"final_sprites_cub3d/red.xpm", &w, &h);
		if (!ptr)
		{
			printf("error texture \n");
			exit(1);
		}
	}
	int *pixels = (int *)mlx_get_data_addr(ptr, &bpp, &sl, &endian);
	return (pixels);
}

void	animate_wall1(t_data *data, int w, int h)
{
	data->texture[1][1] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/wall_animated3.xpm", &w, &h));
	data->texture[1][2] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/wall_animated4.xpm", &w, &h));
	data->texture[1][3] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/wall_animated5.xpm", &w, &h));
	data->texture[1][4] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/wall_animated6.xpm", &w, &h));
	// data->texture[1][5] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
	// 	"final_sprites_cub3d/wall_animated6.xpm", &w, &h));
}

void	animate_wall2(t_data *data, int w, int h)
{
	data->texture[3][1] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window2.xpm", &w, &h));
	data->texture[3][2] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window3.xpm", &w, &h));
	data->texture[3][3] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window4.xpm", &w, &h));
	data->texture[3][4] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window5.xpm", &w, &h));
	data->texture[3][5] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window6.xpm", &w, &h));
	data->texture[3][6] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window7.xpm", &w, &h));
	data->texture[3][7] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window8.xpm", &w, &h));
	data->texture[3][8] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window9.xpm", &w, &h));
	data->texture[3][9] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window10.xpm", &w, &h));
	data->texture[3][10] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window11.xpm", &w, &h));
	data->texture[3][11] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window12.xpm", &w, &h));
}

void	load_textures(t_data *data)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	data->texture[0][0] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		data->img.path_N, &w, &h));
	data->texture[1][0] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		data->img.path_S, &w, &h));
	animate_wall1(data, w, h);
	data->texture[2][0] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		data->img.path_W, &w, &h));
	data->texture[3][0] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		data->img.path_E, &w, &h));
	animate_wall2(data, w, h);
	data->texture[4][0] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
	"final_sprites_cub3d/porte1.xpm", &w, &h));
	data->texture[4][1] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
	"final_sprites_cub3d/porte3.xpm", &w, &h));
	data->texture[4][2] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
	"final_sprites_cub3d/porte2.xpm", &w, &h));
}
