/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 15:49:52 by rkhilenk          #+#    #+#             */
/*   Updated: 2018/07/03 15:49:53 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int get_comment(t_storage *s, char *line)
{
	if (ft_strlen(line) <= 1)
		return (0);
	if (line[0] == '#' && line[1] != '#')
	{
		add_input_lst(s, line);
		return (1);
	}
	return (0);
}

static void get_ants(t_storage *s, char *line)
{
	if (!isnumeric(line))
	{
		ft_putstr("wrong ants number\n");
		exit(0);
	}
	s->ant_nbr = ft_atoi(line);
	if (s->ant_nbr <= 0)
	{
		ft_putstr("wrong ants number\n");
		exit(0);
	}
	else
	{
		add_input_lst(s, ft_itoa(s->ant_nbr));
		s->step_1 = 1;
	}
}

static void parser(t_storage *s)
{
	char *line;

	while (get_next_line(s->fd, &line) && line[0] != 0)
	{
		if (get_comment(s, line))
			continue;
		else if (!s->step_1)
			get_ants(s, line);
		else if (!s->step_2)
			get_room(s, line);
		else if (!s->step_3)
			get_links(s, line);
		// printf("-->%d\n", line[0]);
		free(line);
	}
	printf("--\n");
	print_input_list(s);
	printf("--\n");
	print_room_list(s);
	printf("--\n");

}

void		reader(t_storage *s)
{
	if (s->argc >= 2)
	{
		s->fd = open(s->argv[1], O_RDONLY);
		if (s->fd == -1)
		{
			ft_putstr("wrong input\n");
			exit(0);
		}
	}
	else
		s->fd = 1;
	parser(s);
}


