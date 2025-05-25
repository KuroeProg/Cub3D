#ifndef CUB3D_H
#define CUB3D_H

#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include <fcntl.h> //open()
#include <unistd.h> //close(), read(), write()
#include <stdio.h> //printf(), perror()
#include <string.h> //strerror()
#include <stdlib.h> //malloc(), free(), exit();
#include <math.h> //maths functions (-lm compilation flag)
#include "../.minilibx-linux/mlx.h" // (-lmlx, lX11, -lXext, -lm for compilation)

#define NO [text]
#define SO [text]
#define WE [text]
#define EA [text]
#define C  [int] //couleur ciel
#define F  [int] //couleur plafond
#define CHECK_MAP_TOP \
    data->map[j - 1][i] == '0' && data->map[j - 1][i] == '1' && \
    data->map[j - 1][i] == 'N' && data->map[j - 1][i] == 'E' && \
    data->map[j - 1][i] == 'S' && data->map[j - 1][i] == 'W'
#define CHECK_MAP_DOWN \
    data->map[j + 1][i] == '0' && data->map[j + 1][i] == '1' && \
    data->map[j + 1][i] == 'N' && data->map[j + 1][i] == 'E' && \
    data->map[j + 1][i] == 'S' && data->map[j + 1][i] == 'W'
#define CHECK_MAP_LEFT \
    data->map[j][i - 1] == '0' && data->map[j][i - 1] == '1' && \
    data->map[j][i - 1] == 'N' && data->map[j][i - 1] == 'E' && \
    data->map[j][i - 1] == 'S' && data->map[j][i - 1] == 'W'
#define CHECK_MAP_RIGHT \
    data->map[j][i + 1] == '0' && data->map[j][i + 1] == '1' && \
    data->map[j][i + 1] == 'N' && data->map[j][i + 1] == 'E' && \
    data->map[j][i + 1] == 'S' && data->map[j][i + 1] == 'W'

typedef struct s_img
{
	void	*img_path;
	void	*img_wall;
}				t_img;

typedef struct s_coordonnees
{
	float x; //horizontal
	float y; //vertical
} t_coordonnees;

typedef struct s_mlx
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_mlx;

typedef struct s_data
{
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	int		map_width; //horizontal
	int		map_height; //vertical
	char 	**map;
	int		player_x;
	int		player_y;
	int		dirX; //horizontal
	int		dirY; //vertical
	int		PlaneY;
	int		PlaneX;
	int		i;
	int		j;
} t_data;

/* parsing */
/* check_map.c */
int	malloc_function(t_data *data, char *file_path);
int	get_map_info(t_data *data,char *file_path);
int ft_parsing(t_data *data);
int check_borders(t_data *data, int i, int j);

/*init_data*/
void 	init_data(t_data *data);
t_img	load_sprites(t_data *game);
t_img	xpm_to_img(t_data *game, int width, int height);
void	initialize_img(t_img *img);

/* algo */


/* utils */
int		handle_keypress(int keycode, void *param);
void	display_map(t_data *data);
int		close_program(void *param);

/* free */
void	free_game(t_data *game);
void	free_sprites(t_img *img, void *mlx_connection);
void	free_map(char **map);

/* display_2d */
void	display_line(char *line, t_data *game, t_img *img, int j);
// void	ft_movesprite(char *line, t_data *game, int j, t_img *img);
int		render_frame(t_data *data);

#endif // CUB3D_H