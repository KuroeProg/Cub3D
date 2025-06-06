#include "../../includes/cub3d.h"

int	ft_hexconvert(char *nptr)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (i < 2)
	{
		if (nptr[i] <= '9' && nptr[i] >= '0')
			nb = nb * 16 + nptr[i] - 48;
		else if (nptr[i] <= 'F' && nptr[i] >= 'A')
			nb = nb * 16 + nptr[i] - 65 + 10;
		i++;
	}
	return (nb);
}

int ft_convert_color(char *nptr)
{
	int	nb;

	nb = ft_hexconvert(&nptr[4]);
	printf("hexa %c%c : deci %d\n", nptr[4], nptr[5], nb);
	nb += 1000 * ft_hexconvert(&nptr[2]);
	printf("hexa %c%c : deci %d\n", nptr[2], nptr[3], nb);
	nb += 1000000 * ft_hexconvert(&nptr[0]);
	printf("hexa %s : deci %d\n", nptr, nb);
	return (nb);
}

char	ft_get_char(char *line)
{
	return (line[1]);
}

int	ft_get_color(char *line)
{
	int		i;
	char	color[6];
	int		tmp;

	i = 0;
	while (line[i] && line[i] != '#')
		i++;
	if (line[i] == '#')
	{
		i++;
		tmp = i;
		while (line[i] && (i - tmp < 6))
		{
			color[i - tmp] = line[i];
			i++;
		}
	}
	return (ft_convert_color(color));
}

void	ft_tab_color(t_sprit *img, int fd)
{
	char	*line;
	t_conv	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(t_conv *) * img->nb_colors + sizeof(char) * 1);
	(printf("nb_color : %d\n", img->nb_colors));
	tab[img->nb_colors] = NULL;
	while (i < img->nb_colors)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tab[i] = malloc(sizeof(t_conv));
		tab[i]->c = ft_get_char(line);
		tab[i]->color = ft_get_color(line);
		free(line);
		i++;
	}
	img->tab = tab;
}

void	ft_fill_line_color(int *color, t_conv **tab, int size, char *line)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (line[i] && line[i] != '\n')
	{
		j = 0;
		while (j < size)
		{
			if ((*tab[j]).c == line[i])
			{
				color[k] = (*tab[j]).color;
				printf("colonne %d : couleur %d\n", k, color[k]);
				k++;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_fill_img(t_sprit *img, int fd)
{
	char	*line;
	int		i ;

	i = 0;
	line = get_next_line(fd);
	img->color = (int **)malloc(sizeof(int *) * img->height);
	while (line && line[0] != '\"')
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line && line[0] == '\"')
	{
		free(line);
		img->color[i] = (int *)malloc(sizeof(int) * img->width);
		printf("ligne %d : %s\n", i, line);
		ft_fill_line_color(img->color[i], img->tab, img->nb_colors, line);
		i++;
		line = get_next_line(fd);
	}
}

void	display_convert(t_conv **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%c : %d\n", (*tab[i]).c, (*tab[i]).color);
		i++;
	}
}

void	ft_sprite_img(t_sprit *img, char *infos, int fd)
{
	char **stocks;

	stocks = ft_split(infos, ' ');
	img->height = ft_atoi(stocks[0]);
	img->width = ft_atoi(stocks[1]);
	img->nb_colors = ft_atoi(stocks[2]);
	img->sizeof_c = ft_atoi(stocks[3]);
	free_tab(stocks);
	free(infos);
	ft_tab_color(img, fd);
	// display_convert(img->tab, img->nb_colors);
	ft_fill_img(img, fd);
}

int	**get_sprite(char *sprite)
{
	char	*line;
	int		fd;
	int		i;
	t_sprit img;

	i = 0;
	fd = open(sprite, O_RDONLY);
	if (!fd || fd < 0)
		return (0);
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	while (line && line[0] != '\"')
	{
		free(line);
		line = get_next_line(fd);
	}
	ft_sprite_img(&img, line, fd);
	close(fd);
	return (img.color);
}
