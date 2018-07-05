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

static void	link_add2(t_link **alst, t_link *new)
{
	new->next = *alst;
	*alst = new;
}

static t_link *link_create(char *name)
{
	t_link *new_link;

	new_link = (t_link *)malloc(sizeof(*new_link));
	new_link->name = ft_strdup(name);
	new_link->next = NULL;
	return(new_link);
}

static void	link_add(t_storage *s, char *to, char *link)
{
	t_room *tmp;
	t_link *ltmp;

	tmp = s->rooms_lst;
	while (tmp != NULL)
	{
		if(!ft_strcmp(tmp->name, to))
		{
			ltmp = link_create(link);
			link_add2(&tmp->links, ltmp);
			return;
		}
		tmp = tmp->next;
	}
}

static void links_exist_valid(t_storage *s, char *room1, char *room2)
{
	t_room *tmp;
	int f1;
	int f2;

	f1 = 0;
	f2 = 0;
	tmp = s->rooms_lst;
	while (tmp != NULL)
	{
		if(!ft_strcmp(tmp->name, room1))
			f1 = 1;
		if(!ft_strcmp(tmp->name, room2))
			f2 = 1;
		tmp = tmp->next;
	}
	if (f1 == 0 || f2 == 0)
	{
		ft_putstr("wrong link room not exist\n");
		exit(0);
	}
}

void get_links(t_storage *s, char *line)
{
	char **array;

	if (!ft_strchr(line, '-'))
	{
		ft_putstr("wrong link\n");
		exit(0);
	}
	array = ft_strsplit(line, '-');
	if (arrlen(array) != 2)
	{
		ft_putstr("wrong link\n");
		exit(0);
	}
	links_exist_valid(s, array[0], array[1]);
	link_add(s, array[0], array[1]);
	link_add(s, array[1], array[0]);
	add_input_lst(s, ft_strdup(line));
	free_array(array);
}


