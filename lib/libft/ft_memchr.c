/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:52:17 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/11/02 12:52:19 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*from;

	from = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)c == from[i])
			return (from + i);
		i++;
	}
	return (NULL);
}
