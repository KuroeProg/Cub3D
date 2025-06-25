/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahin <tbahin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:52:34 by tbahin            #+#    #+#             */
/*   Updated: 2025/06/25 15:56:49 by tbahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	color_to_pixel(char *ptr, int color)
{
	*(unsigned int *)ptr = color;
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x > 0 && x < SCREEN_WIDTH) && (y > 0 && y < SCREEN_HEIGHT))
	{
		dst = data->img_mlx.addr + (y * data->img_mlx.line_length
				+ x * (data->img_mlx.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	display_player(t_data *data, int color, double x, double y)
{
	int		k;
	int		l;

	k = -(data->squale_map / 4);
	while (k < (data->squale_map / 4))
	{
		l = -(data->squale_map / 4);
		while (l < (data->squale_map / 4))
		{
			ft_mlx_pixel_put(data, x + (double)k, y + (double)l, color);
			l++;
		}
		k++;
	}
}

void	print_block(t_data *data, int color, int x, int y)
{
	int		k;
	int		l;

	k = 0;
	while (k < data->squale_map)
	{
		l = 0;
		while (l < data->squale_map)
		{
			ft_mlx_pixel_put(data, x + k, y + l, color);
			l++;
		}
		k++;
	}
}
