/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstapp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:57:40 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/11/09 16:57:42 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstapp(t_list **alst, t_list *new)
{
	t_list	*list;

	list = *alst;
	while (list->next)
		list = list->next;
	list->next = new;
}
