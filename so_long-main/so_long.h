/* ************************************************************************** */
/*													                      */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:49:45 by cfiachet          #+#    #+#             */
/*   Updated: 2024/12/26 15:40:59 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include ".minilibx-linux/mlx.h"
# include <stdlib.h>
# include "utils/gnl/get_next_line.h"
# include "utils/ft_printf/ft_printf.h"

# define WIDTH 1000
# define HEIGHT 600

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_img
{
	void	*img_path;
	void	*img_wall;
	void	*img_player;
	void	*img_item;
	void	*img_exit;
}				t_img;

typedef struct s_game
{
	void	*mlx_connection;
	void	*mlx_window;
	char	**map;
	t_img	img;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collected_items;
	int		total_items;
	int		player_start_x;
	int		player_start_y;
	int		move_count;
	int		is_updated;
	int		i;
	int		j;
}			t_game;

typedef struct check
{
	int		check_exit;
	int		check_player;
	int		check_item;
}			t_check;

int		main(int argc, char **argv);
int		close_program(void *param);
void	ft_parsing(char *file_path, t_game *game);
void	display_line(char *line, t_game *game, t_img *img, int j);
int		handle_keypress(int keycode, void *param);
int		ft_sprites_manage(void *mlx);
int		handle_destroy(void *param);
int		move_player(t_game *game, int direction);
int		check_exit(t_game *game);
void	collect_item(t_game *game);
void	handle_player_action(t_game *game, int x, int y);
void	initialize_player(t_game *game, int start_x, int start_y);
t_img	load_sprites(t_game *game);
void	ft_movesprite(char *line, t_game *game, int j, t_img *img);
void	free_sprites(t_img *img, void *mlx_connection);
int		ftff_strlen(char *str);
int		render_frame(t_game *game);
void	initialize_game(t_game *game);
void	is_conform(t_game *game);
void	ft_error(int n, t_game *game);
void	initialize_check(t_check *check);
void	is_rectangular(t_game *game);
int		nl_strlen(char *str);
void	ft_checkerror(t_check *check, t_game *game);
void	free_map(char **map);
void	initialize_img(t_img *img);
void	free_game(t_game *game);
void	free_map_copy(char **map_copy, int map_height);
void	ft_flood_fill(char **map, t_game *game, int i, int j);
void	ft_check_free(int k, int l, t_game *game, char **map_copy);
void	display_information(t_check	*check);
void	free_fd(t_game *game);
void	ft_extrct_line(t_game *game, char *line, int fd);
t_img	xpm_to_img(t_game *game, int width, int height);
void	free_fd_bis(int fd, t_game *game);
void	ft_check_free2(int k, int l, t_game *game, char **map_copy);

#endif