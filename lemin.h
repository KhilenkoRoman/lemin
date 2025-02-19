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

typedef struct		s_ways
{
	int				*antray;
	int				len;
	int				shortest;
	t_link			*way;
	struct s_ways	*next;
}					t_ways;

typedef struct		s_room
{
	char			*name;
	int				start;
	int				end;
	int				x;
	int				y;
	int				visited;
	struct s_room	*next;
	struct s_link	*links;
}					t_room;

typedef struct		s_storage
{
	int				argc;
	char			**argv;
	int				fd;
	int				step_1;
	int				step_2;
	int				step_3;
	int				nr_start;
	int				nr_end;
	int				is_start;
	int				is_end;
	int				ant_nbr;
	int				ant_start;
	int				ant_reach;
	int				dt;
	int				room_nbr;
	int				gc;
	int				shortest_len;
	t_input			*raw_input_lst;
	t_room			*rooms_lst;
	t_ways			*ways_all;
}					t_storage;

void				reader(t_storage *s);
void				add_input_lst(t_storage *s, char *line);
void				print_input_list(t_storage *s);
int					add_room(t_storage *s, char *line);
int					arrlen(char **array);
int					isnumeric(char *str);
void				add_room_lst(t_storage *s, char *name, int x, int y);
void				free_array(char **array);
void				get_links(t_storage *s, char *line);
t_room				*find_room(t_storage *s, char *name);
void				error(char *error);
void				way_finder(t_storage *s);
void				add_link_lst(t_link **list, char *name);
void				print_link_list(t_link *list);
void				room_count(t_storage *s);
int					link_count(t_link *list);
void				pop_last_link(t_link **list);
void				printer(t_storage *s);
t_ways				*get_next_way(t_storage *s);
int					room_in_way(char *name, t_storage *s);
void				unvisit(t_storage *s);

#endif
