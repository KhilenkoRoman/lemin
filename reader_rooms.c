/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:01:40 by rkhilenk          #+#    #+#             */
/*   Updated: 2018/07/03 19:01:42 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int room_validator(char *line)
{
	char **array;

	array = ft_strsplit(line, ' ');
	if (arrlen(array) != 3)
	{
		ft_putstr("wrong room\n");
		exit(0);
	}

	// to fo free list 

	return(1);
}

void get_room(t_storage *s, char *line)
{
	room_validator(line);
	s->argc = s->argc + 1 - 1;
}
