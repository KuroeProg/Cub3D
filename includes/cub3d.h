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

#define NO 0
#define SO 1
#define WE 2
#define EA 3
#define C  [int] //couleur ciel
#define F  [int] //couleur plafond

# define TEX_WIDTH 32
# define TEX_HEIGHT 32
# define TEX_COUNT 4

# define W 0x0077
# define D 0x0064
# define S 0x0073
# define A 0x0061

#define CHECK_MAP_TOP \
    (data->map[j - 1][i] == '0' || data->map[j - 1][i] == '1' || \
     data->map[j - 1][i] == 'N' || data->map[j - 1][i] == 'E' || \
     data->map[j - 1][i] == 'S' || data->map[j - 1][i] == 'W')
#define CHECK_MAP_DOWN \
    (data->map[j + 1][i] == '0' || data->map[j + 1][i] == '1' || \
     data->map[j + 1][i] == 'N' || data->map[j + 1][i] == 'E' || \
     data->map[j + 1][i] == 'S' || data->map[j + 1][i] == 'W')
#define CHECK_MAP_LEFT \
    (data->map[j][i - 1] == '0' || data->map[j][i - 1] == '1' || \
     data->map[j][i - 1] == 'N' || data->map[j][i - 1] == 'E' || \
     data->map[j][i - 1] == 'S' || data->map[j][i - 1] == 'W')
#define CHECK_MAP_RIGHT \
    (data->map[j][i + 1] == '0' || data->map[j][i + 1] == '1' || \
     data->map[j][i + 1] == 'N' || data->map[j][i + 1] == 'E' || \
     data->map[j][i + 1] == 'S' || data->map[j][i + 1] == 'W')

typedef	struct  s_conv
{
	char 	c;
	int		color;
}				t_conv;

typedef struct s_dda
{
    int		map_x;
    int		map_y;
    double	side_x;
    double	side_y;
    double	delta_x;
    double	delta_y;
    int		step_x;
    int		step_y;
    int		hit;
    int		side;
    double	ray_dir_x;
    double	ray_dir_y;
    int		tex_num;
}	t_dda;

typedef struct s_sprit
{
	int	**color;      // <--- Cette variable sert à stocker les couleurs (pixels) d'un sprite custom, PAS pour les textures minilibx classiques.
	int	width;
	int	height;
	t_conv	**tab;
	int	nb_colors;
	int	sizeof_c;
}				t_sprit;

typedef struct s_img
{
	char	*path_S;   // path texture sud
	char	*path_W;   // path texture ouest
	char	*path_E;   // path texture est
	char	*path_N;   // path texture nord
	int		c_color;
	int		f_color;
}				t_img;

typedef struct s_coordonnees
{
	float x; //horizontal
	float y; //vertical
} t_co;

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
    t_mlx	img_mlx;
    int		screen_width;
    int		screen_height;
    char	**map;
    double	player_x;
    double	player_y;
    double	dir_x;
    double	dir_y;
    double	plane_x;
    double	plane_y;
    int     *texture[4];
    int		map_width;
    int		map_height;
    int		player_start_x;
    int		player_start_y;
    int		i;
    int		j;
    t_img	img;
	t_dda   *dda;
}	t_data;

/* parsing */
/* check_map.c */
int	malloc_function(t_data *data, char *file_path);
int	get_map_info(t_data *data,char *file_path);
int ft_parsing(t_data *data);
int check_borders(t_data *data, int i, int j);

/*init_data*/
void 	init_data(t_data *data);
void	init_player(t_data *data, char c, int x, int y);
// t_img	xpm_to_img(t_data *game);
void	initialize_img(t_img *img);
/* algo */


/* utils */
int		handle_keypress(int keycode, void *param);
// void	display_map(t_data *data);
int		close_program(void *param);

/* free */
void	free_game(t_data *game);
void	free_sprites(t_img *img, void *mlx_connection);
void	free_map(char **map);
void	free_tab(char **tab);

/* display_2d */
// void	display_line(char *line, t_mlx *game, t_img *img, int j);
// void	ft_movesprite(char *line, t_data *game, int j, t_img *img);
int		render_frame(t_data *data);
// int		**get_sprite(char *sprite);
// void	display_map_color(int **data);

/* draw */
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
void	ft_reset_img(t_data *img);
void	ft_mlx_put_image(t_data *data, int color, int color2);
void	ft_draw(t_mlx *img, int x, int y, int color);

/*new functions*/
void	init_dda(t_dda *d, double pos_x, double pos_y, double dir_x, double dir_y);
void	perform_dda(t_data *data, t_dda *d);
void	raycast_scene(t_data *data);
void	draw_vertical_line(t_data *data, int x, double perp_wall_dist, t_dda *d);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
void	load_textures(t_data *game);

#endif // CUB3D_H