/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 15:00:07 by ealbecke          #+#    #+#             */
/*   Updated: 2016/02/22 15:00:26 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_key_funct(int keycode, t_data *fdf)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 69)
		fdf->map.scale += ZOOMSTEP;
	else if (keycode == 78 && fdf->map.scale - ZOOMSTEP > 0)
		fdf->map.scale -= ZOOMSTEP;
	else if (keycode == KEYCODE_DEPTHUP)
		fdf->map.depth += DEPTHSTEP;
	else if (keycode == KEYCODE_DEPTHDOWN)
		fdf->map.depth -= DEPTHSTEP;
	else if (keycode == KEYCODE_MOVEUP)
		fdf->map.offset.y += MOVESTEP;
	else if (keycode == KEYCODE_MOVEDOWN)
		fdf->map.offset.y -= MOVESTEP;
	else if (keycode == KEYCODE_MOVELEFT)
		fdf->map.offset.x -= MOVESTEP;
	else if (keycode == KEYCODE_MOVERIGHT)
		fdf->map.offset.x += MOVESTEP;
	draw_map(fdf);
	return (0);
}

int		my_mouse_funct(int mousecode, int x, int y, t_data *fdf)
{
	if (mousecode == KEYCODE_CLICK)
	{
		fdf->map.offset.x = x;
		fdf->map.offset.y = y;
	}
	draw_map(fdf);
	return (0);
}
