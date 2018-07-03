/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:28:57 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/11/09 16:28:58 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	if (lst)
	{
		tmp = f(lst);
		tmp->next = ft_lstmap(lst->next, f);
		return (tmp);
	}
	return (NULL);
}
