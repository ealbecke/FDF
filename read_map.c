/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:21:48 by ealbecke          #+#    #+#             */
/*   Updated: 2016/02/22 14:21:50 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		read_map(char *file, t_data *fdf)
{
	int		***map;
	char	*line;
	char	**line_split;
	int		fd;
	int		i;

	fd = 0;
	i = 0;
	line = NULL;
	map = (int***)malloc(sizeof(int**) * (nbr_row(file) + 1));
	if (map == NULL)
		return ;
	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		line_split = ft_strsplit(line, ' ');
		map[i] = put_in_double_tab(line_split);
		free(line);
		free(line_split);
		i++;
	}
	close(fd);
	map[i] = NULL;
	fdf->map.map = map;
}
