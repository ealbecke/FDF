/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:56:07 by ealbecke          #+#    #+#             */
/*   Updated: 2016/02/11 14:56:09 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_in_img(t_data *fdf, int x, int y, int color)
{
	int		octet;
	int		position;

	octet = fdf->line_size / fdf->width;
	if (y > 0)
		y -= 1;
	position = (fdf->line_size * y) + (x * octet);
	if (ft_memcmp(fdf->ini.data + position, &color, octet) != 0)
		ft_memcpy(fdf->ini.data + position, &color, octet);
}

int		is_in(int bounds_width, int bounds_height, int x, int y)
{
	if (x >= 0 && x < bounds_width && y >= 0 && y < bounds_height)
		return (1);
	return (0);
}

void	draw(t_data *fdf, t_point2d start, t_point2d end, int clr)
{
	t_point2d	delta;
	t_point2d	inc;
	int			e;
	int			ee;

	if (!is_in(fdf->width, fdf->height, start.x, start.y) &&
			!is_in(fdf->width, fdf->height, end.x, end.y))
		return ;
	delta.x = abs(end.x - start.x);
	delta.y = abs(end.y - start.y);
	inc.x = (start.x < end.x) ? 1 : -1;
	inc.y = (start.y < end.y) ? 1 : -1;
	e = (delta.x > delta.y ? delta.x : -delta.y) / 2;
	while (1)
	{
		if (is_in(fdf->width, fdf->height, start.x, start.y))
			put_pixel_in_img(fdf, start.x, start.y, clr);
		if (start.x == end.x && start.y == end.y)
			break ;
		ee = e;
		if (ee > -delta.x && ((start.x += inc.x) || 1))
			e -= delta.y;
		if (ee < delta.y && ((start.y += inc.y) || 1))
			e += delta.x;
	}
}
