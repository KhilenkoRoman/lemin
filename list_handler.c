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

void add_input_lst(t_storage *s, char *line)
{
	t_input *tmp;
	t_input *new;

	new = (t_input *)malloc(sizeof(*new));
	new->text = line;
	new->next = NULL;
	if (s->raw_input_lst == NULL)
	{
		printf("new\n");
		s->raw_input_lst = new;
	}
	else
	{
		printf("next\n");
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
		printf(">raw_inp>%s\n", tmp->text);
		tmp = tmp->next;
	}
}