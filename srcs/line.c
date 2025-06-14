/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahin <tbahin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:20:28 by tbahin            #+#    #+#             */
/*   Updated: 2025/06/13 03:22:50 by tbahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_line_down(t_data *img, t_co point0, t_co point1)
{
	int	dx;
	int	dy;
	int	d;

	dx = point1.x - point0.x;
	dy = point1.y - point0.y;
	d = (2 * dy) - dx;
	if (dy < 0)
		dy = -dy;
	while (point0.x < point1.x)
	{
		ft_draw(img, (int)point0.x, (int)point0.y, 0xFF0000);
		if (d > 0)
		{
			if (point1.y - point0.y < 0)
				point0.y -= 1;
			else
				point0.y += 1;
			d += (2 * (dy - dx));
		}
		else
			d += 2 * dy;
		point0.x += 1;
	}
}

void	ft_line_up(t_data *img, t_co point0, t_co point1)
{
	int	dx;
	int	dy;
	int	d;

	dx = point1.x - point0.x;
	dy = point1.y - point0.y;
	d = (2 * dx) - dy;
	if (dx < 0)
		dx = -dx;
	while (point0.y < point1.y)
	{
		ft_draw(img, (int)point0.x, (int)point0.y, 0xFF0000);
		if (d > 0)
		{
			if (point1.x - point0.x < 0)
				point0.x -= 1;
			else
				point0.x += 1;
			d += (2 * (dx - dy));
		}
		else
			d += 2 * dx;
		point0.y += 1;
	}
}

void	ft_line(t_data *img, t_co point0, t_co point1)
{
	if (fabs(point1.y - point0.y) < fabs(point1.x - point0.x))
		ft_line_down(img, point0, point1);
	else
		ft_line_up(img, point0, point1);
}
