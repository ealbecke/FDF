/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_part.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 10:36:20 by ealbecke          #+#    #+#             */
/*   Updated: 2016/02/22 15:02:24 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point2d	put_point_in_map_iso(t_data *fdf, int x, int y, int z)
{
	t_point2d	ptn;

	ptn.x = fdf->map.scale * (x * cos(RAD(fdf->map.alpha)) - y *
			cos(RAD(fdf->map.beta)));
	ptn.y = (-fdf->map.scale) * ((z * fdf->map.depth) - x *
			sin(RAD(fdf->map.alpha)) - y * sin(RAD(fdf->map.beta)));
	ptn.x += fdf->map.offset.x;
	ptn.y += fdf->map.offset.y;
	return (ptn);
}

int			is_upper_point(int ***map, int x, int y)
{
	int		i;

	if (y > 0)
	{
		i = 0;
		while (map[y - 1][i])
			i++;
		if (i > x)
			return (1);
	}
	return (0);
}

void			buff_image(t_data *fdf)
{
	int		x;
	int		y;
	int		color;

	color = 0x23b129;
	y = 0;
	while (fdf->map.map[y])
	{
		x = 0;
		while (fdf->map.map[y][x])
		{
			if (fdf->map.map[y][x + 1])
				draw(fdf, put_point_in_map_iso(fdf, x, y,
							fdf->map.map[y][x][0]), put_point_in_map_iso(fdf,
								x + 1, y, fdf->map.map[y][x + 1][0]), color);
			if (is_upper_point(fdf->map.map, x, y))
				draw(fdf, put_point_in_map_iso(fdf, x, y,
							fdf->map.map[y][x][0]), put_point_in_map_iso(fdf,
								x, y - 1, fdf->map.map[y - 1][x][0]), color);
			x++;
			color++;
		}
		y++;
	}
}

int					draw_map(t_data *fdf)
{
	ft_bzero(fdf->ini.data, fdf->line_size * WIN_HEIGHT);
	buff_image(fdf);
	mlx_put_image_to_window(fdf->ini.mlx, fdf->ini.win, fdf->ini.img, 0, 0);
	return (0);
}

void				manage_mlx(t_data *fdf)
{
	int		x;

	x = 0;
	fdf->map.alpha = 30;
	fdf->map.beta = 30;
	fdf->map.scale = 32;
	fdf->map.depth = 0.1;
	fdf->map.offset.x = WIN_WIDTH / 2;
	fdf->map.offset.y = WIN_HEIGHT / 8;
	fdf->ini.mlx = mlx_init();
	fdf->ini.win = mlx_new_window(fdf->ini.mlx, WIN_WIDTH, WIN_HEIGHT, "42");
	fdf->width = WIN_WIDTH;
	fdf->height = WIN_HEIGHT;
	fdf->ini.img = mlx_new_image(fdf->ini.mlx, WIN_WIDTH, WIN_HEIGHT);
	fdf->ini.data = mlx_get_data_addr(fdf->ini.img, &fdf->bpp,
			&fdf->line_size, &fdf->endian);
	mlx_expose_hook(fdf->ini.win, draw_map, fdf);
	mlx_key_hook(fdf->ini.win, my_key_funct, fdf);
	mlx_mouse_hook(fdf->ini.win, my_mouse_funct, fdf);
	mlx_loop(fdf->ini.mlx);
}
