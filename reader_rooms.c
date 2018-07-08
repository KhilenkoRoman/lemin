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

static void check_room_coords(t_storage *s, char *name, int x, int y)
{
	t_room *tmp;

	if (s->rooms_lst == NULL)
		return;
	else
	{
		tmp = s->rooms_lst;
		while(tmp != NULL)
		{
			if (tmp->x == x && tmp->y == y)
				error("wrong room coordinates");
			if (!ft_strcmp(tmp->name, name))
				error("wrong room name");
			if (name[0] == 'L')
				error("no L at start alowed");
			tmp = tmp->next;
		}
	}
}

int add_room(t_storage *s, char *line)
{
	char **array;

	if (ft_strchr(line, '-'))
	{
		get_links(s, line);
		s->step_2 = 1;
		return(1);
	}
	array = ft_strsplit(line, ' ');
	if (arrlen(array) != 3 || !isnumeric(array[1]) || !isnumeric(array[2]) || ft_atoi(array[1]) < 0 ||  ft_atoi(array[2]) < 0)
	{
		ft_putstr("wrong room\n");
		exit(0);
	}
	check_room_coords(s, array[0], ft_atoi(array[1]), ft_atoi(array[2]));
	add_room_lst(s, ft_strdup(array[0]), ft_atoi(array[1]), ft_atoi(array[2]));
	s->nr_start = 0;
	s->nr_end = 0;
	add_input_lst(s, ft_strdup(line));
	free_array(array);
	return(1);
}

void get_room(t_storage *s, char *line)
{
	add_room(s, line);
}
