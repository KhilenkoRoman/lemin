/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 15:42:00 by rkhilenk          #+#    #+#             */
/*   Updated: 2018/07/01 15:42:03 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

// dell
# include <stdio.h>
// dell

# include <fcntl.h>
# include <unistd.h>
# include "lib/libft/libft.h"

typedef struct		s_input
{
	char			*text;
	struct s_input	*next;
}					t_input;

typedef struct	s_storage
{
	int				argc;
	char			**argv;
	int				fd;
	int 			step_1;
	int 			step_2;
	int 			step_3;
	int 			ant_nbr;
	t_input         *raw_input_lst;
}				t_storage;

void reader(t_storage *s);
void add_input_lst(t_storage *s, char *line);
void print_input_list(t_storage *s);
void get_room(t_storage *s, char *line);
int arrlen(char **array);
int isnumeric(char *str);

#endif
