#ifndef CUB3D_H
#define CUB3D_H

#include <fcntl.h> //open()
#include <unistd.h> //close(), read(), write()
#include <stdio.h> //printf(), perror()
#include <string.h> //strerror()
#include <stdlib.h> //malloc(), free(), exit();
#include <math.h> //maths functions (-lm compilation flag)

#define NO [text]
#define SO [text]
#define WE [text]
#define EA [text]
#define C  [int] //couleur ciel
#define F  [int] //couleur plafond

#include ".minilibx-linux" // (-lmlx, lX11, -lXext, -lm for compilation)

typedef struct s_data
{
	int		map_width; //horizontal
	int		map_height; //vertical
	char 	**map;
	int		dirX; //horizontal
	int		dirY; //vertical
	int		PlaneY;
	int		PlaneY;
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


/* algo */




#endif // CUB3D_H