/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handler2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 18:31:21 by rkhilenk          #+#    #+#             */
/*   Updated: 2018/07/08 18:31:22 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	add_link_lst(t_link **list, char *name)
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
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	print_link_list(t_link *list)
{
	t_link *tmp;

	tmp = list;
	while (tmp != NULL)
	{
		ft_putstr(tmp->name);
		ft_putstr("\n");
		tmp = tmp->next;
	}
}

void	pop_last_link(t_link **list)
{
	t_link *tmp;
	t_link *prev;

	tmp = *list;
	if (tmp == NULL)
		return ;
	else if (tmp->next == NULL)
	{
		free(*list);
		*list = NULL;
	}
	else
	{
		while (tmp->next != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		free(prev->next);
		prev->next = NULL;
	}
}

void	print_input_list(t_storage *s)
{
	t_input *tmp;

	tmp = s->raw_input_lst;
	while (tmp != NULL)
	{
		ft_putstr(tmp->text);
		ft_putstr("\n");
		tmp = tmp->next;
	}
}

void	unvisit(t_storage *s)
{
	t_room	*tmp;

	tmp = s->rooms_lst;
	while (tmp != NULL)
	{
		tmp->visited = 0;
		tmp = tmp->next;
	}
}
