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

typedef struct		s_link
{
	char			*name;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	char			*name;
	int 			start;
	int 			end;
	int 			x;
	int 			y;
	int 			visited;
	struct s_room	*next;
	struct s_link	*links;
}					t_room;

typedef struct	s_storage
{
	int				argc;
	char			**argv;
	int				fd;
	int 			step_1;
	int 			step_2;
	int 			step_3;
	int 			nr_start;
	int 			nr_end;
	int 			is_start;
	int 			is_end;
	int 			ant_nbr;
	t_input			*raw_input_lst;
	t_room			*rooms_lst;
	t_link			*way;
}				t_storage;

void		reader(t_storage *s);
void		add_input_lst(t_storage *s, char *line);
void		print_input_list(t_storage *s);
void		get_room(t_storage *s, char *line);
int			arrlen(char **array);
int			isnumeric(char *str);
void		add_room_lst(t_storage *s, char *name, int x, int y);
void		print_room_list(t_storage *s);
void		free_array(char **array);
void		get_links(t_storage *s, char *line);
t_room		*find_room(t_storage *s, char *name);
void		error(char *error);
void		way_finder(t_storage *s);

#endif
