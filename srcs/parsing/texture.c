/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:13:06 by tbahin            #+#    #+#             */
/*   Updated: 2025/06/30 17:57:51 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	animate_wall3(t_data *d, int w, int h)
{
	d->texture[3][6] = void_to_int(d, MLX(d->mlx_connection,
				"final_sprites_cub3d/Window7.xpm",
				&w, &h), &d->PT_TEXT[3][6]);
	d->texture[3][7] = void_to_int(d, MLX(d->mlx_connection,
				"final_sprites_cub3d/Window8.xpm",
				&w, &h), &d->PT_TEXT[3][7]);
	d->texture[3][8] = void_to_int(d, MLX(d->mlx_connection,
				"final_sprites_cub3d/Window9.xpm",
				&w, &h), &d->PT_TEXT[3][8]);
	d->texture[3][9] = void_to_int(d, MLX(d->mlx_connection,
				"final_sprites_cub3d/Window10.xpm",
				&w, &h), &d->PT_TEXT[3][9]);
	d->texture[3][10] = void_to_int(d, MLX(d->mlx_connection,
				"final_sprites_cub3d/Window11.xpm",
				&w, &h), &d->PT_TEXT[3][10]);
	d->texture[3][11] = void_to_int(d, MLX(d->mlx_connection,
				"final_sprites_cub3d/Window12.xpm",
				&w, &h), &d->PT_TEXT[3][11]);
}

int	*void_to_int(t_data *data, void *ptr, void **tab_ptr)
{
	int	bpp;
	int	sl;
	int	endian;
	int	*pixels;

	(void)data;
	if (!ptr)
	{
		printf("error texture\n");
		free_sprites(data);
		free_data(data);
		mlx_destroy_display(data->mlx_connection);
		free(data->mlx_connection);
		data->mlx_connection = NULL;
		exit(1);
	}
	pixels = (int *)mlx_get_data_addr(ptr, &bpp, &sl, &endian);
	*tab_ptr = ptr;
	return (pixels);
}

void	animate_wall1(t_data *d, int w, int h)
{
	d->texture[1][1] = void_to_int(d, MLX(d->mlx_connection,
				"final_sprites_cub3d/wall_animated3.xpm",
				&w, &h), &d->PT_TEXT[1][1]);
	d->texture[1][2] = void_to_int(d, MLX(d->mlx_connection,
				"final_sprites_cub3d/wall_animated4.xpm",
				&w, &h), &d->PT_TEXT[1][2]);
	d->texture[1][3] = void_to_int(d, MLX(d->mlx_connection,
				"final_sprites_cub3d/wall_animated5.xpm",
				&w, &h), &d->PT_TEXT[1][3]);
	d->texture[1][4] = void_to_int(d, MLX(d->mlx_connection,
				"final_sprites_cub3d/wall_animated6.xpm",
				&w, &h), &d->PT_TEXT[1][4]);
}

void	animate_wall2(t_data *d, int w, int h)
{
	d->texture[3][1] = void_to_int(d, MLX(d->mlx_connection,
				"final_sprites_cub3d/Window2.xpm",
				&w, &h), &d->PT_TEXT[3][1]);
	d->texture[3][2] = void_to_int(d, MLX(d->mlx_connection,
				"final_sprites_cub3d/Window3.xpm",
				&w, &h), &d->PT_TEXT[3][2]);
	d->texture[3][3] = void_to_int(d, MLX(d->mlx_connection,
				"final_sprites_cub3d/Window4.xpm",
				&w, &h), &d->PT_TEXT[3][3]);
	d->texture[3][4] = void_to_int(d, MLX(d->mlx_connection,
				"final_sprites_cub3d/Window5.xpm",
				&w, &h), &d->PT_TEXT[3][4]);
	d->texture[3][5] = void_to_int(d, MLX(d->mlx_connection,
				"final_sprites_cub3d/Window6.xpm",
				&w, &h), &d->PT_TEXT[3][5]);
	animate_wall3(d, w, h);
}

void	load_textures(t_data *data)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	data->texture[0][0] = void_to_int(data, MLX(data->mlx_connection,
				data->img.path_n, &w, &h), &data->PT_TEXT[0][0]);
	data->texture[1][0] = void_to_int(data, MLX(data->mlx_connection,
				data->img.path_s, &w, &h), &data->PT_TEXT[1][0]);
	animate_wall1(data, w, h);
	data->texture[2][0] = void_to_int(data, MLX(data->mlx_connection,
				data->img.path_w, &w, &h), &data->PT_TEXT[2][0]);
	data->texture[3][0] = void_to_int(data, MLX(data->mlx_connection,
				data->img.path_e, &w, &h), &data->PT_TEXT[3][0]);
	animate_wall2(data, w, h);
	data->texture[4][0] = void_to_int(data, MLX(data->mlx_connection,
				"final_sprites_cub3d/porte1.xpm",
				&w, &h), &data->PT_TEXT[4][0]);
	data->texture[4][1] = void_to_int(data, MLX(data->mlx_connection,
				"final_sprites_cub3d/porte3.xpm",
				&w, &h), &data->PT_TEXT[4][1]);
	data->texture[4][2] = void_to_int(data, MLX(data->mlx_connection,
				"final_sprites_cub3d/porte2.xpm",
				&w, &h), &data->PT_TEXT[4][2]);
}
