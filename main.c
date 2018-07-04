/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 15:40:58 by rkhilenk          #+#    #+#             */
/*   Updated: 2018/07/01 15:40:59 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void init(t_storage *s)
{
	s->fd = -1;
	s->step_1 = 0;
	s->step_2 = 0;
	s->step_3 = 0;
	s->nr_start = 0;
	s->nr_end = 0;
}

int main(int argc, char *argv[])
{
	t_storage	s;

	s.argc = argc;
	s.argv = argv;

	init(&s);
	reader(&s);
}
