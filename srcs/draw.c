#include "../includes/cub3d.h"

void	color_to_pixel(char *ptr, int color)
{
	*(unsigned int *)ptr = color;
}

void	ft_mlx_put_image(t_data *data, int color, int color2)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				color_to_pixel(data->draw, color);
			else
				color_to_pixel(data->draw, color2);
			data->draw += ((&data->img_mlx)->bits_per_pixel / 8);
			x++;
		}
		y++;
	}
}

// void	ft_mlx_put_image_to_window(t_mlx *window, int color, int i, int j)
// {
// 	int	k;
// 	int	l;

// 	k = 0;
// 	l = 0;
// 	while (k < 32)
// 	{
// 		l = 0;
// 		while (l < 32)
// 		{
// 			ft_draw(window, i + l, j + k, color);
// 			l++;
// 		}
// 		k++;
// 	}
// }
