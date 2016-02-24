/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 14:51:20 by ealbecke          #+#    #+#             */
/*   Updated: 2016/01/28 14:51:23 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check_arg(int ac, char **av)
{
	int		fd;

	fd = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd <= 0)
		{
			ft_putendl_fd("Problem with File", 2);
			exit(EXIT_FAILURE);
		}
		else
		{
			close(fd);
			return (fd);
		}
	}
	else if (ac > 2 || ac < 2)
	{
		close(fd);
		ft_putendl_fd("Problem with the number of arguments", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
