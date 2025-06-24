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
		dst = data->img_mlx.addr + (y * data->img_mlx.line_length + x * (data->img_mlx.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

// void	ft_mlx_put_image(t_data *data, int color, int color2)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	x = 0;
// 	while (y < SCREEN_HEIGHT)
// 	{
// 		x = 0;
// 		while (x < SCREEN_WIDTH)
// 		{
// 			if (y < SCREEN_HEIGHT / 2)
// 				color_to_pixel(data->draw, color);
// 			else
// 				color_to_pixel(data->draw, color2);
// 			data->draw += ((&data->img_mlx)->bits_per_pixel / 8);
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	display_player(t_data *data, int color, double x, double y)
{
	int		k;
	int		l;

	k = 0;
	while (k < (double)(SZC / 2))
	{
		l = 0;
		while (l < (double)(SZC / 2))
		{
			ft_mlx_pixel_put(data, (int)x + l, (int)y + k, color);
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
	while (k < SZC)
	{
		l = 0;
		while (l < SZC)
		{
			ft_mlx_pixel_put(data, x + l + (int)(data->cor_map_x * SZC), y + k + (int)(data->cor_map_y * SZC), color);
			l++;
		}
		k++;
	}
}
