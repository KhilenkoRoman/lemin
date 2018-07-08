/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 16:49:27 by rkhilenk          #+#    #+#             */
/*   Updated: 2018/07/03 16:49:28 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*find_room(t_storage *s, char *name)
{
	t_room	*tmp;

	tmp = s->rooms_lst;
	while (tmp != NULL)
	{
		if (!ft_strcmp(tmp->name, name))
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

int		room_in_way(char *name, t_storage *s)
{
	t_ways	*tmp;
	t_link	*tmp_link;

	tmp = s->ways_all;
	while (tmp != NULL)
	{
		tmp_link = tmp->way;
		while (tmp_link != NULL)
		{
			if (!ft_strcmp(tmp_link->name, name))
				return (1);
			tmp_link = tmp_link->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

t_ways	*get_next_way(t_storage *s)
{
	t_ways *tmp;
	t_ways *new;

	new = (t_ways *)malloc(sizeof(*new));
	new->way = NULL;
	new->next = NULL;
	if (s->ways_all == NULL)
	{
		s->ways_all = new;
	}
	else
	{
		tmp = s->ways_all;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

void	add_room_lst(t_storage *s, char *name, int x, int y)
{
	t_room	*tmp;
	t_room	*new;

	new = (t_room *)malloc(sizeof(*new));
	new->name = name;
	new->next = NULL;
	new->links = NULL;
	new->start = s->nr_start;
	new->end = s->nr_end;
	new->x = x;
	new->y = y;
	new->visited = 0;
	if (s->rooms_lst == NULL)
		s->rooms_lst = new;
	else
	{
		tmp = s->rooms_lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	add_input_lst(t_storage *s, char *line)
{
	t_input	*tmp;
	t_input	*new;

	new = (t_input *)malloc(sizeof(*new));
	new->text = line;
	new->next = NULL;
	if (s->raw_input_lst == NULL)
	{
		s->raw_input_lst = new;
	}
	else
	{
		tmp = s->raw_input_lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
