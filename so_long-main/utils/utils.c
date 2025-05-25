/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:03:11 by cfiachet          #+#    #+#             */
/*   Updated: 2025/01/14 15:40:08 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	free_sprites(t_img *img, void *mlx_connection)
{
	if (!img || !mlx_connection)
		return ;
	if (img->img_path)
		mlx_destroy_image(mlx_connection, img->img_path);
	if (img->img_wall)
		mlx_destroy_image(mlx_connection, img->img_wall);
	if (img->img_player)
		mlx_destroy_image(mlx_connection, img->img_player);
	if (img->img_item)
		mlx_destroy_image(mlx_connection, img->img_item);
	if (img->img_exit)
		mlx_destroy_image(mlx_connection, img->img_exit);
}

int	ftff_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	nl_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	ft_error(int n, t_game *game)
{
	if (n == 1)
		ft_printf("Error\nMap not surrounded by walls\n");
	if (n == 2)
		ft_printf("Number of Exit invalid (must be 1)\n");
	if (n == 3)
		ft_printf("Number of Player invalid (must be 1)\n");
	if (n == 4)
		ft_printf("Number of Items invalid (must be at least 1)\n");
	if (n == 5)
		ft_printf("Error\nElements are out of bound\n");
	if (n == 6)
		ft_printf("Error\nMap is not a rectangular\n");
	if (n == 7)
		ft_printf("Border aren't the good value\n");
	if (n == 8)
		ft_printf("Invalid characters in map\n");
	close_program(game);
}
