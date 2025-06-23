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
	

void	print_block(t_data *data, int color, int j, int i)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	while (k < (double)SZC)
	{
		l = 0;
		while (l < (double)SZC)
		{
			ft_mlx_pixel_put(data, MM_X + j + l, MM_Y + i + k, color);
			l++;
		}
		k++;
	}
}
