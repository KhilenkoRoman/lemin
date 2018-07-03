/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:51:33 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/10/31 16:51:35 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	check(unsigned char *dst, const unsigned char *src)
{
	if (src < dst)
		return (1);
	else
		return (0);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = dst;
	s = src;
	while (i < len)
	{
		if (check(d, s) == 1)
			d[len - i - 1] = s[len - i - 1];
		else
			d[i] = s[i];
		i++;
	}
	return ((void *)d);
}
