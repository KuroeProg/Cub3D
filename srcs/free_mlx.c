#include "../includes/cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

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
	// if (img->img_path)
	// 	mlx_destroy_image(mlx_connection, img->img_path);
	// if (img->img_wall)
	// 	mlx_destroy_image(mlx_connection, img->img_wall);
}

void	free_game(t_data *game)
{
	free_sprites(&game->img, game->mlx_connection);
	if (game->mlx_window)
	{
		mlx_destroy_window(game->mlx_connection, game->mlx_window);
		game->mlx_window = NULL;
	}
	if (game->mlx_connection)
	{
		mlx_destroy_display(game->mlx_connection);
		free(game->mlx_connection);
		game->mlx_connection = NULL;
	}
	if (game->map)
	{
		free_map(game->map);
		game->map = NULL;
	}
	exit(0);
}
