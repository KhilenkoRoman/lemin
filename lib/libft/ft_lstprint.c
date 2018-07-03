/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:00:18 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/11/09 17:00:20 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst)
{
	if (!lst)
	{
		ft_putstr("input error");
		return ;
	}
	ft_putchar('[');
	while (lst)
	{
		ft_putstr(lst->content);
		if (lst->next)
			ft_putchar(',');
		lst = lst->next;
	}
	ft_putstr("]\n");
}
