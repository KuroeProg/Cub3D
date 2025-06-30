/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:16:47 by cfiachet          #+#    #+#             */
/*   Updated: 2025/06/30 17:51:44 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	conv_color(int r, int g, int b)
{
	int	color;

	color = (r << 16) | (g << 8) | b;
	return (color);
}

int	get_color(int *color, char *str)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 0;
	r = ft_atoi(str);
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	g = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	b = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] && str[i] != '\n')
		return (0);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (0);
	*color = conv_color(r, g, b);
	return (1);
}

int	check_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
		i++;
	if (line[i])
		return (0);
	return (1);
}

int	fill_path_text(char *line, t_data *da)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ' && da->i == 0)
		return (da->img.path_n = strcpy_path(&line[3]), da->i++, 1);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ' && da->i == 1)
		return (da->img.path_s = strcpy_path(&line[3]), da->i++, 1);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ' && da->i == 2)
		return (da->img.path_w = strcpy_path(&line[3]), da->i++, 1);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ' && da->i == 3)
		return (da->img.path_e = strcpy_path(&line[3]), da->i++, 1);
	else if (line[0] == 'F' && line[1] == ' ' && da->i == 4)
	{
		if (!get_color(&da->img.f_color, &line[2]))
			return (printf("error floor color\n"), 0);
		return (da->i++, 1);
	}
	else if (line[0] == 'C' && line[1] == ' ' && da->i == 5)
	{
		if (!get_color(&da->img.c_color, &line[2]))
			return (printf("error ciel color\n"), 0);
		return (da->i++, 1);
	}
	return (0);
}
