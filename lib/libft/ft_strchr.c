/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:57:12 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/11/02 15:57:14 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*tmp;

	tmp = (char *)s;
	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == (char)c)
			return (tmp + i);
		i++;
	}
	if (c == '\0')
		return (tmp + i);
	return (NULL);
}
