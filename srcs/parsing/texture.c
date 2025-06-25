/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahin <tbahin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:13:06 by tbahin            #+#    #+#             */
/*   Updated: 2025/06/25 20:13:43 by tbahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	*void_to_int(t_data *data, void *ptr, void **tab_ptr)
{
	int bpp;
	int	sl;
	int	endian;
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
	int *pixels = (int *)mlx_get_data_addr(ptr, &bpp, &sl, &endian);
	*tab_ptr = ptr;
	return (pixels);
}

void	animate_wall1(t_data *data, int w, int h)
{
	data->texture[1][1] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/wall_animated3.xpm", &w, &h), &data->ptr_texture[1][1]);
	data->texture[1][2] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/wall_animated4.xpm", &w, &h), &data->ptr_texture[1][2]);
	data->texture[1][3] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/wall_animated5.xpm", &w, &h), &data->ptr_texture[1][3]);
	data->texture[1][4] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/wall_animated6.xpm", &w, &h), &data->ptr_texture[1][4]);
}

void	animate_wall2(t_data *data, int w, int h)
{
	data->texture[3][1] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window2.xpm", &w, &h), &data->ptr_texture[3][1]);
	data->texture[3][2] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window3.xpm", &w, &h), &data->ptr_texture[3][2]);
	data->texture[3][3] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window4.xpm", &w, &h), &data->ptr_texture[3][3]);
	data->texture[3][4] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window5.xpm", &w, &h), &data->ptr_texture[3][4]);
	data->texture[3][5] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window6.xpm", &w, &h), &data->ptr_texture[3][5]);
	data->texture[3][6] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window7.xpm", &w, &h), &data->ptr_texture[3][6]);
	data->texture[3][7] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window8.xpm", &w, &h), &data->ptr_texture[3][7]);
	data->texture[3][8] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window9.xpm", &w, &h), &data->ptr_texture[3][8]);
	data->texture[3][9] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window10.xpm", &w, &h), &data->ptr_texture[3][9]);
	data->texture[3][10] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window11.xpm", &w, &h), &data->ptr_texture[3][10]);
	data->texture[3][11] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		"final_sprites_cub3d/Window12.xpm", &w, &h), &data->ptr_texture[3][11]);
}

void	load_textures(t_data *data)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	data->texture[0][0] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,		data->img.path_n, &w, &h), &data->ptr_texture[0][0]);

	data->texture[1][0] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,		data->img.path_s, &w, &h), &data->ptr_texture[1][0]);
	animate_wall1(data, w, h);
	data->texture[2][0] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		data->img.path_w, &w, &h), &data->ptr_texture[2][0]);
	data->texture[3][0] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
		data->img.path_e, &w, &h), &data->ptr_texture[3][0]);
	animate_wall2(data, w, h);
	data->texture[4][0] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
	"final_sprites_cub3d/porte1.xpm", &w, &h), &data->ptr_texture[4][0]);
	data->texture[4][1] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
	"final_sprites_cub3d/porte3.xpm", &w, &h), &data->ptr_texture[4][1]);
	data->texture[4][2] = void_to_int(data, mlx_xpm_file_to_image(data->mlx_connection,
	"final_sprites_cub3d/porte2.xpm", &w, &h), &data->ptr_texture[4][2]);
}
