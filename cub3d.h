#ifndef CUB3D_H
#define CUB3D_H

#include <fcntl.h> //open()
#include <unistd.h> //close(), read(), write()
#include <stdio.h> //printf(), perror()
#include <string.h> //strerror()
#include <stdlib.h> //malloc(), free(), exit();
#include <math.h> //maths functions (-lm compilation flag)
#include ".minilibx-linux/mlx.h" // (-lmlx, lX11, -lXext, -lm for compilation)

#define NO [text]
#define SO [text]
#define WE [text]
#define EA [text]
#define C  [int] //couleur ciel
#define F  [int] //couleur plafond
#define CHECK_MAP_TOP \
    data->map[j - 1][i] != '0' && data->map[j - 1][i] != '1' && \
    data->map[j - 1][i] != 'N' && data->map[j - 1][i] != 'E' && \
    data->map[j - 1][i] != 'S' && data->map[j - 1][i] != 'W' && \
    data->map[j - 1][i] != ' '
#define CHECK_MAP_DOWN \
    data->map[j + 1][i] != '0' && data->map[j + 1][i] != '1' && \
    data->map[j + 1][i] != 'N' && data->map[j + 1][i] != 'E' && \
    data->map[j + 1][i] != 'S' && data->map[j + 1][i] != 'W' && \
    data->map[j + 1][i] != ' '
#define CHECK_MAP_LEFT \
    data->map[j][i - 1] != '0' && data->map[j][i - 1] != '1' && \
    data->map[j][i - 1] != 'N' && data->map[j][i - 1] != 'E' && \
    data->map[j][i - 1] != 'S' && data->map[j][i - 1] != 'W' && \
    data->map[j][i - 1] != ' '
#define CHECK_MAP_RIGHT \
    data->map[j][i + 1] != '0' && data->map[j][i + 1] != '1' && \
    data->map[j][i + 1] != 'N' && data->map[j][i + 1] != 'E' && \
    data->map[j][i + 1] != 'S' && data->map[j][i + 1] != 'W' && \
    data->map[j][i + 1] != ' '


typedef struct s_data
{
	int		map_width; //horizontal
	int		map_height; //vertical
	char 	**map;
	int		dirX; //horizontal
	int		dirY; //vertical
	int		PlaneY;
	int		PlaneX;
	int		i;
	int		j;
} t_data;

typedef struct s_coordonnees
{
	float x; //horizontal
	float y; //vertical
} t_coordonnees;

typedef struct s_mlx
{
	//a completer
} t_mlx;

/* parsing */
/* check_map.c */
int	malloc_function(t_data *data);
int	get_map_info(char *file_path, t_data *data);
int ft_parsing(t_data *data);
int check_borders(t_data *data, int i, int j);

/*init_data*/
int init_data(t_data *data, char *file_path);



/* algo */


/* utils */

#endif // CUB3D_H