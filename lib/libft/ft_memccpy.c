/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:13:53 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/10/31 16:13:56 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*from;
	unsigned char	*to;
	size_t			i;

	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			to[i] = from[i];
			if (from[i] == (unsigned char)c)
				return (to + i + 1);
			i++;
		}
	}
	return (NULL);
}
