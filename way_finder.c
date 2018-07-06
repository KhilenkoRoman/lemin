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

void way_finder(t_storage *s)
{
	starter(s);
	ender(s);
	print_room_list(s);
}
