/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:18:34 by rkhilenk          #+#    #+#             */
/*   Updated: 2018/07/04 17:18:35 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// int add_room(t_storage *s, char *line)
// {
// 	char **array;

// 	if (ft_strchr(line, '-'))
// 	{
		
// 	}
// 	array = ft_strsplit(line, ' ');
// 	if (arrlen(array) != 3 || !isnumeric(array[1]) || !isnumeric(array[2]))
// 	{
// 		ft_putstr("wrong room\n");
// 		exit(0);
// 	}
// 	add_room_lst(s, ft_strdup(array[0]), s->nr_start, s->nr_end);
// 	s->nr_start = 0;
// 	s->nr_end = 0;
// 	add_input_lst(s, ft_strdup(line));
// 	free_array(array);
// 	return(1);
// }

void get_links(t_storage *s, char *line)
{
	// add_room(s, line);
	printf("%s\n", line);
	s->argc = s->argc + 1 - 1;
}

