/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 16:15:46 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/11/02 16:15:48 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;
	int		buff;

	buff = -1;
	tmp = (char *)s;
	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == (char)c)
			buff = i;
		i++;
	}
	if (c == '\0')
		return (tmp + i);
	if (buff >= 0)
		return (tmp + buff);
	return (NULL);
}
