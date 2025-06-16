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
	data->player_start_x = x;
	data->player_start_y = y;
	data->player_x = x + 0.5;
	data->player_y = y + 0.5;
	data->plane_x = -data->dir_y * 0.66;
	data->plane_y = data->dir_x * 0.66;
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
    data->player_x = 0;
    data->player_y = 0;
    data->dir_x = 0;
    data->dir_y = 0;
    data->plane_x = -0.66;
    data->plane_y = 0;
    data->texture[0] = NULL;
    data->texture[1] = NULL;
    data->texture[2] = NULL;
    data->texture[3] = NULL;
    data->map_width = 0;
    data->map_height = 0;
    data->player_start_x = 0;
    data->player_start_y = 0;
    data->i = 0;
    data->j = 0;
    initialize_img(&data->img);
}

int	*void_to_int(void *ptr)
{
	int bpp, sl, endian;
	if (!ptr)
	{
		printf("error texture \n");
		exit(1);
	}
	int *pixels = (int *)mlx_get_data_addr(ptr, &bpp, &sl, &endian);
	return (pixels);
}

void	load_textures(t_data *data)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	data->texture[0] = void_to_int(mlx_xpm_file_to_image(data->mlx_connection,
		data->img.path_N, &w, &h));
	data->texture[1] = void_to_int(mlx_xpm_file_to_image(data->mlx_connection,
		data->img.path_S, &w, &h));
	data->texture[2] = void_to_int(mlx_xpm_file_to_image(data->mlx_connection,
		data->img.path_W, &w, &h));
	data->texture[3] = void_to_int(mlx_xpm_file_to_image(data->mlx_connection,
		data->img.path_E, &w, &h));
	// Par exemple, tu peux ajouter d'autres textures ici
}
