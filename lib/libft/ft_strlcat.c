/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:35:07 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/11/02 15:35:08 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		n;
	size_t	dst_lenth;
	size_t	src_lenth;

	dst_lenth = ft_strlen(dst);
	src_lenth = ft_strlen(src);
	n = size - dst_lenth;
	if (n <= 0)
		return (src_lenth + size);
	else
	{
		ft_strncat(dst, src, size - dst_lenth - 1);
		return (src_lenth + dst_lenth);
	}
}
