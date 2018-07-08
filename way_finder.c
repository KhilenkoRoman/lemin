/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_finder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:08:57 by rkhilenk          #+#    #+#             */
/*   Updated: 2018/07/06 12:08:59 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void starter(t_storage *s)
{
	t_room *tmp;
	t_room *start;

	if (s->rooms_lst->start == 1)
		return;
	tmp = s->rooms_lst;
	while(tmp != NULL && tmp->next != NULL)
	{
		if (tmp->next->start == 1)
		{
			start = tmp->next;
			tmp->next = start->next;
		}
		tmp = tmp->next;
	}
	tmp = s->rooms_lst;
	s->rooms_lst = start;
	s->rooms_lst->next = tmp;
}

static void ender(t_storage *s)
{
	t_room *tmp;
	t_room *end;

	tmp = s->rooms_lst;
	if (tmp->end == 1)
	{
		end = tmp;
		s->rooms_lst = tmp->next;
		tmp = s->rooms_lst;
	}
	while(tmp->next != NULL)
	{
		if (tmp->next->end == 1)
		{
			end = tmp->next;
			tmp->next = end->next;
		}
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}
	end->next = NULL;
	tmp->next = end;
}

static void unvisit(t_storage *s)
{
	t_room	*tmp;

	tmp = s->rooms_lst;
	while (tmp != NULL)
	{
		tmp->visited = 0;
		tmp = tmp->next;
	}
}

static int step(t_room *room, t_storage *s, int count, t_link **way)
{
	t_link *links;

	if (room->end == 1)
	{
		add_link_lst(way, room->name);
		return (1);
	}
	if (room->visited == 1 || count > s->gc || (room_in_way(room->name, s) == 1 && room->start != 1))
		return (0);
	add_link_lst(way, room->name);
	links = room->links;
	room->visited = 1;
	while (links != NULL)
	{
		if (step(find_room(s, links->name), s, count + 1, way) == 1)
			return (1);
		links = links->next;
	}
	pop_last_link(way);
	return(0);
}

static void finder(t_storage *s)
{
	int		res;
	t_ways	*cur_way;

	res = 1;
	while (res == 1)
	{
		s->gc = 1;
		cur_way = get_next_way(s);
		while (s->gc <= s->room_nbr)
		{
			res = step(s->rooms_lst, s, 1, &cur_way->way);
			if (res == 1)
				break;
			unvisit(s);
			free(cur_way->way);
			cur_way->way = NULL;
			s->gc++;		
		}
		if (res == 0)
			break;
	}
}

void way_finder(t_storage *s)
{
	starter(s);
	ender(s);
	room_count(s);
	finder(s);
	if (s->ways_all->way == NULL)
		error("no way out");
}
