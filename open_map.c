/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 14:49:55 by ealbecke          #+#    #+#             */
/*   Updated: 2016/01/28 14:49:58 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			nbr_case(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int			*cast_value(int value)
{
	int		*i;

	if (!(i = (int*)malloc(sizeof(int))))
		exit(EXIT_FAILURE);
	*i = value;
	return (i);
}

int			**put_in_double_tab(char **tbl)
{
	int		**new_tbl;
	int		i;
	int		len;

	i = 0;
	len = nbr_case(tbl);
	new_tbl = (int**)malloc(sizeof(int*) * (len + 1));
	if (new_tbl == NULL)
		exit(EXIT_FAILURE);
	while (tbl[i])
	{
		new_tbl[i] = cast_value(ft_atoi(tbl[i]));
		i++;
	}
	new_tbl[i] = NULL;
	return (new_tbl);
}

int			nbr_row(char *file)
{
	int		i;
	int		fd;
	char	*line;

	fd = 0;
	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		i++;
	}
	close(fd);
	return (i);
}
