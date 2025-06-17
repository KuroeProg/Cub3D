#include "../includes/cub3d.h"

void	ft_reset_img(t_data *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
			my_mlx_pixel_put(&img->img_mlx, x, y, 0);
			y++;
		}
		x++;
	}
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw(t_mlx *img, int x, int y, int color)
{
	if ((x < SCREEN_WIDTH && x > 0) && (y < SCREEN_HEIGHT && y > 0))
	{
		my_mlx_pixel_put(img, x, y, color);
	}
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
				my_mlx_pixel_put(&data->img_mlx, x, y, color);
			else
				my_mlx_pixel_put(&data->img_mlx, x, y, color2);
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
