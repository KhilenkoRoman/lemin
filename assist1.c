/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 19:51:32 by rkhilenk          #+#    #+#             */
/*   Updated: 2018/07/03 19:51:33 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		arrlen(char **array)
{
	int i;

	i = 0;
	while (array[i] != 0)
		i++;
	return (i);
}

int		isnumeric(char *str)
{
	int i;

	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i - 1] < '0' || str[i - 1] > '9')
		{
			return (0);
		}
		i--;
	}
	return (1);
}

void	free_array(char **array)
{
	int i;

	i = 0;
	while (array[i] != 0)
		free(array[i++]);
	free(array);
}

void	room_count(t_storage *s)
{
	t_room	*tmp;

	s->room_nbr = 0;
	tmp = s->rooms_lst;
	while (tmp != NULL)
	{
		s->room_nbr++;
		tmp = tmp->next;
	}
}

int		link_count(t_link *list)
{
	t_link	*tmp;
	int		i;

	tmp = list;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
