/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 17:01:49 by rkhilenk          #+#    #+#             */
/*   Updated: 2018/07/06 17:01:51 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// static void ant_move(t_storage *s, t_ways *way)
// {
// 	int i;

// 	i = way_len - 1;
// 	while (i >= 0)
// 	{
// 		if (i == way_len - 1)
// 		{
// 			if (antray[i] != 0)
// 				s->ant_reach++;
// 			antray[i] = antray[i - 1];
// 		}
// 		else if(i == 0 && s->ant_start > 0)
// 		{
// 			antray[i] = s->ant_nbr - s->ant_start + 1;
// 			s->ant_start--;
// 		}
// 		else if(i > 0 && i < way_len - 1)
// 			antray[i] = antray[i - 1];
// 		else if(i == 0 && s->ant_start == 0)
// 			antray[i] = 0;
// 		i--;
// 	}
// 	return(antray);
// }

char *get_room_name(t_link *way, int index)
{
	int		i;
	t_link	*tmp;

	i = 0;
	tmp = way;
	while (tmp != NULL && i < index)
	{
		tmp = tmp->next;
		i++;
	}
	return(tmp->name);
}


// static void ant_print(t_ways *way)
// {
// 	int i;

// 	i = 1;
// 	while (i < way->len)
// 	{
// 		printf(" [%2d] ", way->antray[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

static void ant_print(t_ways *way)
{
	int i;

	i = 1;
	while (i < way->len)
	{
		if (way->antray[i] > 0)
		{
			ft_putstr("L");
			ft_putnbr(way->antray[i]);
			ft_putstr("-");
			ft_putstr(get_room_name(way->way, i));
			ft_putstr(" ");
		}
		i++;
	}
}

static void ant_move(t_storage *s, t_ways *way)
{
	int i;

	i = way->len - 1;
	while (i >= 0)
	{
		if (i == way->len - 1)
		{
			if (way->antray[i] != 0)
				s->ant_reach++;
			way->antray[i] = way->antray[i - 1];
		}
		else if(i == 0 && s->ant_start > 0 && (way->shortest == 1 || s->ant_start >= way->len - s->shortest_len))
		{
			way->antray[i] = s->ant_nbr - s->ant_start + 1;
			s->ant_start--;
		}
		else if(i > 0 && i < way->len - 1)
			way->antray[i] = way->antray[i - 1];
		else if(i == 0 && s->ant_start == 0)
			way->antray[i] = 0;
		i--;
	}
}

void prepare_ways(t_storage *s)
{
	t_ways *tmp;
	int i;
	int flag;

	flag = -1;
	tmp = s->ways_all;
	while (tmp != NULL)
	{
		i = 0;
		tmp->len = link_count(tmp->way);
		if (flag == -1)
		{
			tmp->shortest = 1;
			s->shortest_len = tmp->len;
			flag = 0;
		}
		else
			tmp->shortest = 0;
		tmp->antray = (int*)malloc(sizeof(tmp->antray) * tmp->len);
		while (i < tmp->len)
		{
			tmp->antray[i] = 0;
			i++;
		}
		tmp = tmp->next;
	}
}

void printer(t_storage *s)
{
	t_ways *tmp;

	prepare_ways(s);
	s->ant_start = s->ant_nbr;
	while (s->ant_reach < s->ant_nbr)
	{
		tmp = s->ways_all;
		while (tmp != NULL && tmp->len > 0)
		{
			ant_move(s, tmp);
			ant_print(tmp);
			tmp = tmp->next;
		}
		ft_putstr("\n");
	}
}
