/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <ealbecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 13:31:30 by ealbecke          #+#    #+#             */
/*   Updated: 2016/01/11 15:39:03 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 10000000

int		get_next_line(int const fd, char **line);

#endif
