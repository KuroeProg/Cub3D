/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahin <tbahin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:52:51 by tbahin            #+#    #+#             */
/*   Updated: 2025/06/25 16:15:01 by tbahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	free_sprites(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 12)
		{
			if (data->texture[i][j])
				mlx_destroy_image(data->mlx_connection,
					data->ptr_texture[i][j]);
			j++;
		}
		i++;
	}
}

void	free_path_anim(t_data *data)
{
	free(data->img.path_s);
	free(data->img.path_w);
	free(data->img.path_e);
	free(data->img.path_n);
	free(data->tex_s);
	free(data->tex_e);
}

void	free_data(t_data *data)
{
	free_path_anim(data);
	free_map(data->map);
}

void	free_game(t_data *data)
{
	free_sprites(data);
	free_path_anim(data);
	if (data->door)
		free(data->door);
	mlx_destroy_image(data->mlx_connection, data->img_mlx.img);
	if (data->mlx_window)
	{
		mlx_destroy_window(data->mlx_connection, data->mlx_window);
		data->mlx_window = NULL;
	}
	if (data->mlx_connection)
	{
		mlx_destroy_display(data->mlx_connection);
		free(data->mlx_connection);
		data->mlx_connection = NULL;
	}
	if (data->map)
	{
		free_map(data->map);
		data->map = NULL;
	}
	exit(0);
}
