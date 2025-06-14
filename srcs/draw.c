#include "../includes/cub3d.h"

void	ft_reset_img(t_data *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 1920)
	{
		y = 0;
		while (y < 1080)
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
	if ((x < 1920 && x > 0) && (y < 1080 && y > 0))
	{
		my_mlx_pixel_put(img, x, y, color);
	}
}

void	ft_mlx_put_image_to_window(t_mlx *window, int color, int i, int j)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	while (k < 32)
	{
		l = 0;
		while (l < 32)
		{
			ft_draw(window, i + l, j + k, color);
			l++;
		}
		k++;
	}
}

void	ft_mlx_put_image_to_window(t_mlx *window, int color, int i, int j)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	while (k < 32)
	{
		l = 0;
		while (l < 32)
		{
			ft_draw(window, i + l, j + k, color);
			l++;
		}
		k++;
	}
}
