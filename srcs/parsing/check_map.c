/* ************************************************************************** */
/*			                                                                */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahin <tbahin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:45:08 by tbahin            #+#    #+#             */
/*   Updated: 2025/06/25 18:39:45 by tbahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	strlen_path(char *src)
{
	int	i;

	i = 0;
	while (src[i] && src[i] >= 46 && src[i] <= 122)
		i++;
	return (i);
}

int	check_valid_name_tex(char *name)
{
	int	size;

	size = ft_strlen(name);
	if (size < 4 || ft_strcmp(".xpm", &name[size - 4]))
		return (0);
	return (1);
}

char	*strcpy_path(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc((strlen_path(src) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (src[i] && src[i] >= 46 && src[i] <= 122)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	if (!check_valid_name_tex(dest))
		return (NULL);
	return (dest);
}

void	strcpy_cube(char *dest, const char *src, int size)
{
	int	i;

	if (!dest || !src)
		return ;
	i = 0;
	while (i < size && src[i] != '\0' && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	check_header(char *line)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	while (line[i])
	{
		if (!(line[i] == '1' || line[i] == '0'
				|| (line[i] >= 9 && line[i] <= 13) || line[i] == 32))
			return (0);
		else if (line[i] == '1')
			check = 1;
		i++;
	}
	if (check == 0)
		return (0);
	return (1);
}
