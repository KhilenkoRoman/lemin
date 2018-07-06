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

static int *ant_move(t_storage *s, int *antray, int way_len)
{
	int i;

	i = way_len - 1;
	while (i >= 0)
	{
		if (i == way_len - 1)
		{
			if (antray[i] != 0)
				s->ant_reach++;
			antray[i] = antray[i - 1];
		}
		else if(i == 0 && s->ant_start > 0)
		{
			antray[i] = s->ant_nbr - s->ant_start + 1;
			s->ant_start--;
		}
		else if(i > 0 && i < way_len - 1)
			antray[i] = antray[i - 1];
		else if(i == 0 && s->ant_start == 0)
			antray[i] = 0;
		i--;
	}
	return(antray);
}

static void ant_print(t_storage *s, int *antray, int way_len)
{
	int i;

	i = 0;
	while (i < way_len)
	{
		printf(" [%d] ", antray[i]);
		i++;
	}
	printf("\n");
}

void printer(t_storage *s)
{
	int way_len;
	int *antray;
	int i;

	i = -1;
	s->ant_start = s->ant_nbr;
	way_len = link_count(s->way);
	antray = (int*)malloc(sizeof(antray) * way_len);
	while (i < way_len - 1)
		antray[++i] = 0;
	while (s->ant_reach < s->ant_nbr)
	{
		// printf("ant_reach %d\n", s->ant_reach);
		// printf("ant_nbr %d\n", s->ant_nbr);
		antray = ant_move(s, antray, way_len);
		ant_print(s, antray, way_len);
	}

	// antray = ant_move(s, antray, way_len);

	// ant_print(s, antray, way_len);
	// ant_move(s, &antray, way_len);

	print_link_list(s->way);
}
