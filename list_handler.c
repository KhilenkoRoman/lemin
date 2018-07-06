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

t_room *find_room(t_storage *s, char *name)
{
	t_room *tmp;

	tmp = s->rooms_lst;
	while(tmp != NULL)
	{
		if(!ft_strcmp(tmp->name, name))
			return (tmp);
		tmp = tmp->next;
	}
	return(tmp);
}

void add_room_lst(t_storage *s, char *name, int x, int y)
{
	t_room *tmp;
	t_room *new;

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
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void add_input_lst(t_storage *s, char *line)
{
	t_input *tmp;
	t_input *new;

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
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void print_input_list(t_storage *s)
{
	t_input *tmp;

	tmp = s->raw_input_lst;
	while(tmp != NULL)
	{
		ft_putstr(tmp->text);
		ft_putstr("\n");
		tmp = tmp->next;
	}
}

void print_room_list(t_storage *s)
{
	t_room *tmp;
	t_link *link;

	tmp = s->rooms_lst;
	while(tmp != NULL)
	{
		printf("room-->%s", tmp->name);
		printf(" x=%d y=%d start=%d end=%d visited = %d\n", tmp->x, tmp->y, tmp->start, tmp->end, tmp->visited);
		link = tmp->links;
		while (link != NULL)
		{
			printf("__link_name--> %s\n", link->name);
			link = link->next;
		}
		printf("\n");
		tmp = tmp->next;
	}
}

void add_link_lst(t_link **list, char *name)
{
	t_link *tmp;
	t_link *new;

	new = (t_link *)malloc(sizeof(*new));
	new->name = name;
	new->next = NULL;
	if (*list == NULL)
		*list = new;
	else
	{
		tmp = *list;
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void print_link_list(t_link *list)
{
	t_link *tmp;

	tmp = list;
	while(tmp != NULL)
	{
		ft_putstr(tmp->name);
		ft_putstr("\n");
		tmp = tmp->next;
	}
}

void pop_last_link(t_link **list)
{
	t_link *tmp;
	t_link *prev;

	tmp = *list;
	if (tmp == NULL)
		return;
	else if(tmp->next == NULL)
	{
		free(*list);
		*list = NULL;
	}
	else
	{
		while(tmp->next != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		free(prev->next);
		prev->next = NULL;
	}
}