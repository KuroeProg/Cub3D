#include "../../includes/cub3d.h"

int	ft_hexconvert(char *nptr)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (i < 6)
	{
		if (nptr[i] <= '9' && nptr[i] >= '0')
			nb = nb * 16 + nptr[i] - 48;
		else if (nptr[i] <= 'F' && nptr[i] >= 'A')
			nb = nb * 16 + nptr[i] - 65 + 10;
		i++;
	}
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
		tmp = i;
		while (line[i] && (i - tmp < 6))
		{
			color[i - tmp] = line[i];
			i++;
		}
	}
	return (ft_hexconvert(color));
}

void	ft_tab_color(t_sprit *img, int fd)
{
	char	*line;
	t_conv	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(t_conv *) * img->nb_colors + sizeof(char) * 1);
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

void	ft_fill_line_color(int *color, t_sprit *img, char *line)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (line[i])
	{
		j = 0;
		while (j < img->nb_colors)
		{
			if (img->tab[j]->c == line[i])
			{
				color[k] = img->tab[j]->color;
				k++;
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
		ft_fill_line_color(img->color[i], img, line);
		i++;
		line = get_next_line(fd);
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
