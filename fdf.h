/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 12:23:01 by ealbecke          #+#    #+#             */
/*   Updated: 2016/02/03 16:49:56 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "libft/includes/libft.h"
# include "get_next_line.h"

# define WIN_WIDTH 1900
# define WIN_HEIGHT 1100
# define RAD(x) (x * M_PI / 180)
# define DEG(x) (x * 180 / M_PI)
# define KEYCODE_ESC 53
# define KEYCODE_ZOOMIN 69
# define KEYCODE_ZOOMOUT 78
# define KEYCODE_DEPTHUP 116
# define KEYCODE_DEPTHDOWN 121
# define KEYCODE_MOVEUP 125
# define KEYCODE_MOVERIGHT 124
# define KEYCODE_MOVEDOWN 126
# define KEYCODE_MOVELEFT 123
# define KEYCODE_CLICK 1
# define MOVESTEP 32
# define ZOOMSTEP 4
# define DEPTHSTEP 0.1

typedef struct		s_point2d
{
	int			x;
	int			y;
}					t_point2d;

typedef struct		s_ini
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
}					t_ini;

typedef struct		s_param
{
	void		*mse;
	void		*kybrd;
}					t_param;

typedef struct		s_map
{
	int			***map;
	int			scale;
	float		depth;
	int			alpha;
	int			beta;
	t_point2d	offset;
}					t_map;

typedef struct		s_data
{
	int			bpp;
	int			line_size;
	int			endian;
	int			width;
	int			height;
	t_map		map;
	t_param		param;
	t_ini		ini;
}					t_data;

void				read_map(char *file, t_data *fdf);
void				put_pixel_in_img(t_data *fdf, int x, int y, int color);
int					is_in(int bounds_width, int bounds_height, int x, int y);
void				draw(t_data *fdf, t_point2d start, t_point2d end, int clr);
t_point2d			put_point_in_map_iso(t_data *fdf, int x, int y, int z);
int					is_upper_point(int ***map, int x, int y);
void				buff_image(t_data *fdf);
int					draw_map(t_data *fdf);
int					my_mouse_funct(int mousecode, int x, int y, t_data *fdf);
int					my_key_funct(int keycode, t_data *fdf);
int					ft_check_arg(int ac, char **av);
void				manage_mlx(t_data *fdf);
int					nbr_case(char **str);
int					*cast_value(int value);
int					**put_in_double_tab(char **tbl);
int					nbr_row(char *file);
void				error_nbr_arg(void);

#endif
