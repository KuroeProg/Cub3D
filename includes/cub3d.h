/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:44:47 by tbahin            #+#    #+#             */
/*   Updated: 2025/07/01 10:41:03 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h> 
# include <math.h> 
# include "../.minilibx-linux/mlx.h"

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define DOOR 4

# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define TEX_COUNT 5
# define SCREEN_HEIGHT 2140 
# define SCREEN_WIDTH 3860
# define ANIME_SPEED 20

# define SZC 20
# define MM_X 0
# define MM_Y 0
# define MLX mlx_xpm_file_to_image
# define PT_TEXT ptr_texture

# define W 0x0077
# define D 0x0064
# define S 0x0073
# define A 0x0061
# define Q 0x0071
# define E 0x0065
# define F 0x0066
# define C 0x0063
# define PI 3.1415

typedef struct s_draw_line
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		y;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step ;
	double	tex_pos;
	int		color;
}					t_dwl;

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
	int		door;
}	t_dda;

typedef struct s_img
{
	char	*path_s;
	char	*path_w;
	char	*path_e;
	char	*path_n;
	int		c_color;
	int		f_color;
}				t_img;

typedef struct s_mlx
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;

typedef struct s_next_frame
{
	int		x;
	int		y;
	char	etat;
	int		count;
}			t_nx_f;

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
	float	rad;
	double	plane_x;
	double	plane_y;
	void	*ptr_texture[5][12];
	int		*texture[5][12];
	int		map_width;
	int		map_height;
	int		i;
	int		j;
	int		prev_x;
	float	rotation_speed;
	char	*draw;
	t_img	img;
	t_dda	*dda;
	int		check_door;
	int		x_door;
	int		y_door;
	int		check_animation;
	int		move_speed;
	int		count_frame_speed;
	char	*start_minimap;
	t_nx_f	*door;
	t_nx_f	*tex_s;
	t_nx_f	*tex_e;
	int		squale_map;
	float	cor_map_x;
	float	cor_map_y;
	int		valid_size_map;
	char	keys[256];
}	t_data;

/* parsing */
/* check_map.c */
int		malloc_function(t_data *data, char *file_path);
int		get_map_info(t_data *data, char *file_path);
int		ft_parsing(t_data *data);
int		check_borders(t_data *data, int i, int j);
int		malloc_function(t_data *data, char *file_path);
int		invalid_line(char *line);
void	strcpy_cube(char *dest, const char *src, int size);
int		fill_path_text(char *line, t_data *da);

/*init_data*/
void	init_data(t_data *data);
void	init_player(t_data *data, char c, int x, int y);

/* utils */
int		handle_keypress(int keycode, void *param);
// void	display_map(t_data *data);
int		close_program(void *param);

/* free */
void	free_game(t_data *game);
// void	free_sprites(t_data *data);
void	free_map(char **map);
void	free_data(t_data *data);
void	free_sprites(t_data *data);
/* display_2d */
// void	display_line(char *line, t_mlx *game, t_img *img, int j);
// void	ft_movesprite(char *line, t_data *game, int j, t_img *img);
int		render_frame(t_data *data);
void	move_player(t_data *data, int move);
int		mouse_move(int x, int y, t_data *data);
void	cam_player(t_data *data, int cam);
void	open_door(t_data *data);
// int		**get_sprite(char *sprite);
// void	display_map_color(int **data);

/* draw */
// void	ft_mlx_put_image(t_data *data, int color, int color2);
void	draw_pixel(t_mlx *img_mlx, char *ptr, int color, int y);
void	display_player(t_data *data, int color, double x, double y);

/*new functions*/
void	init_dda(t_dda *d, double pos_x, double pos_y);
void	perform_dda(t_data *data, t_dda *d);
void	raycast_scene(t_data *data);
void	draw_vertical_line(t_data *data, double perp_wall_dist, t_dda *d);
void	load_textures(t_data *game);

/*minimap*/
void	print_block(t_data *data, int color, int x, int y);
int		*void_to_int(t_data *data, void *ptr, void **tab_ptr);
char	*strcpy_path(char *src);
int		check_header(char *line);
int		check_space(char *line);
int		invalid_line(char *line);
int		handle_map_char(t_data *d, int i, int j, int *count);
int		check_door(t_data *d, int i, int j);

#endif // CUB3D_H